// Include Scheduler since we want to manage multiple tasks.
#include <Scheduler.h>

#include <PID_v1.h>                     
#include <Servo.h>                    //include the servo library

Servo SteeringServo;                  // Servo object Servo
Servo MotorServo;                     // Servo object Motorcontrol

double angle = 0;                     // Steering angle -1 is left 0 is straight and 1 is right. X100 for % 
double mps = 0.0;                     // Engine speed where 0 is standing still and 1 is full throttle

double hallVelocity = 0;

double SetpointSpeed= 2;              // Setpoint for speed
double SetpointStearing = 0;          // Setpoint for stearing

                                      // Pin 0: Reserved for Bluetooth.
                                      // Pin 1: Reserved for Bluetooth.
const int PhotoTrans1 = 2;            // Pin 2: Phototransistor1
const int PhotoTrans2 = 3;            // Pin 3: Phototransistor2
const int PhotoTrans3 = 1;            // Pin 4: Phototransistor3
const int PhotoTrans4 = 5;            // Pin 5: Phototransistor4
const int PhotoTrans5 = 6;            // Pin 6: Phototransistor5
const int PhotoTrans6 = 7;            // Pin 7: Phototransistor6
const int PhotoTrans7 = 8;            // Pin 8: Phototransistor7
const int PhotoTrans8 = 9;            // Pin 9: Phototransistor8
const int ServoMotorPin = 10;         // Pin 10: Motor control.
const int ServoSteeringPin = 11;      // Pin 11: Steering control.
//const int hallIsrLeft = 12;         // Pin 12: Left Hall sensor.
const int hallIsrRight = 13;          // Pin 13: Right Hall sensor.

double SetSteer = 0;                    // Setpoint for steering
double SensorArray = 0;                 //Sum of all hall-sensor. Value used for stearing

void setup() {
  Serial.begin(9600);
  IsrSetup();                         // Setup for ISR.  
  MotorSetup();                       // Setup for motor.
  ServoSetup();                       // Setup for steering servo.
  SensorArraySetup();                 // Setup for Sensor Array
  PidSetup();                         // Setup for PID_Speed
  PidSteerSetup();                    // Setup for stearing PID
  SetSpeed(mps);                      // Startsignal for ECU

  Scheduler.startLoop(ReadPhotoTrans);    // Add ReadPhotoTrans to Schedule
  Scheduler.startLoop(PidSpeed);          // Add PidSpeed to Schedule
  //Scheduler.startLoop(PidSteer);        // Add PidSteer to Schedule
  Scheduler.startLoop(Printtab);          // Yada yada...
  Scheduler.startLoop(SetSteering);
}

void loop() {
  delay(100);
  yield();
}
