// C++ code

//Blink

// This is our first program


int redLED = 3;
int blueLED =4;

//Runs once 
void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}


void loop()
{
  //Turn on LED
  digitalWrite(redLED, 1);
  digitalWrite(blueLED, 1);
  
  delay(500);
  
  //Turn off LED
  digitalWrite(redLED, 0);
  digitalWrite(blueLED, 0);
  
  delay(500);
  
}
