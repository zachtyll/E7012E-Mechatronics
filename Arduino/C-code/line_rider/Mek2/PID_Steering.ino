
#include <PID_v1.h>

//Specify the links and initial tuning parameters
double KpStear=0.1, KiStear=0.75, KdStear=0;
PID StearingPID(&SensorArray, &angle, &SetStear, KpStear, KiStear, KdStear, DIRECT);

void PidStearSetup(){
  //turn the PID on
  StearingPID.SetMode(AUTOMATIC);
  //Serial.println("PID-Speed setup completed!");
}

void PidStear(){
  StearingPID.Compute();

}
