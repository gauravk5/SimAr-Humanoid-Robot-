
#include <Servo.h>
Servo s ;
Servo grip ;
Servo wrist ;
//variables
short int valRead = 0;

const int m1 = 2 ;
const int m2 = 3 ;
const int m3 = 4 ;
const int m4 = 5 ;



 int a = 1;
int b = 1 ;

void setup() {


  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  s.attach(8);// 9 10
  grip.attach(9);
  wrist.attach(10);


}

/*

   digitalWrite(m1,0);
    digitalWrite(m2,1);
     digitalWrite(m3,0);
      digitalWrite(m4,1);

  ///

  }
      digitalWrite(m1,0);
    digitalWrite(m2,0);
     digitalWrite(m3,0);
      digitalWrite(m4,0);

  //proportionality between input and output value
  while (valRead >= valTarget && abs(valRead - valTarget) >  diff_error) {
    valRead = (((float)analogRead(potMT) - minPot) / (maxPot - minPot)) * maxValIn;
    //run motor
   digitalWrite(m1,1);
    digitalWrite(m2,0);
     digitalWrite(m3,1);
      digitalWrite(m4,0);
  }
      digitalWrite(m1,0);
    digitalWrite(m2,0);
     digitalWrite(m3,0);
      digitalWrite(m4,0);
  }

  //loop

*/
void loop() {
  s.write(96);
  delay (1000);
  s.write(180);
  delay(96);
  delay(500);


  if (a == 1)
  {
    digitalWrite(m1, 1);
    digitalWrite(m2, 0);
    digitalWrite(m3, 0);
    digitalWrite(m4, 0);
    delay(2000);
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
    digitalWrite(m3, 0);
    digitalWrite(m4, 0);
    delay(800);

    a = 2;
  }

   if (b == 1)
{
  digitalWrite(m3, 1);
  digitalWrite(m4, 0);
  delay(4000);

    digitalWrite(m3,0);
  digitalWrite(m4,0);
  
  b = 2;

  

}

grip.write(0);
delay(1000);
grip.write(180);
delay(1000);

wrist.write(0);
delay(1000);
wrist.write(50);
delay(1000);
  



}
