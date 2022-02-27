char input;

void setup() {
  Serial.begin (9600);
  delay(2000);

  Serial.println("Type something!");
}

void loop(){
  if (Serial.available()){
    input = Serial.read();
    Serial.print("You typed: ");
    Serial.println(input);
  }
}
