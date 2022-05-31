/**
 * @brief Arduino program to estimate motor speed from encoder.
 * @version 1.0
 * @date 2021-10-22
 *
 * @copyright Copyright (c) 2021
 *
 */

// Motor driver PWM pin
const byte E1 = 5;
const byte E2 = 6;

// Motor driver direction pin
const byte M1 = 4;
const byte M2 = 7;

// Motor PWM command variable [0-255]
byte u = 0;

// Left wheel encoder digital pins
const byte SIGNAL_A = 8;
const byte SIGNAL_B = 9;
const byte SIGNAL_C = 2;
const byte SIGNAL_D = 3;

// Encoder ticks per (motor) revolution (TPR)
const int TPR = 3000;

// Wheel radius [m]
const double RHO = 0.0625;

// Counter to keep track of encoder ticks [integer]
volatile long encoder_ticksL = 0;
volatile long encoder_ticksR = 0;

// Variable to store estimated angular rate of left wheel [rad/s]
double omega_L = 0.0;
double omega_R = 0.0;
//Variable to store velocity [rad*m/s]
double vel_L = 0.0;
double vel_R = 0.0;
// Sampling interval for measurements in milliseconds
const int T = 200;

// Counters for milliseconds during interval
long t_now = 0;
long t_last = 0;

// This function is called when SIGNAL_A goes HIGH
void decodeEncoderTicksL()
{
    if (digitalRead(SIGNAL_B) == LOW)
    {
        // SIGNAL_A leads SIGNAL_B, so count one way
        encoder_ticksL--;
    }
    else
    {
        // SIGNAL_B leads SIGNAL_A, so count the other way
        encoder_ticksL++;
    }
}
void decodeEncoderTicksR()
{
    if (digitalRead(SIGNAL_C) == HIGH)
    {
        // SIGNAL_D leads SIGNAL_C, so count one way
        encoder_ticksR--;
    }
    else
    {
        // SIGNAL_C leads SIGNAL_D, so count the other way
        encoder_ticksR++;
    }
}

void setup()
{
    // Open the serial port at 9600 bps
    Serial.begin(9600);

    // Set the pin modes for the motor driver
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
    // Set the pin modes for the encoders
    pinMode(SIGNAL_A, INPUT);
    pinMode(SIGNAL_B, INPUT);
    pinMode(SIGNAL_C, INPUT);
    pinMode(SIGNAL_D, INPUT);
    // Every time the pin goes high, this is a pulse
    attachInterrupt(digitalPinToInterrupt(SIGNAL_A), decodeEncoderTicksL, RISING);
    attachInterrupt(digitalPinToInterrupt(SIGNAL_C), decodeEncoderTicksR, RISING);
    // Print a message
    Serial.print("Program initialized.");
    Serial.print("\n");
}

void loop()
{
    // Get the elapsed time [ms]
    t_now = millis();

    if (t_now - t_last >= T)
    {
        // Estimate the rotational speed [rad/s]
        omega_L = (2.0 * PI * ((double)encoder_ticksL / (double)TPR) * 1000.0 / (double)(t_now - t_last));
        vel_L = 0.0625*omega_L;
        omega_R = -1*(2.0 * PI * ((double)encoder_ticksR / (double)TPR) * 1000.0 / (double)(t_now - t_last));
        vel_R = 0.0625*omega_R;
        // Print some stuff to the serial monitor
        Serial.print("Encoder ticks: ");
        Serial.print(encoder_ticksL);
        Serial.print("\t");
        Serial.print("Estimated left wheel speed: ");
        Serial.print(omega_L);
        Serial.print(" rad/s");
        Serial.print("\n");

        Serial.print("Linear speed of left wheel: ");
        Serial.print(vel_L);
        Serial.print(" rad*m/s");
        Serial.print("\n");


        Serial.print("Encoder ticks: ");
        Serial.print(encoder_ticksR);
        Serial.print("\t");
        Serial.print("Estimated right wheel speed: ");
        Serial.print(omega_R);
        Serial.print(" rad/s");
        Serial.print("\n");

        Serial.print("Linear speed of right wheel: ");
        Serial.print(vel_R);
        Serial.print(" rad*m/s");
        Serial.print("\n");
        // Record the current time [ms]
        t_last = t_now;

        // Reset the encoder ticks counter
        encoder_ticksL = 0;
        encoder_ticksR = 0;
    }
    

    // Set the wheel motor PWM command [0-255]
    u = 128;

    // Write to the output pins
    digitalWrite(M1, LOW); // Drive forward (left wheels)
    analogWrite(E1, u);    // Write left motors command
    digitalWrite(M2, HIGH); // Drive forward (right wheels)
    analogWrite(E2, u);    // Write right motors command
    
}
