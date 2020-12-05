#include<ESP8266WiFi.h>
#include <dht.h>
dht DHT;
WiFiClient client;
String d1,d2,request;
void setup()
{
Serial.begin(9600);

WiFi.begin("endurance","Winrap321!");
delay(7000);
Serial.println("connected to");
Serial.println(WiFi.localIP());
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

d1 ="GET /update?api_key=ITZTYZIAKC6GZ1T4&field1=";
d2="&field2="

request=d1+temp+d2+humi;


if(client.connect("api.thingspeak.com",80))
{
Serial.println("Connected to Server");
client.println(request);
client.stop();
delay(15000);

}

}


