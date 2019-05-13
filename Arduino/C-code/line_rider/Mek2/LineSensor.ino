float PhotoTrans1Value=0;
float LastSensorArray=0;
float SensorCheck=0;

const double Lc = 260;
const double Ls = 112;
double alpha = 0;
//double remapAlpha = 0;
double constrainedRemapAlpha = 0;
double SetpointSpeed1=0;

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
  SensorArray = PTSens[0]*(-127) + PTSens[1]*(-82) + PTSens[2]*(-40) + PTSens[3]*(-5) + PTSens[4]*(5) + PTSens[5]*(40) + PTSens[6]*(82) + PTSens[7]*(127);  // Summation of the active sensors with its distance to normal
  //SensorArray = PTSens[0]*(-127) + PTSens[1]*(-90) + PTSens[2]*(-30) + PTSens[3]*(-10) + PTSens[4]*(10) + PTSens[5]*(30) + PTSens[6]*(90) + PTSens[7]*(127);  // Summation of the active sensors with its distance to normal
  SensorCheck = PTSens[0] + PTSens[1] + PTSens[2] + PTSens[3] + PTSens[4] + PTSens[5] + PTSens[6] + PTSens[7];
  
  if (SensorCheck == 0){
      SensorArray = LastSensorArray;                                                                                                                              //If no sensor is active, take last know value of SensorArray
    }
  else{
     SensorArray = SensorArray / SensorCheck;    // Mean value of the active sensors 
      }
      
   // CALCULATION FOR ANGLE   
   alpha = atan((2*Lc*SensorArray)/((Lc+Ls)*(Lc+Ls)+SensorArray*SensorArray)); 
//   Serial.println(SensorArray);
 //  remapAlpha = ;  // re-map of alpha from -0.4--0.4 to -1 -- 1
   remapAlpha=constrain(alpha*2.5,-1,1);
//   Serial.print(remapAlpha);
//   Serial.print(",");
   
   // CALCULATION FOR BREAKING IN CORNERS
   SetpointSpeed1 = SetpointSpeed * (1 - abs(alpha / 1.4));
   delay(prio1);
  }
