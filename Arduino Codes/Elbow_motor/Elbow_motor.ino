//L293D
//Motor A
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293


int tsh = 20 ;

//This will run only one time.
void setup(){


     Serial.begin(9600);


 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    //This code  will turn Motor A clockwise for 2 sec.

   // delay(5000); 
    //This code will turn Motor A counter-clockwise for 2 sec.

   // delay(5000);
    
        //And this code will stop motors

  
}


void loop(){

int pot = analogRead(A0);
// 395 minimum 
// 1000 maximum

int current_angle ;
int new_angle ;
new_angle = 500;
current_angle = pot ; 
Serial.println(pot);
if (new_angle >= current_angle  )
{
    
    
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 1);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 1);

     delay(10);

 
}

if (new_angle <= current_angle)
{
  
    digitalWrite(motorPin1, 1);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 1);
    digitalWrite(motorPin4, 0);
  
  delay(10);

  
}

if (new_angle + 50 > current_angle && new_angle - 50 < current_angle)
{
     digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 0);

    delay(10);
}
}

/*


  
if (Serial.available())
{
  int state = Serial.parseInt();
  if (state == 1)
  {
    digitalWrite(motorPin1, 1);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 1);
    digitalWrite(motorPin4, 0);
  }

  if (state == 2)
  {
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 1);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 1);
  }

  if (state == 0)
  {
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 0);
  }
  
}
   


}
*/
