int moen1 = 9;
int moen2 = 10;
int morun1p = 7;
int morun1n = 6;
int morun2p = 5;
int morun2n = 4;
int morun3p = 12;
int morun3n = 13;
int delayx = 1000; //this delay handle x axis motor
int delayy = 1000; //this delay hadle y axis motor
int delayz = 1000; //this delay handle z axis motor
char black = '1';
char white = '0';
int i;
int j;

void setup() 
{                
  Serial.begin(9600); 
  pinMode(moen1, INPUT);
  pinMode(moen2, INPUT);    
  pinMode(morun1p, OUTPUT);  
  pinMode(morun1n, OUTPUT);  
  pinMode(morun2p, OUTPUT);  
  pinMode(morun2n, OUTPUT);
  pinMode(morun3p, OUTPUT);
  pinMode(morun3n, OUTPUT); 
}

void loop() 
{
  for(i=0;i<297;i++)//loop for x axis
  {
    digitalWrite(morun1p, HIGH);
    digitalWrite(morun1n, LOW);
    delay(delayx);
    digitalWrite(morun1p, LOW);
    digitalWrite(morun1n, LOW);

    if(i%2==0)//for zigzag motion
    {
      for(j=0;j<210;j++)//loop for y axis
      {
        digitalWrite(morun2p, HIGH);
        digitalWrite(morun2n, LOW);
        delay(delayy);
        digitalWrite(morun2p, LOW);
        digitalWrite(morun2n, LOW);
        getData();
      }
    }
    else
    {
      for(j=209;j>=0;j--)//loop for y axis
      {
        digitalWrite(morun2p, LOW);
        digitalWrite(morun2n, HIGH);
        delay(delayy);
        digitalWrite(morun2p, LOW);
        digitalWrite(morun2n, LOW);
        getData();
      }
    }
  }
}

void putPen()//function that control pen movement
{
  digitalWrite(morun3p, HIGH);
  digitalWrite(morun3n, LOW);
  delay(delayz);
  digitalWrite(morun3p, LOW);
  digitalWrite(morun3n, LOW);
}

void withdrawPen()//function that control pen movement
{
  digitalWrite(morun3p, LOW);
  digitalWrite(morun3n, HIGH);
  delay(delayz);
  digitalWrite(morun3p, LOW);
  digitalWrite(morun3n, LOW);
}
void putapixel()//function that control pen movement
{
  digitalWrite(morun3p, HIGH);
  digitalWrite(morun3n, LOW);
  delay(delayz);
  digitalWrite(morun3p, LOW);
  digitalWrite(morun3n, HIGH);

}

void getData()//function that get data from C#.NET code
{
  if(Serial.available() > 0)
  {
    char dataInput = (char) Serial.read();
    if(dataInput == black)
    {
      //putapixel();
      putPen();
      Serial.write("1");
    }
    else
    {
      withdrawPen();
      Serial.write("1");
    }
  }
}

