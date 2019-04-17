#include <Servo.h>


int ServoMotorPin = 8;        //Pin for motor
int minPulseMotor = 1000;     //Motor min pulse
int maxPulseMotor = 2000;     //Motor max pulse

float mpsRange = 420.0;       //engine range from zero to max
float mpsZero = 1500.0;       //calibrated zero engine speed
float speedval = 0.0;         //Define speedscaling value

void MotorSetup(){
  pinMode(ServoMotorPin, OUTPUT);                                 //Initialize the motorsignalpin as an OUTPUT
  MotorServo.attach(ServoMotorPin, minPulseMotor, maxPulseMotor); //(pin, min pulse width, max pulse width in microseconds)
  Serial.println("Motor setup completed!);
}

void SetSpeed(float mps){
  speedval = mpsZero + mpsRange * mps;       //engine value multiplied to scale with Esc speed
  MotorServo.writeMicroseconds(speedval); //Send engine speed in microsecounds(pulse) to output pin
  Serial.println(speedval);               //Display value of engine speed
  delay(15); 
}
