int sound_value;
int sound_sensor = A0;
int redLED = 13;
int whiteLED = 12;
int blueLED = 11;
int greenLED = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(sound_sensor, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sound_value = analogRead(sound_sensor);
  Serial.println(sound_value);
  if (sound_value > 100){
    digitalWrite(whiteLED,1);
    digitalWrite(redLED,0);
    digitalWrite(blueLED,0);
    digitalWrite(greenLED,0);
  }
  else if(sound_value > 200){
    digitalWrite(whiteLED,1);
    digitalWrite(redLED,1);
    digitalWrite(blueLED,0);
    digitalWrite(greenLED,0);
  }
   else if(sound_value > 300){
    digitalWrite(whiteLED,1);
    digitalWrite(redLED,1);
    digitalWrite(blueLED,1);
    digitalWrite(greenLED,0);
  }
  else{
     digitalWrite(whiteLED,0);
    digitalWrite(redLED,0);
    digitalWrite(blueLED,0);
    digitalWrite(greenLED,0);
  }

}
