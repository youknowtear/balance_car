#include "PID.h"

float Velcity_Kp,  Velcity_Ki,  Velcity_Kd; //相关速度PID参数
float Vertical_KD,Vertical_KP;              //直立环控制参数
float Velocity_KP,Velocity_KI;              //速度环控制参数
float Turn_KP,Turn_KD;                      //转向环控制参数
            
///***************************************************************************
//函数功能：电机的闭环控制
//入口参数：左右电机的编码器值
//返回值  ：电机的PWM
//***************************************************************************/

//int Velocity_A(int TargetVelocity, int CurrentVelocity)
//{
//		int Bias;  //定义相关变量
//		static int ControlVelocity, Last_bias; //静态变量，函数调用结束后其值依然存在
//		
//		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
//		
//		ControlVelocity+=Velcity_Kp*(Bias-Last_bias)+Velcity_Ki*Bias;  //增量式PI控制器
//                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
//	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
//		Last_bias=Bias;	
//		return ControlVelocity; //返回速度控制值
//	
//}


//int Velocity_B(int TargetVelocity, int CurrentVelocity)
//{
//		int Bias;  //定义相关变量
//		static int ControlVelocity, Last_bias; //静态变量，函数调用结束后其值依然存在
//		
//		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
//		
//		ControlVelocity+=Velcity_Kp*(Bias-Last_bias)+Velcity_Ki*Bias;  //增量式PI控制器
//                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
//	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
//		Last_bias=Bias;	
//		return ControlVelocity; //返回速度控制值
//	
//}





/***************************************************************************
函数功能：直立环
入口参数：期望角度   //外环计算得出
入口参数：真实角度   //陀螺仪获得
入口参数：角速度     //陀螺仪获得
返回值  ：电机的PWM
***************************************************************************/
//直立环PD控制前

int Vertical(float Med,float Angle,float gyro_Y)
{
    int temp;   //这个是给电机速度
    temp = Vertical_KP*(Angle-Med)+Vertical_KD*gyro_Y;
    return temp;
}

/***************************************************************************
函数功能：速度环
入口参数：期望速度
入口参数：真实速度,编码器
返回值  ：电机的PWM
***************************************************************************/



int Velocity(int Target,int encoder_l,int encoder_r)
{
    static int Err_LowOut_last,Encoder_S;
    static float  a=0.7;
    //计算偏差值
    int Err,Err_LowOut,temp;
    Err=(encoder_l+encoder_r)-Target;
    //低通滤波,相当于取权重滤波
    Err_LowOut=(1-a)*Err+a*Err_LowOut_last;
    Err_LowOut_last=Err_LowOut;
    
    //计算编码器的积分值
    Encoder_S+=Err_LowOut;
    
    //积分限幅
    
    Encoder_S=Encoder_S>20000?20000:(Encoder_S<(-20000)?(-20000):Encoder_S);
    //限制在-20000到20000之间
    
    //清零是因为有积分值的影响，小车会一直往前
    
//    if(stop==1)Encoder_S=0,stop=0;
//这个是放到遥控器中的

//KP乘比例，也就是误差值，KI乘积分，也就是累计，KD乘微分
    //速度环计算
    temp=Velocity_KP*Err_LowOut+Velocity_KI*Encoder_S;
    return temp;

}


/***************************************************************************
函数功能：转向环
入口参数：转向的角速度
入口参数：偏差值（想让其转过的角度）
返回值  ：
***************************************************************************/


int Turn(float gyro_Z,int Target_turn)
{
    int temp;
    temp=Turn_KP*Target_turn+Turn_KD*gyro_Z;
    return temp;

}






