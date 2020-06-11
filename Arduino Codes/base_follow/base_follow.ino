#include <Servo.h>



//Motor A
const int motorPin1  = 2;  // Pin 14 of L293
const int motorPin2  = 3;  // Pin 10 of L293
//Motor B
const int motorPin3  = 4; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293
int enA = 9 ;
int enB = 10 ;
int a = 1;
void setup(){

    Serial.begin(9600);
    
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
      pinMode(enA, OUTPUT);
        pinMode(enB, OUTPUT);
    
}


void loop()


{
  analogWrite(enA, 150);
analogWrite(enB, 150);
  if (Serial.available())
{
  int state = Serial.read();
  if (state == 'R' )
  {
    digitalWrite(motorPin1, 1);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 1);
    digitalWrite(motorPin4, 0);

  
    
  }

  if (state == 'L')
  {
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 1);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 1);
   

  }

  if (state == 'S')
  {
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 0);
    
  }
  
}
// left - 0101
// right - 1010
/*
if (a==1)
{   
    digitalWrite(motorPin1, 1);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 1);
    digitalWrite(motorPin4, 0);
    delay(1000);
    a = 2;
}

*/


}
