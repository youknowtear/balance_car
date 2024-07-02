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


void TIM3_IRQHandler(void)//1ms中断
{
    
    
    
if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)//检查指定的TIM中断发生与否:TIM 中断源
{
    timerms++;
    
    if(keyPressFlag )//如果按下，那么就开始计按下的时长
    {
    key_press_time++;    
    }
    
    if(timerms%10==0)//10ms工程
    {
    time_10ms=1;
    time_temp++;
    key_shake=0;   //按键消抖标志位 
           
    }
    if(time_temp%2==0)
    {
    time_20ms=1;
    
    
    
    
    
    }
    if(time_temp%5==0)
    {
    time_50ms=1;
    
    
    
    
    
    }    
        
        
        
        
        
        
           
        
        
        
        
        
        
        
        
        
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//清除TIMx的中断待处理位:TIM 中断源 	
}
}










