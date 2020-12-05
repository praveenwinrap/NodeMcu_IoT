#include <dht.h>


dht DHT;

#define DHT11_PIN 7
void setup()
{
Serial.begin(9600);

Serial.println("AT");
delay(1000);
Serial.println("AT+CWMODE=3");
delay(1500);
Serial.println("AT+CWJAP=\"Torvalds\",\"linux@training\"");
delay(7000);

}

void loop() {
 int chk = DHT.read11(DHT11_PIN);
 // Serial.print("Temperature=");
 // Serial.print(DHT.temperature);
//  Serial.print("   ");
//  Serial.print("Humidity=");
//  Serial.println(DHT.humidity);
//  delay(2000);
  Serial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  delay(2000);
  Serial.println("AT+CIPSEND=51");
  delay(100);
  Serial.print("GET /update?api_key=ER8YOHD135RU1J7O&field1=");
  Serial.println(DHT.temperature);
  delay(100);
  Serial.println("AT+CIPCLOSE");
  delay(15000);
  // put your main code here, to run repeatedly:

}

