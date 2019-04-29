float PhotoTrans1Value=0;
int PTSens[6]={0};
float LastSensorArray=0;

void SensorArraySetup(){
    pinMode(PhotoTrans1, INPUT);
    pinMode(PhotoTrans2, INPUT);
    pinMode(PhotoTrans3, INPUT);
    pinMode(PhotoTrans4, INPUT);
    pinMode(PhotoTrans5, INPUT);
    pinMode(PhotoTrans6, INPUT); 
    pinMode(PhotoTrans7, INPUT);
    pinMode(PhotoTrans8, INPUT); 
  }

void ReadPhotoTrans(){
  PTSens[0] = digitalRead(PhotoTrans1);
  PTSens[1] = digitalRead(PhotoTrans2);
  PTSens[2] = digitalRead(PhotoTrans3);
  PTSens[3] = digitalRead(PhotoTrans4);
  PTSens[4] = digitalRead(PhotoTrans5);
  PTSens[5] = digitalRead(PhotoTrans6);
  PTSens[6] = digitalRead(PhotoTrans7);
  PTSens[7] = digitalRead(PhotoTrans8);

  LastSensorArray=SensorArray;
  SensorArray = PTSens[0]*(-1) + PTSens[1]*(-0.5) + PTSens[2]*(-0.3) + PTSens[3]*(-0.1) + PTSens[4]*(0.1) + PTSens[5]*(0.3) + PTSens[6]*(0.5) + PTSens[7]*(1);      //Calculating stearing value
  SensorArray = SensorArray /(PTSens[0] + PTSens[1] + PTSens[2] + PTSens[3] + PTSens[4] + PTSens[5] + PTSens[6] + PTSens[7]);                                                      //Calculations coninues
  if (SensorArray = 0){
    SensorArray = LastSensorArray;      //If no new value, use old
    } 
  //Serial.print("Photo Transistor 1 value: ");
  //PhotoTrans1Value=digitalRead(PhotoTrans1);
  //PhotoTrans1Value=analogRead(A5);
  //Serial.println(PhotoTrans1Value);
  
  }
