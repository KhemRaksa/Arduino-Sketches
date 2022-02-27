// Line follower robot with L293D code

//Library for DC motor
#include <AFMotor.h>

//defining the motors
AF_DCMotor motor1(1);
//.....


void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(150);
  //......


  //set the speed 0-255
}

void loop() {
  // put your main code here, to run repeatedly:
  // Testing the code 

 
}

void go_forward(){
     // Need to modify according to actual connection
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor1.run(FORWARD);
}

void go_left() {

}

void go_right() {
  
}

void go_backwards {

}
}
