float PhotoTrans1Value=0;
float LastSensorArray=0;
float SensorCheck=0;

const double Lc = 260;
const double Ls = 112;
double alpha = 0;
double remapAlpha = 0;
double constrainedRemapAlpha = 0;

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
  SensorArray = PTSens[0]*(-127) + PTSens[1]*(-92) + PTSens[2]*(-57) + PTSens[3]*(-22) + PTSens[4]*(22) + PTSens[5]*(57) + PTSens[6]*(92) + PTSens[7]*(127);  // Summation of the active sensors with its distance to normal
  SensorCheck = PTSens[0] + PTSens[1] + PTSens[2] + PTSens[3] + PTSens[4] + PTSens[5] + PTSens[6] + PTSens[7];
  
  if (SensorCheck == 0){
      SensorArray = LastSensorArray;                                                                                                                              //If no sensor is active, take last know value of SensorArray
    }
  else{
     SensorArray = SensorArray /SensorCheck;    // Mean value of the active sensors 
      }
   // CALCULATION FOR ANGLE   
   alpha = atan((2*Lc*SensorArray)/((Lc+Ls)*(Lc+Ls)+SensorArray*SensorArray)); 
//   Serial.println(SensorArray);
   remapAlpha = alpha*2.5;  // re-map of alpha from -0.4--0.4 to 0 -- 2
       
  delay(prio1);
  }
