#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int temp;
int fan = 6;

//dht.readTemperature()

void setup() {
    temp = 0;
    pinMode(fan, OUTPUT);
    Serial.begin(9600);
    
}

void loop() {
    temp = dht.readTemperature();
    Serial.println(temp);

    if(temp>29){
      analogWrite(fan, 200);
    }
    else{
    analogWrite(fan, 75);  
    }
    
}
