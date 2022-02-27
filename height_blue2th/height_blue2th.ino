#include <SoftwareSerial.h>
int  rxPin = 10;
int txPin = 11;
byte data = 0x01; //Hex value for ''1''
SoftwareSerial nodeCommunication = SoftwareSerial(rxPin, txPin);

int echoPin = 2; // attach pin D2 Arduino to pin Echo of HC-SR04
int trigPin = 3; //attach pin D3 Arduino to pin Trig of HC-SR04
double distance;

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
pinMode(rxPin, INPUT);
pinMode(txPin, OUTPUT);
nodeCommunication.begin(9600); 

}
void loop() {

  distance = get_distance();
  nodeCommunication.write(distance); //Sends byte data to slave
  delay(1000);

}

double get_distance(){
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance;
}
