int pot_red = A5;
int pot_white = A4;
int pot_blue = A3;
int pot_green = A2;

int red_led = 10;
int white_led = 11;
int green_led = 5;
int blue_led = 6;

void setup() 

{
  pinMode(red_led, OUTPUT);
  pinMode(white_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(white_led, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int pot_red_value = analogRead(pot_red);
  int pot_white_value = analogRead(pot_white);
  int pot_blue_value = analogRead(pot_blue);
  int pot_green_value = analogRead(pot_green);


  int red_value = map(pot_red_value,0,1023,0,255);
  int white_value = map(pot_white_value,0,1023,0,255);
  int blue_value = map(pot_blue_value,0,1023,0,255);
  int green_value = map(pot_green_value,0,1023,0,255);
  

  analogWrite(red_led,red_value);
  analogWrite(white_led,white_value);
  analogWrite(green_led,green_value);
  analogWrite(blue_led,blue_value);
 
  
  delay(100);
}
