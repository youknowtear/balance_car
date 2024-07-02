#ifndef __KEY_H
#define __KEY_H


#include "stm32f10x.h"                  // Device header


#define KEY1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)
#define KEY2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)
#define KEY3 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#define KEY4 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define KEY5 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)
#define KEY6 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)




typedef struct KEY_CLASS
{
 int  key_num;
 char long_flag;   
 char press_time;   
      
}KEY;





void Key_GetNum(void);
void Key_Init(void);
uint8_t key_loop(void);


//extern int flag;
extern u8 key_type;
extern u16 text;
extern u8 key_shake;
extern u8 KeyState;
extern u8 keyPressFlag;
extern uint8_t view;
extern KEY key;



#endif
