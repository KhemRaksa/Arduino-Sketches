/*

*/
double distance;

int greenLED = 10;
int blueLED = 11;
int redLED = 12;
int buzzer = 13;

int trigPin = 5;
int echoPin = 6;

void setup() {
    
    Serial.begin(9600);
    
    pinMode(greenLED,OUTPUT);
    pinMode(blueLED,OUTPUT);
    pinMode(redLED,OUTPUT);
    pinMode(buzzer,OUTPUT);
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin,INPUT);
    
}

void loop() {
  
  distance = distance_func();
  Serial.println(distance);
  
  if(distance<=10)
  {
      digitalWrite(greenLED,HIGH);
      digitalWrite(blueLED,HIGH);
      digitalWrite(redLED,HIGH);
      tone(buzzer,400);
      delay(50);
      noTone(buzzer);
      delay(distance*10);
  }
  else if(distance<=20)
  {
      digitalWrite(greenLED,LOW);
      digitalWrite(blueLED,LOW);
      digitalWrite(redLED,HIGH);
      tone(buzzer,400);
      delay(50);
      noTone(buzzer);
      delay(distance*10);
  }
  else if(distance<=50)
  {
      digitalWrite(greenLED,LOW);
      digitalWrite(blueLED,HIGH);
      digitalWrite(redLED,LOW);
//      tone(buzzer,200);
      tone(buzzer,400);
      delay(50);
      noTone(buzzer);
      delay(distance*10);
  }
  else if(distance<=100)
  {
      digitalWrite(greenLED,HIGH);
      digitalWrite(blueLED,LOW);
      digitalWrite(redLED,LOW);
      tone(buzzer,400);
      delay(50);
      noTone(buzzer);
      delay(distance*10);
  }
  
  delay(10);
    
}

double distance_func()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  double duration = pulseIn(echoPin,HIGH);
  return duration*0.034/2;
}
