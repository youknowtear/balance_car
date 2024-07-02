#include "headfile.h"

uint16_t key_press_time=0;
uint16_t timerms=0;

u8 time_temp=0;
u8 time_10ms=0;
u8 time_20ms=0;
u8 time_50ms=0;




void delay(u8 mode)
{

    switch(mode)
    {
    case 1:
        if(time_10ms==1)
        {
        time_10ms=0;
        }
    break;
        
    case 2:
         if(time_20ms==1)   
         {
         time_20ms=0;
         }
    break;
   case 3:
         if(time_50ms==1)   
         {
         time_50ms=0;
         }
    break; 
    
    }
}


void TIM3_IRQHandler(void)//1ms�ж�
{
    
    
    
if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)//���ָ����TIM�жϷ������:TIM �ж�Դ
{
    timerms++;
    
    if(keyPressFlag )//������£���ô�Ϳ�ʼ�ư��µ�ʱ��
    {
    key_press_time++;    
    }
    
    if(timerms%10==0)//10ms����
    {
    time_10ms=1;
    time_temp++;
    key_shake=0;   //����������־λ 
           
    }
    if(time_temp%2==0)
    {
    time_20ms=1;
    
    
    
    
    
    }
    if(time_temp%5==0)
    {
    time_50ms=1;
    
    
    
    
    
    }    
        
        
        
        
        
        
           
        
        
        
        
        
        
        
        
        
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//���TIMx���жϴ�����λ:TIM �ж�Դ 	
}
}










