void setup() {
 pinMode(16,OUTPUT);
 pinMode(2,OUTPUT);
 Serial.begin(9600);
}

void loop() 
{
  char c;
  if(Serial.available())
  {
  c=Serial.read();  
  }

  if(c=='a')
  {
    digitalWrite(16,0);
    digitalWrite(2,0);
  }
  else if(c=='b')
  {
    digitalWrite(16,1);
    digitalWrite(2,1);
  }
  

}
