void IsrSetup() {
  attachInterrupt(digitalPinToInterrupt(hallIsrRight), ReadHallSensor, FALLING);     // Interrupt for left hall sensor, runs "Sensor"  
}
