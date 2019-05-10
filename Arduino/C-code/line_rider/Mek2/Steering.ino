const int minPulse = 1430;            // Minimum servo position
const int maxPulse = 1670;            // Maximum servo position

const float calibratedMid = 1550.0;   //Calibrated mid value
const float steerRange = 120.0;       //Steering range
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
  steerAmplitude = calibratedMid + steerRange * angle;    //Steering value multiplied to scale with servo
  steerAmplitude = constrain(steerAmplitude, minPulse, maxPulse);
  SteeringServo.writeMicroseconds(steerAmplitude);              //Send steering in microsecounds(pulse) to output pin
  //Serial.println(steerAmplitude);
  //delay(15 + 1000 * oldAngle);
  oldAngle = SensorArray;
  delay(prio1);
}
