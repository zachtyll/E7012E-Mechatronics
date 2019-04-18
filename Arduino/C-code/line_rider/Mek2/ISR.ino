void IsrSetup() {
  attachInterrupt(digitalPinToInterrupt(hallIsrLeft), Sensor, FALLING);
  attachInterrupt(digitalPinToInterrupt(hallIsrRight), blink2, FALLING);
  Serial.println("ISR setup completed!");
}
