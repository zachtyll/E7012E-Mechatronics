#include <PID_v1.h>

//Specify the links and initial tuning parameters
double KpSteer=1, KiSteer=0, KdSteer=0;
PID SteeringPID(&constrainedRemapAlpha, &angle, &SetSteer, KpSteer, KiSteer, KdSteer, DIRECT);

void PidSteerSetup(){
  //turn the PID on
  SteeringPID.SetMode(AUTOMATIC);
}

void PidSteer(){
      Serial.print("Alpha: ");
      Serial.println(constrainedRemapAlpha);
  SteeringPID.Compute();
      Serial.print("angle: ");
      Serial.println(angle);
  delay(prio1);
}
