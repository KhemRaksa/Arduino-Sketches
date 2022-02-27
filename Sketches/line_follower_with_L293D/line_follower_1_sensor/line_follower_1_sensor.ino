//Line follower robot using 1 IR-sensor and L298N
//

//Will need to use PWM -capable pins for ENA , ENB if we want to analogWrite it
//int IN1 = 1;
//int IN2 = 2;
//int IN3 = 3;
//int IN4 = 4;
//int ENA = 5;
//int ENB = 6;

//int IR_sensor = 7;

void setup() {
  // put your setup code here, to run once:

//  pinMode(IN1, OUTPUT);
//  pinMode(IN2, OUTPUT);
//  ...

}

void loop() {
  // put your main code here, to run repeatedly:

  int reading = digitalRead(IR_sensor);
  //As soon as sensor detects black, we make the car go one way
  //Could be left or right 
  //Then as soon as it stops detecting black, we make the car go the other way
  //Car will wiggle quickly to left and right like a snake
  if (reading == 0)
  {
    go_left();
  }
  else {
    go_right();
  }
}

void go_left()
{ 
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4,0);
  //Set speed of left motors. Suppose it's enA
  analogWrite(ENA, 200);
  analogWrite(ENB, 0);
}


void go_right()
{
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, )0;
  digitalWrite(IN4,0);
  //Set speed of right motors
  analogWrite(ENA, 0);
  analogWrite(ENB, 200);
  
}
