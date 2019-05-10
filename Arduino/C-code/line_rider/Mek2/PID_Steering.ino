// Specify the links and initial tuning parameters
double KpSteer=2.5, KiSteer=0.2, KdSteer=0;
PID SteeringPID(&remapAlpha, &angle, &SetSteer, KpSteer, KiSteer, KdSteer, DIRECT);

void PidSteerSetup(){
  // Turn the PID on
  SteeringPID.SetOutputLimits(-1, 1);
  SteeringPID.SetMode(AUTOMATIC);
}

void PidSteer(){
//      Serial.print("remapAlpha: ");
//      Serial.println(remapAlpha);
  SteeringPID.Compute();
//      Serial.print("angle: ");
//      Serial.println(angle);
  delay(prio1);
}
