void setup()
{
Serial.begin(9600);

Serial.println("AT");
delay(1000);
Serial.println("AT+CWMODE=3");
delay(1500);
Serial.println("AT+CWJAP=\"SSID\",\"PASSWORD\"");
delay(7000);

}

void loop() {

  Serial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  delay(2000);
  Serial.println("AT+CIPSEND=49");
  delay(100);
  Serial.println("GET /update?api_key=YOUR_TOKEN&field1=8");
  delay(100);
  Serial.println("AT+CIPCLOSE");
  delay(15000);
  // put your main code here, to run repeatedly:

}
