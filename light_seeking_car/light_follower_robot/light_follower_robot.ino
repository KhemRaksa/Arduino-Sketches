volatile float left_sensor;
volatile float right_sensor;
volatile int lightseeking_degree;
volatile float f;
volatile int speed_v;

void setup() {
  // put your setup code here, to run once:
  //  Serial.begin(115200);
  left_sensor = 0;
  right_sensor = 0;
  lightseeking_degree = 0;
  f = 0;
  //speed ~ max is 255
  speed_v = 200;
  //The sensors
  pinMode(A0, INPUT);
  pinMode(A3, INPUT);
  //The motors
  //left motors
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  //right motors
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  light_seeking();
}

void light_seeking(){
  left_sensor = analogRead(A0)/10; // divide by 10 to make smaller
  right_sensor = analogRead(A3)/10;

   if (left_sensor > 55 && right_sensor > 55) {
    stay_still();
   }
   //if right_sensors senses light 
   else if (left_sensor > right_sensor){
    lightseeking_degree = ((float)(right_sensor/left_sensor))*90; // result will be less than 90
   } 
   else if (left_sensor <= right_sensor) {
    lightseeking_degree = 180 - ((float)(left_sensor / right_sensor))*90; // result will be bigger than 90 less than 180
   }
   //turn right
   if (lightseeking_degree < 90 ) {
    f = ((float)(lightseeking_degree)) / 90; // just dividing it back by 90 to make it in range from 0 - 1 to use it as multiplier for speed
      digitalWrite(2,HIGH);
      analogWrite(5,speed_v);
      digitalWrite(4,LOW);
      analogWrite(6,(speed_v * f)); // we do this , so our car turns smoothly, when it is closer to light source, it turns slower, etc, more realistic
   }
   //turn left
   if (lightseeking_degree > 90) {
      f = ((float)(180 - lightseeking_degree)) / 90; // just dividing it back by 90 to make it in range from 0 - 1 to use it as multiplier for speed
      digitalWrite(2,HIGH);
      analogWrite(5,(speed_v * f));
      digitalWrite(4,LOW);
      analogWrite(6,speed_v);
   }
   //go straight ~ here you will see we do not use lightseeking_degree or f_multiplier because, we are just going straight
   if(lightseeking_degree == 90){
      f = ((float)(lightseeking_degree)) / 90;
      digitalWrite(2,HIGH);
      analogWrite(5,speed_v);
      digitalWrite(4,LOW);
      analogWrite(6,speed_v);
   }
  
}

void stay_still(){
    digitalWrite(2,0);
    analogWrite(5,0);
    digitalWrite(4,0);
    analogWrite(6,0);
}
