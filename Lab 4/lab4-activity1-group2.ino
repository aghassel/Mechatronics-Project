/**
 * @file servomotor.ino
 * @author Joshua Marshall (joshua.marshall@queensu.ca)
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
Servo hs422servo;

// Variable to store the servo position [degrees]
int angle = 0;

void setup()
{
    // Attach the servo on pin 12 to the Servo object
    hs422servo.attach(12);
}

void loop()
{
    // For angle 0 to 180 [degrees]
    for (angle = 0; angle <= 180; angle += 1)
    {
        // Tell servo to go to position "angle"
        hs422servo.write(angle);

        // Wait a specified time [ms]
        delay(100);
    }
    // For angle 180 to 0 [degrees]
    for (angle = 180; angle >= 0; angle -= 1)
    {
        // Tell servo to go to position "angle"
        hs422servo.write(angle);

        // Wait a specified time [ms]
        delay(100);
    }
}
