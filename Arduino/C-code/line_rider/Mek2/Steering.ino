const int minPulse = 1000;            // Minimum servo position
const int maxPulse = 2000;            // Maximum servo position

const float calibratedMid = 1550.0;   //Calibrated mid value
const float steerRange = 250.0;       //Steering range
float steerAmplitude = 0.0;           // define steeringscaling value
float oldAngle = 0.0;

void ServoSetup(){
  pinMode(ServoSteeringPin, OUTPUT);  //Initialize the Servosignalpin as an OUTPUT
  SteeringServo.attach(               //(pin, min pulse width, max pulse width in microseconds)
    ServoSteeringPin,
    minPulse,
    maxPulse
  );     
  SteeringServo.writeMicroseconds(1550);
}  

void SetSteering(){
  steerAmplitude = calibratedMid + steerRange * (angle+1);    //Steering value multiplied to scale with servo
  SteeringServo.writeMicroseconds(steerAmplitude);              //Send steering in microsecounds(pulse) to output pin
  //delay(15 + 1000 * oldAngle);
  oldAngle = SensorArray;
  delay(prio1);
}
