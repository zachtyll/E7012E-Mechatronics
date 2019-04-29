#include <PID_v1.h>                     
#include <Servo.h>                    //include the servo library

Servo SteeringServo;                  // Servo object Servo
Servo MotorServo;                     // Servo object Motorcontrol

double angle = 0;                     // Steering angle -1 is left 0 is straigth and 1 is right. X100 for % 
double mps = 0.0;                     // Engine speed where 0 is standing still and 1 is full throttle

double SetpointSpeed= 2;              // Setpoint for speed
double SetpointStearing = 0;          // Setpoint for stearing

const int PhotoTrans1 = 2;              // Pin 1: Phototransistor1
const int PhotoTrans2 = 3;              // Pin 2: Phototransistor2
const int PhotoTrans3 = 4;              // Pin 3: Phototransistor3
const int PhotoTrans4 = 5;              // Pin 4: Phototransistor4
const int PhotoTrans5 = 6;              // Pin 5: Phototransistor5
const int PhotoTrans6 = 7;              // Pin 6: Phototransistor6
const int PhotoTrans7 = 8;              // Pin 7: Phototransistor7
const int PhotoTrans8 = 9;              // Pin 8: Phototransistor8
const int hallIsrRight = 13;        // Pin 10: Right Hall sensor.
const int ServoMotorPin = 10;         // Pin 11: Motor control.
const int ServoSteeringPin = 11;      // Pin 12: Steering control.
//const int hallIsrLeft = 12;           // Pin 9: Left Hall sensor.



double SetStear=0;
double SensorArray=0;



void setup() { 
  Serial.begin(9600);                 // Sets the data rate in bits per second (baud) for serial data transmission.
  IsrSetup();                         // Setup for ISR.  
  MotorSetup();                       // Setup for motor.
  ServoSetup();                       // Setup for steering servo.
  SensorArraySetup();                 // Setup for Sensor Array
  PidSetup();                         // Setup for PID_Speed
  PidStearSetup();                    // Setup for stearing PID
  //Serial.println("Turn on your ECU in 5");
  SetSpeed(mps);                      // Startsignal for ECU
  delay(1000);
  //Serial.println("Turn on your ECU in 4"); 
  delay(1000);
  //Serial.println("Turn on your ECU in 3"); 
  delay(1000);
  //Serial.println("Turn on your ECU in 2"); 
  delay(1000);
  //Serial.println("Turn on your ECU in 1"); 
  delay(1000);
  //Serial.println("Setup completed!");
  delay(1000);
}
void loop() {  
  SetSpeed(mps);      // Makes function for running the motortab        
  SetSteering(angle); // Makes function for running the servotab
  ReadPhotoTrans();   // Reads phototransistors high/low and calculates stearing value (non pidded)
  PidSpeed();         // 
  PidStear();         // 

   
  Printtab();         //
}

  
