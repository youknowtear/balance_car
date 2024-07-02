#include "headfile.h"


void Timer3_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//结构体定义    
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//开启时钟
	
	TIM_InternalClockConfig(TIM3);//采用内部时钟给 TIM3提供时钟源
	

	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//设置时钟分割,这里是不分割
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //TIM向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period=100 - 1;//设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	//计数周期定时器每记1000个数就触发一次更新时间
    
    TIM_TimeBaseInitStructure.TIM_Prescaler=7200 - 1;//预分频值
	//时钟分频
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//定时0.001秒，进入一次中断
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);//中断清除
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//开启定时器中断
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级分组
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;//设置中断源
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//中断源使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//响应优先级
	NVIC_Init(&NVIC_InitStructure); //调用NVIC初始化函数
	
	TIM_Cmd(TIM3,ENABLE);//定时器3使能
}



















