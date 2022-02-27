//Simple Joystick 
int SW = 10;
int VRx = A4;
int VRy = A5;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);

  mapX = map(xPosition,0,1023,-512,512);
  mapY = map(yPosition,0,1023,-512,512);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);

}
