#include<ESP8266WiFi.h>
#include <dht.h>
dht DHT;
WiFiClient client;
String d1,d2,temp,humi,request;
void setup()
{
Serial.begin(9600);

WiFi.begin("SSID","PASSWORD");
delay(7000);
Serial.println("connected to wifi");

}
void loop()
{
 DHT.read11(5);
 temp=(String)DHT.temperature;
 humi=(String)DHT.humidity;
  Serial.print("Temperature=");
  Serial.print(temp);
  Serial.print("   ");
  Serial.print("Humidity=");
  Serial.println(humi);

d1 ="GET /update?api_key=YOUR_TOKEN&field1=";
d2="&field2=";

request=d1+temp+d2+humi;
Serial.println(request);
if(client.connect("api.thingspeak.com",80))
{
Serial.println("Connected to Server");
client.println(request);
client.stop();
delay(10000);

}

}
