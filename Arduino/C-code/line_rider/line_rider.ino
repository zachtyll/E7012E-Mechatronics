#include <Servo.h>

Servo SteeringServo;     // Servo object Servo
Servo MotorServo;

// Steering
int SteeringPin = 9;             // Control pin for steering servo
int minPulseSteering = 1300;  // Smallest pulse and
int maxPulseSteering = 1800;  // largest pulse for steering servo.


// Speed
int MotorPin = 8;    // Control pin for motor servo
int minPulseMotor = 0;    // Smallest pulse and
int maxPulseMotor = 1000; // largest pulse for motor servo

int steeringPos = A0;     // Unused. Might be used for steering actuator assertion in future.
float oldAngle = 0.0;

void setup() {

  Serial.begin(9600);   // Setup a serial connection for debugging.

  pinMode(SteeringPin, OUTPUT);              // initialize the steering control pin as an OUTPUT                
  SteeringServo.attach(
    SteeringPin,                             // Set the control pin for the steering servo
    minPulseSteering,                     // Set the min and
    maxPulseSteering);                    // max value for the servo.
  SteeringServo.writeMicroseconds(1550);  // Home the steering servo to 0.0 (1550).                

  // Setup Motor
  pinMode(MotorPin, OUTPUT);              // initialize the motor control pin as an OUTPUT 
  MotorServo.attach(                      
    MotorPin,                        // Set the control pin for the steering servo
    minPulseMotor,                        // Set the min and
    maxPulseMotor);                       // max value for the servo.
  MotorServo.writeMicroseconds(0);        // Turn the motor off.
  
  Serial.println("Setup completed!");
  delay(1000);
}

void loop() {
  pinMode(A0,INPUT);
  
  SetSteering(-0.5);
  SetSteering(0.0);
  SetSpeed(1.0);
  SetSteering(1.0);
  SetSteering(0.0);
  SetSpeed(0.5);
}
