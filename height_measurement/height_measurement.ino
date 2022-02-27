

#include <LiquidCrystal_I2C.h>

// LcdBarGraphX - Version: Latest 
// #include <LcdBarGraph.h>



#define max_distance 193

//For Ultrasonic sensor

int trigPin = 6;
int echoPin =5;

////////////////////

LiquidCrystal_I2C my_lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line displayLcdBarGraph lbg(0x27, 16, 0, 1);

// LcdBarGraph lbg(my_lcd, 16, 0, 1);

//////////////////////

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  my_lcd.init();
  my_lcd.clear();         
  my_lcd.backlight();      // Make sure backlight is on
  
}

void loop() {
  
  double distance = distance_func();
  
  my_lcd.setCursor(0,0);
  my_lcd.print("HEIGHT: ");
  my_lcd.print(distance);
  my_lcd.print("cm  ");

  
  my_lcd.setCursor(0,1);
  my_lcd.print("^******><******^");
  // my_lcd.setCursor(0,1);
  // lbg.drawValue(distance, max_distance);
   delay(1000);
  
}

double distance_func(){
  
 //Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //Sending the signal
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Recieving the bounced signal, and calculating duration (microseconds)
  
  double duration  = pulseIn(echoPin, HIGH);
  return max_distance-(duration*0.034)/2;
  
}
