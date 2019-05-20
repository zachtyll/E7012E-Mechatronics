const int minPulse = 1290;            // Minimum servo position
const int maxPulse = 1660;            // Maximum servo position

const float calibratedMid = 1470.0;   //Calibrated mid value
const float steerRange = 180.0;       //Steering range
float steerAmplitude = 0.0;           // define steeringscaling value
float oldAngle = 0.0;
float steerAmplitudeHead = 0.0;

void ServoSetup(){
  pinMode(ServoSteeringPin, OUTPUT);  //Initialize the Servosignalpin as an OUTPUT
  SteeringServo.attach(               //(pin, min pulse width, max pulse width in microseconds)
    ServoSteeringPin,
    minPulse,
    maxPulse
  );     
  SteeringServo.writeMicroseconds(calibratedMid);

// HEAD MOVEMENT
  pinMode(ServoHeadPin, OUTPUT);  //Initialize the Servosignalpin as an OUTPUT
  ServoHead.attach(               //(pin, min pulse width, max pulse width in microseconds)
    ServoHeadPin,
    1000,
    2000
  );     
  ServoHead.writeMicroseconds(1500);
}  

void SetSteering(){
//  Serial.print("angle: ");
//  Serial.println(angle);
  steerAmplitude = minPulse + steerRange * angle;    //Steering value multiplied to scale with servo
  steerAmplitude = constrain(steerAmplitude, minPulse, maxPulse);
//  Serial.println(steerAmplitude);
  SteeringServo.writeMicroseconds(steerAmplitude);              //Send steering in microsecounds(pulse) to output pin
  steerAmplitudeHead = 1000 + 1000 * angle;
  ServoHead.writeMicroseconds(steerAmplitudeHead);
  
  delay(1);
  //delay(prio1);
}
