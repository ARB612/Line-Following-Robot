#include <AFMotor.h>

//defining motors
AF_DCMotor motor1(4);
AF_DCMotor motor2(2);

void setup(){

}

void loop()
{   
  motor1.run(FORWARD);
  motor1.setSpeed(255);
  motor2.run(FORWARD);
  motor2.setSpeed(255);   
}