#ifndef _PID_h_
#define _PID_h_

#include "headfile.h"



extern float Vertical_KD,Vertical_KP;              //ֱ�������Ʋ���
extern float Velocity_KP,Velocity_KI;              //�ٶȻ����Ʋ���
extern float Turn_KP,Turn_KD;                      //ת�򻷿��Ʋ���



int Vertical(float Med,float Angle,float gyro_Y);
int Velocity(int Target,int encoder_l,int encoder_r);
int Turn(float gyro_Z,int Target_turn);



#endif


