#include <Servo.h>

Servo servo;
Servo servo2;

int angle = 0;

void setup() {
  // put your setup code here, to run once:

  servo.attach(9);
  servo2.attach(10);
  servo.write(0);
}

void loop() {
  

for (angle = 0; angle <181; angle ++)
{
  servo.write(angle);
  servo2.write(angle);
  delay(10);
}

for (angle = 180; angle >0; angle--)
{
  servo.write(angle);
  servo2.write(angle);
  delay(10);
}

}
