#include <PID_v1.h>                     
#include <Servo.h>                      //include the servo library

Servo SteeringServo;                  // Servo object Servo
Servo MotorServo;                     // Servo object Motorcontrol

const float circumference = 0.065* 3.14;    //circumference of wheel

float angle = 0.75;                   // Steering angle -1 is left 0 is straigth and 1 is right. X100 for % 
float mps = 0.45;                     // Engine speed where 0 is standing still and 1 is full throttle

const int hallIsrLeft = 5;            // Pin 5: Left Hall sensor
const int hallIsrRight = 6;           // Pin 6: Right Hall sensor
const int ServoMotorPin = 8;          // Pin 8: Motor control
const int ServoPin = 9;               // Pin 9: Steering control

volatile byte state = LOW;

void setup() { 
  Serial.begin(9600);
  PinSetup();         // Setup for pins.
  IsrSetup();         // Setup for ISR.
                      // Sets the data rate in bits per second (baud) for serial data transmission.
  MotorSetup();       // Engine function to tab for setup
  ServoSetup();       // Servo function to tab for setup
  
  Serial.println("Setup completed!");
  delay(1000);
}
void loop() {  
    SetSpeed(mps);                               //Makes function for running the motortab        
    angle = 0.25;
    SetSteering(angle);                            //Makes function for running the servotab
    angle = 0.5;
}

void blink1() {
  Serial.println("blink 1!");
}

void blink2() {
  Serial.println("Blink 2");
}

  
