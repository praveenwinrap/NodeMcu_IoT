#include <dht.h>
dht DHT;
void setup() 
{
 Serial.begin(9600);
}

void loop() 
{

  DHT.read11(5);
  Serial.print("Temperature=");
  Serial.print(DHT.temperature);
  Serial.print("   ");
  Serial.print("Humidity=");
  Serial.println(DHT.humidity);
  delay(2000);

  
}
