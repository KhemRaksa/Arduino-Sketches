int ldr = A5;
int reading;

int led = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(ldr);
  Serial.println(reading);
  if (reading <= 200)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }
}
