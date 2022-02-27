#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);   

int temp;
int fan_pin = 6;

//Just constrain
void fan_motor(int fan_pin, int pwm) {
  if(pwm<=0){
    analogWrite(fan_pin,0);
  } 
  else if (pwm > 255){
    analogWrite(fan_pin,255);
  }
  else{
    analogWrite(fan_pin,pwm);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  temp = 0;
  dht.begin();
  pinMode(fan_pin, OUTPUT);
  digitalWrite(fan_pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = dht.readTemperature();
  Serial.println(temp);
  if(temp > 30){
    fan_motor(fan_pin,60);
  }
  else{
    fan_motor(fan_pin,0);
  }
}
