/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

//Specify the links and initial tuning parameters
double Kp=0.1, Ki=0.2, Kd=0;
PID TheSpeedPID(&hallVelocity, &mps, &SetpointSpeed, Kp, Ki, Kd, DIRECT);

void PidSetup(){
  //turn the PID on
  TheSpeedPID.SetMode(AUTOMATIC);
}

void PidSpeed(){
  TheSpeedPID.Compute();
  delay(100);
}
