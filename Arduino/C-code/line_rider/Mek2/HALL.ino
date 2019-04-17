void Sensor(){
    if (millis()!= lastTime){
      currentTime = millis();
      hallPeriod = (currentTime - lastTime) / 1000;
      hallVelocity = circumference * 0.5 / hallPeriod;
      Serial.println(hallVelocity);
      lastTime = millis();
      lastVelocity = hallVelocity;
    }    
}
void LastVelocity(){
  if (lastVelocity!= hallVelocity) {
  Serial.println(hallVelocity);
  }
}
