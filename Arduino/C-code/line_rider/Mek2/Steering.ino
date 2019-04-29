#include <Servo.h>

int minPulse = 1000;    // Minimum servo position
int maxPulse = 2000;    // Maximum servo position

float calibratedMid = 1550.0;   //Calibrated mid value
const float steerRange = 250.0; //Steering range
float steerAmplitude = 0.0;     // define steeringscaling value
float oldAngle = 0.0;

void ServoSetup(){
  pinMode(ServoSteeringPin, OUTPUT);                              //Initialize the Servosignalpin as an OUTPUT
  SteeringServo.attach(ServoSteeringPin,minPulse,maxPulse);       //(pin, min pulse width, max pulse width in microseconds)
  SteeringServo.writeMicroseconds(1550);
  //Serial.println("Servo setup completed!");
}  
void SetSteering(float angle){
  steerAmplitude = calibratedMid + steerRange * angle;    //Steering value multiplied to scale with servo
  SteeringServo.writeMicroseconds(steerAmplitude);        //Send steering in microsecounds(pulse) to output pin
  delay(15 + 1000 * oldAngle);
  oldAngle = angle;
}
