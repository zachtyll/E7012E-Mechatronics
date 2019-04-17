#include <PID_v1.h>

double Input = 0;
double Output = 0;
double Setpoint = 0;
int mode = MANUAL;  //set automatic and manual

double Kp = 0;
double Ki = 0;
double Kd = 0;

double Max = 255;
double Min = 0;

int Sampletime = 200e-3;


void Pid(){
//SetMode(mode);
//SetOutputLimits(Min, Max);
//SetSampleTime(Sampletime);
//SetTunings(Kp, Ki, Kd);

}
