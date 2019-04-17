void IsrSetup() {
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(hallIsrLeft), Sensor, FALLING);
  attachInterrupt(digitalPinToInterrupt(hallIsrRight), blink2, FALLING);
}
