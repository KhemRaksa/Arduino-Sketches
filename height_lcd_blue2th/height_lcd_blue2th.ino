#include <SoftwareSerial.h>
#define rxPin 11
#define txPin 10
byte incoming;
SoftwareSerial nodeCommunication = SoftwareSerial(rxPin, txPin);

void setup()
{
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  nodeCommunication.begin(9600); 
}
 void loop()
{
  if(nodeCommunication.available > 0) //Only if data is available
  {
   byte incoming = nodeCommunication.read(); //read byte from master
    
  }
    else
    {
    
    }
}
