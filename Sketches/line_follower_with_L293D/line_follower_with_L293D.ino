// Line follower robot with L293D code

//Library for DC motor
#include <AFMotor.h>

//defining the motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//sensor Pins
int LeftSensor = A0;
int left_sensor_value;
int RightSensor = A1;
int right_sensor_value;

//threshold level, selected on the basis of the IR readings
// through the serial monitor

int threshold = 500;

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);

  //set the speed 0-255
}

void loop() {
  // put your main code here, to run repeatedly:
   left_sensor_value = analogRead(LeftSensor);
   right_sensor_value = analogRead(RightSensor);

  //Will need to change according to actual configuration of motors with L293D
   if (left_sensor_value > threshold && right_sensor_value < threshold)
   {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor1.run(FORWARD);
   }
    if (left_sensor_value < threshold && right_sensor_value < threshold)
   {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor1.run(FORWARD);
   }
    if (left_sensor_value < threshold && right_sensor_value > threshold)
   {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor1.run(FORWARD);
   }
 

}
