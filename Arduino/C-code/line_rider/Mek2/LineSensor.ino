float PhotoTrans1Value=0;
int PTSens[8]={0,0,0,0,0,0,0,0};
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
  PTSens[0] = digitalRead(PhotoTrans1); // Most right sensor in traveling direction
  PTSens[1] = digitalRead(PhotoTrans2);
  PTSens[2] = digitalRead(PhotoTrans3);
  PTSens[3] = digitalRead(PhotoTrans4);
  PTSens[4] = digitalRead(PhotoTrans5);
  PTSens[5] = digitalRead(PhotoTrans6);
  PTSens[6] = digitalRead(PhotoTrans7);
  PTSens[7] = digitalRead(PhotoTrans8); //Most left sensor in traveling direction

  
  LastSensorArray=SensorArray;                                                                                                                                  // Last know SenorArray value
  
  SensorArray = PTSens[0]*(1) + PTSens[1]*(0.5) + PTSens[2]*(0.3) + PTSens[3]*(0.1) + PTSens[4]*(-0.1) + PTSens[5]*(-0.3) + PTSens[6]*(-0.5) + PTSens[7]*(-1);  // Summation of the active sensors with its distance to normal
  if (SensorArray == 0){
    SensorArray = LastSensorArray;                                                                                                                              //If no sensor is active, take last know value of SensorArray
    }
  else{
     SensorArray = SensorArray /(PTSens[0] + PTSens[1] + PTSens[2] + PTSens[3] + PTSens[4] + PTSens[5] + PTSens[6] + PTSens[7]);                                // Mean value of the active sensors 
     angle=SensorArray; 
      } 
  }
