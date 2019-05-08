
void Printtab(){
//  Serial.print(hallVelocity);
//  Serial.print(",");
//  Serial.println(mps);

//  Serial.print("Speed: ");                          // Print
//  Serial.println(speedval);
//  Serial.print("output:");
//  Serial.println(mps);
//  Serial.print("Steering angle");
//  Serial.println(SensorArray);
  Serial.print(digitalRead(PhotoTrans1));
  Serial.print(digitalRead(PhotoTrans2));
  Serial.print(digitalRead(PhotoTrans3));
  Serial.print(digitalRead(PhotoTrans4));
  Serial.print(digitalRead(PhotoTrans5));
  Serial.print(digitalRead(PhotoTrans6));
  Serial.print(digitalRead(PhotoTrans7));
  Serial.println(digitalRead(PhotoTrans8));
//  Serial.print(angle);
//  Serial.print(",");
//  Serial.println(SensorArray);
  delay(100);



  
}
