// Specify the links and initial tuning parameters
double KpSteer=1.5, KiSteer=0.4, KdSteer=0.6;
PID SteeringPID(&remapAlpha, &angle, &SetSteer, KpSteer, KiSteer, KdSteer, DIRECT);

void PidSteerSetup(){
  // Turn the PID on
//  SteeringPID.SetOutputLimits(0, 2);
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
