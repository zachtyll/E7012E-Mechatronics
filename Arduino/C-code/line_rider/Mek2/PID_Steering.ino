// Specify the links and initial tuning parameters
double KpSteer=2 , KiSteer=0.4, KdSteer=0.2;
PID SteeringPID(&remapAlpha, &angle, &SetSteer, KpSteer, KiSteer, KdSteer, DIRECT);

void PidSteerSetup(){
  // Turn the PID on
  SteeringPID.SetOutputLimits(0, 2);
  SteeringPID.SetSampleTime(1); 
  SteeringPID.SetMode(AUTOMATIC);
}

void PidSteer(){
//      Serial.print("remapAlpha: ");
//      Serial.println(remapAlpha);
  SteeringPID.Compute();
//     Serial.print("angle: ");
//     Serial.println(angle);
  delay(1);
  //delay(prio1);
}
