// Include Scheduler since we want to manage multiple tasks.
#include <Scheduler.h>
#include <math.h>
#include <PID_v1.h>                     
#include <Servo.h>                    //include the servo library

Servo SteeringServo;                  // Servo object Servo
Servo MotorServo;                     // Servo object Motorcontrol

// Prios for scheduling.
const int prio1 = 1;                // Priority levels measured in ms.
const int prio2 = 2;                // 1 is highest and n+1 is lowest.
const int prio3 = 3;                // e.g. for every 4 prio1 you get 1 prio4. 
const int prio4 = 4;

int PTSens[8]={0,0,0,0,0,0,0,0};

double angle = 1;                     // Steering angle -1 is left 0 is straight and 1 is right. X100 for % 
double mps = 0;                       // Engine speed where 0 is standing still and 1 is full throttle
double SetSteer = 0;                  // Setpoint for steering
double SensorArray = 0;               // Sum of all hall-sensor. Value used for stearing
double remapAlpha = 1;                // 1 is forward.

double hallVelocity = 0;

// Setpoints PID
double SetpointSpeed= 0.85;            // Setpoint for speed
double SetpointStearing = 1;          // Setpoint for steering

                                      // Pin 0: Reserved for Bluetooth.
                                      // Pin 1: Reserved for Bluetooth.
const int PhotoTrans1 = 2;            // Pin 2: Phototransistor1
const int PhotoTrans2 = 3;            // Pin 3: Phototransistor2
const int PhotoTrans3 = 4;            // Pin 4: Phototransistor3
const int PhotoTrans4 = 5;            // Pin 5: Phototransistor4
const int PhotoTrans5 = 6;            // Pin 6: Phototransistor5
const int PhotoTrans6 = 7;            // Pin 7: Phototransistor6
const int PhotoTrans7 = 8;            // Pin 8: Phototransistor7
const int PhotoTrans8 = 9;            // Pin 9: Phototransistor8
const int ServoSteeringPin = 10;      // Pin 10: Steering control.
const int ServoMotorPin = 11;         // Pin 11: Motor control.
//const int hallIsrLeft = 12;         // Pin 12: Left Hall sensor.
const int hallIsrRight = 13;          // Pin 13: Right Hall sensor.


void setup() {
  Serial.begin(9600);                 // USB COM.
  Serial5.begin(9600);                // Bluetooth COM.
  
  IsrSetup();                         // Setup for ISR.  
  MotorSetup();                       // Setup for motor.
  ServoSetup();                       // Setup for steering servo.
  SensorArraySetup();                 // Setup for Sensor Array
  PidSetup();                         // Setup for PID_Speed
  PidSteerSetup();                    // Setup for stearing PID
  SetSpeed();                         // Startsignal for ECU
  delay(5000);
  
  Scheduler.startLoop(ReadPhotoTrans);    // Add ReadPhotoTrans to Schedule
  Scheduler.startLoop(PidSpeed);          // Add PidSpeed to Schedule
  Scheduler.startLoop(PidSteer);          // Add PidSteer to Schedule
  Scheduler.startLoop(Printtab);          // Add Printvaribles to Schedule
  Scheduler.startLoop(SetSteering);       // Add Servo input to Schedule
  Scheduler.startLoop(SetSpeed);          // Add ESC input to Schedule
}

void loop() {
  delay(1);
  //delay(prio1);
  yield();
}
