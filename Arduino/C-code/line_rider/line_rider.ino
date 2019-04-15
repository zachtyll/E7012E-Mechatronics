#include <Servo.h>

Servo SteeringServo;     // Servo object Servo
Servo MotorServo;

int ServoValue;           // Analog input value Servo
int ServoPin = 9;         // Control pin for servo motor

int ServoMotorValue;
int ServoMotorPin = 8;

int minPulse = 1000;    // Minimum servo position
int maxPulse = 2000;    // Maximum servo position

int minPulseMotor = 0;
int maxPulseMotor = 1000;

int pos = 0;
int analogread = A0;
int servoMax = 1800;
int servoMin = 1300;
int servoSpeed = 5;


void setup() {

  Serial.begin(9600);   // Setup a serial connection for debugging.


  pinMode(ServoPin, OUTPUT);                      // initialize the Servo signal pin as an OUTPUT
  SteeringServo.attach(ServoPin,minPulse,maxPulse);       //(pin, min pulse width, max pulse width in microseconds)
  SteeringServo.writeMicroseconds(1550);                  // set servo at 90 degrees from 0-180

  MotorServo.attach(ServoMotorPin, minPulseMotor, maxPulseMotor);
  MotorServo.writeMicroseconds(500);
  Serial.println("Setup completed!");
  delay(1000);
}

void loop() {
  pinMode(A0,INPUT);
  
  SetSteering(-0.5);
  SetSteering(0.0);
  SetSteering(1.0);
  SetSteering(0.0);
  
  MotorServo.writeMicroseconds(500);
  delay(1000);
  Serial.println(analogRead(A0));
  
//  SetSteering(1.0);
//    Servo.writeMicroseconds(1550 + 250);                  // set servo at 90 degrees from 0-180
//    delay(1000);
//    Servo.writeMicroseconds(1550);                  // set servo at 90 degrees from 0-180
//    delay(1000);
//    Servo.writeMicroseconds(1550 - 250);                  // set servo at 90 degrees from 0-180
//    delay(1000);
//    Servo.writeMicroseconds(1550);                  // set servo at 90 degrees from 0-180
//    delay(1000);
}

float SetSteering(float angle) {
   SteeringServo.writeMicroseconds(1550 + 250 * angle);
   delay(1000);
}

float SetSpeed(float angle) {
  
}
