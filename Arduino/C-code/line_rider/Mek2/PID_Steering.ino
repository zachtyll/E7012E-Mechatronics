// Define the aggressive and conservative tuning parameters.
double aggKp = 2, aggKi = 0.8, aggKd = 0.4;
double consKp = 2 , consKi = 0, consKd = 0;

// Specify the links and initial tuning parameters.
PID SteeringPID(&remapAlpha, &angle, &SetpointSteering, consKp, consKi, consKd, DIRECT);

void PidSteerSetup(){
  // Set limits, sample time and mode for PID.
  SteeringPID.SetOutputLimits(-1, 1);
  SteeringPID.SetSampleTime(1); 
  SteeringPID.SetMode(AUTOMATIC);
}

void PidSteer(){
  Serial5.print(remapAlpha);
  Serial5.print(",");
  Serial5.print(SetpointSteering);
  Serial5.print(",");
  Serial5.print(angle);
  Serial5.println(",");
  double gap = (SetpointSteering + abs(remapAlpha));
  if (gap < 0.5) 
  { // If the line is close to the set point, conservative values for PID
    SteeringPID.SetTunings(consKp, consKi, consKd);
    Serial.println("CONS");
  }
  else
  { // If the line is close to the set point, aggressive values for PID
    SteeringPID.SetTunings(aggKp, aggKi, aggKd);
    Serial.println("AGG");
  }
  SteeringPID.Compute();
  delay(prio1);
}
