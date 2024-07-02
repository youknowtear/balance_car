#ifndef __isr_H_
#define __isr_H_
#include "stm32f10x.h"                  // Device header

void TIM3_IRQHandler(void);
void delay(u8 mode);









extern uint16_t key_press_time;
extern uint16_t timerms;

extern u8 time_temp;
extern u8 time_10ms;
extern u8 time_20ms;
extern u8 time_50ms;




#endif
