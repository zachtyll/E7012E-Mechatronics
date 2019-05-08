void IsrSetup() {
  attachInterrupt(digitalPinToInterrupt(hallIsrRight), Sensor, FALLING);     // Interrupt for left hall sensor, runs "Sensor"  
}
