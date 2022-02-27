
int moisture_digital_pin = 4;
int sensor_state;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(moisture_digital_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Soil Moisture Level: ");
  sensor_state = digitalRead(moisture_digital_pin);
  if (sensor_state == 1)
  {
    Serial.println("Wet");
  }
  else
  {
    Serial.println("Dry");
  }

delay(200);
}
