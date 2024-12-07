/* 
Designed and Developed by:
 "YOUNG INNOVATORS EDUCATIONAL SERVICES PVT. LTD."


NOTE:
 YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
 GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //

*/

#include <AFMotor.h>

//defining pins and variables
int LS = 9;     // Left sensor
int MS = 10;    // Middle Sensor
int RS = 11;   // Right sensor


//defining motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);


void setup()
 {
   pinMode(LS, INPUT);
   pinMode(MS, INPUT);
   pinMode(RS, INPUT);
   delay (500);
 }

void loop()
{   
     //Forward when Middle Sensor on Black Line
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 1) && (digitalRead(LS)== 0)) 
     {
        motor1.run(FORWARD);
        motor1.setSpeed(150);
        motor2.run(FORWARD);
        motor2.setSpeed(150);
     }
     
     //Sharp Left: When Left and Middle Sensor on Black Line
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1))   
     {
        motor1.run(BACKWARD);
        motor1.setSpeed(150);
        motor2.run(FORWARD);
        motor2.setSpeed(150);
     }
     
     //Sharp Right: When Right and Middle Sensor on Black Line
     if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 0))    
     {
        motor1.run(FORWARD);
        motor1.setSpeed(150);
        motor2.run(BACKWARD);
        motor2.setSpeed(150);
     }
     
    // Turn Left: When Left Sensor is on Black Line
    if((digitalRead(RS)== 0) && (digitalRead(MS)== 0) && (digitalRead(LS)== 1))        
    {
      motor1.run(RELEASE);
      motor1.setSpeed(0);
      motor2.run(FORWARD);
      motor2.setSpeed(150);
    }

    // Turn Right: When Right Sensor is on Black Line
    if((digitalRead(RS)== 1) && (digitalRead(MS)== 0) && (digitalRead(LS)== 0))
    {
      motor1.run(FORWARD);
      motor1.setSpeed(150);
      motor2.run(RELEASE);
      motor2.setSpeed(0); 
    }
     
    // STOP: ALL 3 SENSORS ARE ON BLACK  SURFACE
    if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1)) 
    {
      motor1.run(RELEASE);
      motor1.setSpeed(0);
      motor2.run(RELEASE);
      motor2.setSpeed(0);
    }

   // STOP: ALL 3 SENSORS ARE ON WHITE SURFACE
    if((digitalRead(RS)== 0) && (digitalRead(MS)== 0) && (digitalRead(LS)== 0))  
    {
      motor1.run(RELEASE);
      motor1.setSpeed(0);
      motor2.run(RELEASE);
      motor2.setSpeed(0);
    }     
}
