float hallVelocity = 0;
float lastTime = 0;
float hallPeriod = 0;
float currentTime = 0;
float lastVelocity;

void Sensor(){
    if (millis()!= lastTime){
      currentTime = millis();
      hallPeriod = (currentTime - lastTime) / 1000;
      hallVelocity = circumference * 0.5 / hallPeriod;
      Serial.println(hallVelocity);
      lastTime = millis();
      lastVelocity = hallVelocity;
      Serial.print("Speed: ");
      Serial.println(hallVelocity);
    }
}
void LastVelocity(){
  if (lastVelocity!= hallVelocity) {
  Serial.println(hallVelocity);
  }
}
