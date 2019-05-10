// Specify the links and initial tuning parameters
double Kp=0.1, Ki=0.2, Kd=0;
PID SpeedPID(&hallVelocity, &mps, &SetpointSpeed, Kp, Ki, Kd, DIRECT);

void PidSetup(){
  // Turn the PID on
//  SpeedPID.SetOutputLimits(1080, 1920);
  SpeedPID.SetMode(AUTOMATIC);
}

void PidSpeed(){
  SpeedPID.Compute();
  delay(prio1);
}
