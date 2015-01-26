// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo2, myservo3, myservo4, myservo5, myservo6, myservo7;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 40;    // variable to store the servo position 
 
void setup() 
{ 
  myservo2.attach(2);  // attaches the servo on pin 9 to the servo object 
   myservo3.attach(3);  // attaches the servo on pin 9 to the servo object 
   myservo4.attach(4);  // attaches the servo on pin 9 to the servo object 
 myservo5.attach(5);  // attaches the servo on pin 9 to the servo object 
   myservo6.attach(6);  // attaches the servo on pin 9 to the servo object 
   myservo7.attach(7);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
myservo2.write(90);
delay(50);    // tell servo to go to position in variable 'pos' 
myservo3.write(90);              // tell servo to go to position in variable 'pos' 
delay(50);    
myservo4.write(90);              // tell servo to go to position in variable 'pos' 
delay(50);
myservo5.write(90);
delay(50);    // tell servo to go to position in variable 'pos' 
myservo6.write(90);              // tell servo to go to position in variable 'pos' 
delay(50);    
myservo7.write(90);              // tell servo to go to position in variable 'pos' 
delay(50);

while(1);
} 
