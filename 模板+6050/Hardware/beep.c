#include "headfile.h"



void beep_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;//�����ṹ�塪��GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʱ��ʹ��GPIOB

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//��������pin_8 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//Ƶ��50Mhz
	
    GPIO_Init(GPIOB,&GPIO_InitStructure);//��ʼ��GPIOB
	
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









