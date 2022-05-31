/**
 * @brief Arduino program to command the Hitec HS422 servomotor.
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 * Based on the example code by BARRAGAN <http://barraganstudio.com>, modified
 * 2013-11-08 by Scott Fitzgerald http://www.arduino.cc/en/Tutorial/Sweep.
 * Uses the Servo library https://www.arduino.cc/reference/en/libraries/servo/.
 *
 */

// Use this library to command servomotors
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
    // Attach the servo on pin 12 to the Servo object
    hs1.attach(12);
    hs2.attach(2);
    hs3.attach(13);
    hs2.write(side);
    angle = 90;
    hs1.write(angle);
    
}

void loop()
{
  
    hs3.write(0);
    delay(5000);
    hs3.write(180);
    delay(5000);
    hs1.write(180);
    delay(5000);
    hs1.write(90);
    delay(5000);
    

}
