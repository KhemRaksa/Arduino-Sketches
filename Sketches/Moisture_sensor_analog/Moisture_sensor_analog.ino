//Analog - numeric Values of dryness or wetness
int moisture_sensor = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(moisture_sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moisture_reading = analogRead(moisture_sensor);

  //Value 1023 is maximum , maximum resistance , not much wetness
  //If water is added, the value will be lower, meaning resistance is dropping, since water allows eletricity to be conducted.
  //Deeper the probe, the more the value will drop

  
  Serial.print("Soil Moisture Level: ");
  Serial.println(moisture_reading);


  delay(200);
}
