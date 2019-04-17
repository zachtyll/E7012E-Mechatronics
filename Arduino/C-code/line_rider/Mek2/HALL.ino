float circ=0.065*3.14; //circumference of wheeel
float vel=0;
float lastTime=0;
float timevel;
float lastVel;
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), sensor, RISING);  
  

}

void loop() {
  Serial.print(vel);
  digitalWrite(3, 1);
  delay(1000);
  digitalWrite(3, 0);
  lastVelocity;
}

void sensor(){
    if (millis()!=lastTime){
      timevel=(millis()-lastTime)*1000;
      vel=circ*0.5/timevel;
      lastTime=millis();
      lastVel=vel;}    
  }
void lastVelocity(){
  if (lastVel!=vel) {
  Serial.println(vel);
  }}
