#include "headfile.h"



void beep_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;//声明结构体——GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//时钟使能GPIOB

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//定义引脚pin_8 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//频率50Mhz
	
    GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化GPIOB
	
    GPIO_SetBits(GPIOB,GPIO_Pin_5);

}




void beep_control(u8 mode)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_5);    
    
    switch(mode)
    {
        
        case 1:
            GPIO_ResetBits(GPIOB,GPIO_Pin_5);    
            delay(mode);
            GPIO_SetBits(GPIOB,GPIO_Pin_5);
            delay(mode);
            break;
        case 2:
            GPIO_ResetBits(GPIOB,GPIO_Pin_5);    
            delay(mode);
            GPIO_SetBits(GPIOB,GPIO_Pin_5);
            delay(mode);
            break;
        case 3:
            GPIO_ResetBits(GPIOB,GPIO_Pin_5);    
            delay(mode);
            GPIO_SetBits(GPIOB,GPIO_Pin_5);
            delay(mode);
            break;
        case 4:
            GPIO_ResetBits(GPIOB,GPIO_Pin_5);    
            break;       
        case 5:
            GPIO_SetBits(GPIOB,GPIO_Pin_5);
            break;           
    }


}









