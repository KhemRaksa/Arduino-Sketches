

//Variables are usually created at the top of the sketch
//Syntax:
//data_type varaible_name = value;

//Just declaring, the value will be zero 

//Scopes of variable : global vs local variable

/*In this section, we'll learn about storing data in the non-volatile memory known as EEPROM. 
 * This allows data to be retained when power is disconnected and accessed later.
 * 
 * Solid state, non-volative memory. 
 * Like a little hard drive built onto the chip. 
 * 
 * Arduino UNO has 1kilobyte of onboard EEPROM to use. 
 * 
 * Whale levelling. 
 * 
 */

#include <EEPROM.h>

//pin definitions
int ledPin = 13;
int buttonPin = 2;

//global variables
int lastButtonState = 1;
long unsigned int lastPress;
int debounceTime = 20;
int counter;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  //Initialize Serial port
  Serial.begin(9600);

  //Assign counter the value of address 0
  counter = EEPROM.read(0);

  //Write a 0 to address 0. This allows for consecutive resets to reset the counter
  //Press 2 resets two times will reset counter
  //Got it
  EEPROM.write(0,0);
  
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if((millis() - lastPress)> debounceTime)
  { 
    lastPress = millis();
    if(buttonState == 0 && lastButtonState ==1 )
    {
        counter++;
        //This eeprom down here is important too. it why counter doesn't reset if press just once
        EEPROM.write(0, counter); //Write counter to address 0
        digitalWrite(ledPin, HIGH); // momentary LED
        lastButtonState = 0; //
        //print results
        Serial.print("Counter: ");
        Serial.println(counter);
    }

    if(buttonState == 1 && lastButtonState == 0)
     {
        lastButtonState = 1;
        digitalWrite(ledPin, LOW);
     }
    }
  }
