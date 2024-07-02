#include "PID.h"

float Velcity_Kp,  Velcity_Ki,  Velcity_Kd; //����ٶ�PID����
float Vertical_KD,Vertical_KP;              //ֱ�������Ʋ���
float Velocity_KP,Velocity_KI;              //�ٶȻ����Ʋ���
float Turn_KP,Turn_KD;                      //ת�򻷿��Ʋ���
            
///***************************************************************************
//�������ܣ�����ıջ�����
//��ڲ��������ҵ���ı�����ֵ
//����ֵ  �������PWM
//***************************************************************************/

//int Velocity_A(int TargetVelocity, int CurrentVelocity)
//{
//		int Bias;  //������ر���
//		static int ControlVelocity, Last_bias; //��̬�������������ý�������ֵ��Ȼ����
//		
//		Bias=TargetVelocity-CurrentVelocity; //���ٶ�ƫ��
//		
//		ControlVelocity+=Velcity_Kp*(Bias-Last_bias)+Velcity_Ki*Bias;  //����ʽPI������
//                                                                   //Velcity_Kp*(Bias-Last_bias) ����Ϊ���Ƽ��ٶ�
//	                                                                 //Velcity_Ki*Bias             �ٶȿ���ֵ��Bias���ϻ��ֵõ� ƫ��Խ����ٶ�Խ��
//		Last_bias=Bias;	
//		return ControlVelocity; //�����ٶȿ���ֵ
//	
//}


//int Velocity_B(int TargetVelocity, int CurrentVelocity)
//{
//		int Bias;  //������ر���
//		static int ControlVelocity, Last_bias; //��̬�������������ý�������ֵ��Ȼ����
//		
//		Bias=TargetVelocity-CurrentVelocity; //���ٶ�ƫ��
//		
//		ControlVelocity+=Velcity_Kp*(Bias-Last_bias)+Velcity_Ki*Bias;  //����ʽPI������
//                                                                   //Velcity_Kp*(Bias-Last_bias) ����Ϊ���Ƽ��ٶ�
//	                                                                 //Velcity_Ki*Bias             �ٶȿ���ֵ��Bias���ϻ��ֵõ� ƫ��Խ����ٶ�Խ��
//		Last_bias=Bias;	
//		return ControlVelocity; //�����ٶȿ���ֵ
//	
//}





/***************************************************************************
�������ܣ�ֱ����
��ڲ����������Ƕ�   //�⻷����ó�
��ڲ�������ʵ�Ƕ�   //�����ǻ��
��ڲ��������ٶ�     //�����ǻ��
����ֵ  �������PWM
***************************************************************************/
//ֱ����PD����ǰ

int Vertical(float Med,float Angle,float gyro_Y)
{
    int temp;   //����Ǹ�����ٶ�
    temp = Vertical_KP*(Angle-Med)+Vertical_KD*gyro_Y;
    return temp;
}

/***************************************************************************
�������ܣ��ٶȻ�
��ڲ����������ٶ�
��ڲ�������ʵ�ٶ�,������
����ֵ  �������PWM
***************************************************************************/



int Velocity(int Target,int encoder_l,int encoder_r)
{
    static int Err_LowOut_last,Encoder_S;
    static float  a=0.7;
    //����ƫ��ֵ
    int Err,Err_LowOut,temp;
    Err=(encoder_l+encoder_r)-Target;
    //��ͨ�˲�,�൱��ȡȨ���˲�
    Err_LowOut=(1-a)*Err+a*Err_LowOut_last;
    Err_LowOut_last=Err_LowOut;
    
    //����������Ļ���ֵ
    Encoder_S+=Err_LowOut;
    
    //�����޷�
    
    Encoder_S=Encoder_S>20000?20000:(Encoder_S<(-20000)?(-20000):Encoder_S);
    //������-20000��20000֮��
    
    //��������Ϊ�л���ֵ��Ӱ�죬С����һֱ��ǰ
    
//    if(stop==1)Encoder_S=0,stop=0;
//����Ƿŵ�ң�����е�

//KP�˱�����Ҳ�������ֵ��KI�˻��֣�Ҳ�����ۼƣ�KD��΢��
    //�ٶȻ�����
    temp=Velocity_KP*Err_LowOut+Velocity_KI*Encoder_S;
    return temp;

}


/***************************************************************************
�������ܣ�ת��
��ڲ�����ת��Ľ��ٶ�
��ڲ�����ƫ��ֵ��������ת���ĽǶȣ�
����ֵ  ��
***************************************************************************/


int Turn(float gyro_Z,int Target_turn)
{
    int temp;
    temp=Turn_KP*Target_turn+Turn_KD*gyro_Z;
    return temp;

}






