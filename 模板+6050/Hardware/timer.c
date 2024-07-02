#include "headfile.h"


void Timer3_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//�ṹ�嶨��    
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//����ʱ��
	
	TIM_InternalClockConfig(TIM3);//�����ڲ�ʱ�Ӹ� TIM3�ṩʱ��Դ
	

	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//����ʱ�ӷָ�,�����ǲ��ָ�
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_Period=100 - 1;//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	//�������ڶ�ʱ��ÿ��1000�����ʹ���һ�θ���ʱ��
    
    TIM_TimeBaseInitStructure.TIM_Prescaler=7200 - 1;//Ԥ��Ƶֵ
	//ʱ�ӷ�Ƶ
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//��ʱ0.001�룬����һ���ж�
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
	
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);//�ж����
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//������ʱ���ж�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ�����
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;//�����ж�Դ
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//�ж�Դʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//��Ӧ���ȼ�
	NVIC_Init(&NVIC_InitStructure); //����NVIC��ʼ������
	
	TIM_Cmd(TIM3,ENABLE);//��ʱ��3ʹ��
}



















