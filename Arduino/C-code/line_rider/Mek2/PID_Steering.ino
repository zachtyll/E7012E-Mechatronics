#include <PID_v1.h>

//Specify the links and initial tuning parameters
double KpSteer=1, KiSteer=0, KdSteer=0;
PID SteeringPID(&SensorArray, &angle, &SetSteer, KpSteer, KiSteer, KdSteer, DIRECT);

void PidSteerSetup(){
  //turn the PID on
  SteeringPID.SetMode(AUTOMATIC);
}

void PidSteer(){
  SteeringPID.Compute();
  delay(10);
}
