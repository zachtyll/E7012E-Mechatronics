#include <Servo.h>

Servo SteeringServo;     // Servo object Servo
Servo MotorServo;

// Steering
int ServoPin = 9;             // Control pin for steering servo
int minPulseSteering = 1300;  // Smallest pulse and
int maxPulseSteering = 1800;  // largest pulse for steering servo.


// Speed
int ServoMotorPin = 8;    // Control pin for motor servo
int minPulseMotor = 0;    // Smallest pulse and
int maxPulseMotor = 1000; // largest pulse for motor servo

int steeringPos = A0;     // Unused. Might be used for steering actuator assertion in future.
float oldAngle = 0.0;

void setup() {

  Serial.begin(9600);   // Setup a serial connection for debugging.

  // initialize the steering servo signal pin as an OUTPUT
  //(pin, min pulse width, max pulse width in microseconds)
  // set servo at 90 degrees from 0-180
  pinMode(ServoPin, OUTPUT);                      
  SteeringServo.attach(ServoPin,minPulseSteering,maxPulseSteering);       
  SteeringServo.writeMicroseconds(1550);                  

  MotorServo.attach(ServoMotorPin, minPulseMotor, maxPulseMotor);
  MotorServo.writeMicroseconds(500);
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
