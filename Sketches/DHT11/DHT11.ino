#include <dht.h>
int dataPin = 8 ; // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object

void setup() 
{
  Serial.begin(9600);
//  pinMode(dataPin,INPUT);
}
void loop() 
{
  //Uncomment whatever type you're using!
  //int readData = DHT.read22(dataPin); // DHT22/AM2302
  int readData = DHT.read11(dataPin); // DHT11

  float t = DHT.temperature; // Gets the values of the temperature
  float h = DHT.humidity; // Gets the values of the humidity

  // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.println(t);
  
  Serial.print("Humidity = ");
  Serial.println(h);
 
  delay(2000); // Delays 2 seconds
}
