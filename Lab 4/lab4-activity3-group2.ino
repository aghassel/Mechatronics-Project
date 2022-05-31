
const byte FPIN = 5;

int f_val;
double dist = 0;
int travelDist = 0; //Used to see how far back rover must go

int E1 = 5; // Left wheel PWM pin (must be a PWM pin)
int M1 = 4; // Left wheel direction digital pin
int E2 = 6; // Right wheel PWM pin (must be a PWM pin)
int M2 = 7; // Right wheel direction digital pin

#include <Servo.h>

// Create a servo object to control a servo
Servo hs1;
Servo hs2;
Servo hs3;
// Variable to store the servo position [degrees]
int angle = 90;
int side = 90;
int grip = 0;

void setup()
{
    pinMode(M1, OUTPUT); // Configure pin M1 for output
    pinMode(M2, OUTPUT); // Configure pin M2 for output
    Serial.begin(9600);

    hs1.attach(12);
    hs2.attach(2);
    hs3.attach(13);
    hs2.write(side);
    angle = 90;
    hs1.write(angle);
}

void loop()
{
  
    f_val = analogRead(FPIN);
    dist = 129*exp(-0.00516*f_val);
    int u; // A variable for the motor PWM command [0-255]

    //make sure claw is open
    hs3.write(0);
    delay(1100);

   
    //Foward movement, break if close to the object or wall
    while (true)
      {
        travelDist++;
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, 230);     // PWM speed command (left wheels)
        analogWrite(E2, 230);     // PWM speed command (right wheels)

        //Calc distance to object and break if close.
        f_val = analogRead(FPIN);
        dist = 129*exp(-0.00516*f_val); 
        if (dist < 20) break;
      }      

      //Use to stop rovermovement
      for (u = 0; u <= 250; u += 10)// wheels spin slow
      {
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, 0);     // PWM speed command (left wheels)
        analogWrite(E2, 0);     // PWM speed command (right wheels) 
      }
      
      delay(1000);

      //grab object with claw
      hs3.write(0);
      delay(1500);
      hs3.write(180);
      delay(1500);
      hs1.write(180);
      delay(1200);
      
      //Revese backwards same distance 
      while (travelDist>0)
      {
        // Tell the motor driver board what to do
        digitalWrite(M1, HIGH);  // Drive back (left wheels)
        digitalWrite(M2, LOW); // Drive back (right wheels)
        analogWrite(E1, 230);     // PWM speed command (left wheels)
        analogWrite(E2, 230);     // PWM speed command (right wheels) 

        travelDist--;
      }
      
      delay(1400);

      //Code to stop rover
      for (u = 0; u <= 250; u += 10)// wheels spin slow
      {
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, 0);     // PWM speed command (left wheels)
        analogWrite(E2, 0);     // PWM speed command (right wheels) 
      }
      delay(1000);

      //Put the flag down code
      hs1.write(90);
      delay(2000);
      hs3.write(0);
      delay(2000);


}
