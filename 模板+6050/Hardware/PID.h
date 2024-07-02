#ifndef _PID_h_
#define _PID_h_

#include "headfile.h"



extern float Vertical_KD,Vertical_KP;              //直立环控制参数
extern float Velocity_KP,Velocity_KI;              //速度环控制参数
extern float Turn_KP,Turn_KD;                      //转向环控制参数



int Vertical(float Med,float Angle,float gyro_Y);
int Velocity(int Target,int encoder_l,int encoder_r);
int Turn(float gyro_Z,int Target_turn);



#endif


