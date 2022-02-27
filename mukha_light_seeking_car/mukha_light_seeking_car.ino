int Left_Sensor = A0;
float Left_Sensor_val;
int Right_Sensor = A3;
float Right_Sensor_val;

void setup() {
  pinMode(Left_Sensor, INPUT); 
  pinMode(Right_Sensor, INPUT);
  //left motors
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  
  //right motors
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  Follow_Light();

}

void Follow_Light(){
  Left_Sensor_val = analogRead(Left_Sensor)/10;
  Right_Sensor_val = analogRead(Right_Sensor)/10;

  Serial.print("Left_photosensitive:");
  Serial.println(Left_Sensor_val);
  Serial.print("Right_photosensitive:");
  Serial.println(Right_Sensor_val);
  Serial.println("");
  
  if (Left_Sensor_val >30 && Right_Sensor_val >30){
    stay_still();
  }
  if(Left_Sensor_val<Right_Sensor_val){
    left();
  }
  if(Left_Sensor_val>Right_Sensor_val){
    right();  
  }
  if(Left_Sensor_val==Right_Sensor_val){
    forward();  
  }
  
}

void stay_still(){
  digitalWrite(2,0);
  analogWrite(5,0);
  
  digitalWrite(4,0);
  analogWrite(6,0);
}
void left(){
  
  digitalWrite(2,LOW);
  analogWrite(5,200);
  
  digitalWrite(4,LOW);
  analogWrite(6,200);
}
void right(){
  
  digitalWrite(2,HIGH);
  analogWrite(5,200);
  
  digitalWrite(4,HIGH);
  analogWrite(6,200);
}
void forward(){
  digitalWrite(2,HIGH);
  analogWrite(5,200);
  
  digitalWrite(4,LOW);
  analogWrite(6,200);
}
