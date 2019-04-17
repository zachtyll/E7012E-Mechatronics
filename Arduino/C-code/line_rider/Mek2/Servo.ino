#include <Servo.h>


int ServoPin = 9;       // Control pin for servo motor
int minPulse = 1000;    // Minimum servo position
int maxPulse = 2000;    // Maximum servo position

float caliMid = 1550.0;     //Calibrated mid value
float steerR = 250.0;       //Steering range
float steerA = 0.0;         // define steeringscaling value

void servosetup(){
  pinMode(ServoPin, OUTPUT);                              //Initialize the Servosignalpin as an OUTPUT
  SteeringServo.attach(ServoPin,minPulse,maxPulse);       //(pin, min pulse width, max pulse width in microseconds)
  SteeringServo.writeMicroseconds(1550);
}  
void SetSteering(){
  steerA = caliMid + steerR * angle;              //Steering value multiplied to scale with servo
  SteeringServo.writeMicroseconds(steerA);        //Send steering in microsecounds(pulse) to output pin
  Serial.println(steerA);                        //display value used
  delay(15);
}
