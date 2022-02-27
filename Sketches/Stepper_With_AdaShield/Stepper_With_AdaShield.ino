#include <AFMotor.h>


//Port 1 , using M1 and M2.
//Port 2, using M3 and M4
AF_Stepper motor(2038, 2);


void setup() {


  motor.setSpeed(15);  // 15 rpm   

  delay(1000);
}

void loop() {
  
  motor.step(100, FORWARD, DOUBLE); //CW
 
}
