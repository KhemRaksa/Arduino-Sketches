// LcdBarGraphX - Version: 2.0.0
#include <LcdBarGraphX.h>


#include <LiquidCrystal_I2C.h>

#define max_distance 193

//For Ultrasonic sensor

int trigPin = 6;
int echoPin =5;

////////////////////

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line displayLcdBarGraph lbg(0x27, 16, 0, 1);

LcdBarGraphX lbg(&lcd, 16, 0, 1);

//////////////////////

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
}

void loop() {
  
  double distance = distance_func();
  
  lcd.setCursor(0,0);
  lcd.print("HEIGHT: ");
  lcd.print(distance);
  lcd.print("cm  ");

  
  lcd.setCursor(0,1);
  lcd.print("^******><******^");
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
