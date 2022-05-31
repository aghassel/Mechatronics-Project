int E1 = 5; // Left wheel PWM pin (must be a PWM pin)
int M1 = 4; // Left wheel direction digital pin
int E2 = 6; // Right wheel PWM pin (must be a PWM pin)
int M2 = 7; // Right wheel direction digital pin

void setup()
{
    pinMode(M1, OUTPUT); // Configure pin M1 for output
    pinMode(M2, OUTPUT); // Configure pin M2 for output
}

void loop()
{
    int u; // A variable for the motor PWM command [0-255]

    // Play with this code to write open loop commands to the wheel motors

    //FWD motion
    for (u = 0; u <= 255; u += 5)// wheels spin slow
    {
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, u);     // PWM speed command (left wheels)
        analogWrite(E2, u);     // PWM speed command (right wheels)

        // Brief delay (perhaps not necessary)

        delay(100);
    }

    //Clkws Dir
    for (u = 0; u <= 250; u += 5)// wheels spin slow
    {
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, LOW); // Drive forward (right wheels)
        analogWrite(E1, u);     // PWM speed command (left wheels)
        analogWrite(E2, u);     // PWM speed command (right wheels)

        // Brief delay (perhaps not necessary)

        delay(100);
    }

    //Bckwd dir
    for (u = 0; u <= 255; u += 5)// wheels spin slow
    {
        // Tell the motor driver board what to do
        digitalWrite(M1, HIGH);  // Drive forward (left wheels)
        digitalWrite(M2, LOW); // Drive forward (right wheels)
        analogWrite(E1, u);     // PWM speed command (left wheels)
        analogWrite(E2, u);     // PWM speed command (right wheels)

        // Brief delay (perhaps not necessary)

        delay(100);
    }

    //CClkws dir
    for (u = 0; u <= 230 ;u += 5)// wheels spin slow
    {
        // Tell the motor driver board what to do
        digitalWrite(M1, HIGH);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, u);     // PWM speed command (left wheels)
        analogWrite(E2, u);     // PWM speed command (right wheels)

        // Brief delay (perhaps not necessary)

        delay(100);
    }
  
    //Clockwise circle with forward drive
    
    for (u = 0; u <= 255; u += 5)// wheels spin slow
    {
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, 255);     // PWM speed command (left wheels)
        analogWrite(E2, 100);

        // Brief delay (perhaps not necessary)

        delay(100);
    }

     //Clockwise circle with forward drive
    
    for (u = 0; u <= 255; u += 5)// wheels spin slow
    {
        // Tell the motor driver board what to do
        digitalWrite(M1, LOW);  // Drive forward (left wheels)
        digitalWrite(M2, HIGH); // Drive forward (right wheels)
        analogWrite(E1, 100);     // PWM speed command (left wheels)
        analogWrite(E2, 255);   

        // Brief delay (perhaps not necessary)

        delay(100);
    }
    
     
}
