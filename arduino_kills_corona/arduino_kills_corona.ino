
int relayPin = 3;
int trigPin = 9;
int echoPin = 8;
float distance;

float checkDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00; // convert it to centimeters
  delay(10);
  return distance;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  distance = checkDistance();
  Serial.println(distance);
  if(distance <= 10){
    //pump the water if hand is close to the sensor
    digitalWrite(relayPin, HIGH);
    delay(500);
    digitalWrite(relayPin, LOW);
  }
  else{
    digitalWrite(relayPin, LOW);
  }

}
