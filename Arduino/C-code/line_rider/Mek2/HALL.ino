void Sensor(){
    Serial.println("Sensor TRIGGERED!");
    if (millis()!=lastTime){
      timevel=(millis()-lastTime)*1000;
      vel=circ*0.5/timevel;
      lastTime=millis();
      lastVel=vel;}    
}
void LastVelocity(){
  Serial.println("oTHER TRIGGERED!");
  if (lastVel!=vel) {
  Serial.println(vel);
  }
}
