#include <PID_v1.h>                     
#include <Servo.h>                      //include the servo library

Servo SteeringServo;                    // Servo object Servo
Servo MotorServo;                       // Servo object Motorcontrol

int hallIsrLeft = 5;
int hallIsrRight = 6;
float circ=0.065*3.14;                  //circumference of wheeel
float vel=0;
float lastTime=0;
float timevel;
float lastVel;
float angle = 0.75;                      // Steering angle -1 is left 0 is straigth and 1 is right. X100 for % 
float mps = 0.75;                        // Engine speed where 0 is standing still and 1 is full throttle

volatile byte state = LOW;

void setup() { 
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(hallIsrLeft), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(hallIsrRight), blink2, FALLING);
  //interrupts();
                                             // Sets the data rate in bits per second (baud) for serial data transmission.
  //MotorSetup();                              // Engine function to tab for setup
  //ServoSetup();                              // Servo function to tab for setup
  Serial.println("Setup completed!");
  delay(1000);
}
void loop() {
//  digitalWrite(3, HIGH);
//  delay(1000);
//  digitalWrite(3, LOW);
//  digitalWrite(ISR_pin, HIGH);

//  SetSpeed(mps);                               //Makes function for running the motortab        
//  SetSteering(angle);                            //Makes function for running the servotab
//  angle = 0.5;
//  SetSteering(angle);
//  
//  delay(3000);                              //demonstration time of 3 sek until reset below                      
//  MotorServo.writeMicroseconds(1200);       //set speed to 0
//  SteeringServo.writeMicroseconds(1550);    //set steering straight 
//  delay(2000);                              //Keep it zero for 2 sek until showing desierd values again.
}

void blink1() {
  Serial.println("blink 1!");
  state = !state;
}

void blink2() {
  Serial.println("Blink 2");
}

  
