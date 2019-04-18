#include <PID_v1.h>                     
#include <Servo.h>                    //include the servo library

Servo SteeringServo;                  // Servo object Servo
Servo MotorServo;                     // Servo object Motorcontrol

float angle = 0.0;                    // Steering angle -1 is left 0 is straigth and 1 is right. X100 for % 
float mps = 0.0;                      // Engine speed where 0 is standing still and 1 is full throttle

const int hallIsrLeft = 5;            // Pin 5: Left Hall sensor.
const int hallIsrRight = 6;           // Pin 6: Right Hall sensor.
const int ServoMotorPin = 8;          // Pin 8: Motor control.
const int ServoPin = 9;               // Pin 9: Steering control.

void setup() { 
  Serial.begin(9600);                 // Sets the data rate in bits per second (baud) for serial data transmission.
  PinSetup();                         // Setup for pins.
  IsrSetup();                         // Setup for ISR.  
  MotorSetup();                       // Setup for motor.
  ServoSetup();                       // Setup for steering servo.
  
  Serial.println("Setup completed!");
  delay(1000);
}
void loop() {  
  SetSpeed(0.);      //Makes function for running the motortab        
  SetSteering(angle); //Makes function for running the servotab
}

void blink1() {
  Serial.println("blink 1!");
}

void blink2() {
  Serial.println("Blink 2");
}

  
