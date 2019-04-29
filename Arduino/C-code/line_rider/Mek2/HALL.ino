double hallVelocity = 0;
float previousTime = 0;
float hallPeriod = 0;
float previousVelocity = 0;
const float circumference = 0.065* 3.14;    //circumference of wheel

void Sensor(){
  if (millis() > previousTime + 15){                  // Ensure no double detection by 'low-pass filtering'
    hallPeriod = (millis() - previousTime) / 1000;    // Calculates the time since last trigger of the sensor.
    hallVelocity = circumference * 0.5 / hallPeriod;  // Calculates the speed the car has reached.
    previousTime = millis();                          // Set previous time for next loop
    previousVelocity = hallVelocity;                  // Set previous velocity for next loop
  }
}
void LastVelocity(){
  if (previousVelocity!= hallVelocity) {        
  //Serial.println(previousVelocity);
  }
}
