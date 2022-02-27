//Simple Joystick 
int SW = 10;
int VRx = A4;
int VRy = A5;

int redLED = 6;
int greenLED = 4;
int blueLED = 5;


int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(VRx,INPUT);
 pinMode(VRy,INPUT);
 pinMode(SW,INPUT_PULLUP);

 pinMode(redLED , OUTPUT);
 pinMode(blueLED, OUTPUT);
 pinMode(greenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);

  mapX = map(xPosition,0,1023,0,255);
  mapY = map(yPosition,0,1023,0,255);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  analogWrite(redLED , mapX);
  analogWrite(blueLED, mapY);
  digitalWrite(greenLED, SW_state);



  delay(10);

}
