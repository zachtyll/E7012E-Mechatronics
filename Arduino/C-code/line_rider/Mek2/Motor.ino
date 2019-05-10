const int minPulseMotor = 1080;     //Motor min pulse
const int maxPulseMotor = 1920;     //Motor max pulse

const float mpsRange = 420.0;       //engine range from zero to max
const float mpsZero = 1500.0;       //calibrated zero engine speed
float speedval = 0.0;               //Define speedscaling value

void MotorSetup(){
  pinMode(ServoMotorPin, OUTPUT);   //Initialize the motorsignalpin as an OUTPUT
  MotorServo.attach(                //(pin, min pulse width, max pulse width in microseconds)
    ServoMotorPin,
    minPulseMotor,
    maxPulseMotor
  ); 
  MotorServo.writeMicroseconds(mpsZero);  // Initialize the motor with 1500.
}

void SetSpeed(){
  speedval = mpsZero + mpsRange * mps;    //engine value multiplied to scale with Esc speed
  speedval = constrain(speedval, minPulseMotor, maxPulseMotor);
  MotorServo.writeMicroseconds(speedval); //Send engine speed in microsecounds(pulse) to output pin
  delay(15); 


  








}
