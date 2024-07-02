#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "headfile.h"


KEY key;
u16 text=0;
u8 key_type;
u8 keyPressFlag = 0; //按键按下，定时器中打开key_press_time开始计时
u8 key_shake=0;
u8 key_state;
u8 KeyState=0;
extern int flag;         //记录你的选择  
uint8_t view=0;


/**
  * 函    数：按键初始化
  * 参    数：无
  * 返 回 值：无
  */
void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOB的时钟	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);		//开启GPIOB的时钟
	/*GPIO初始化*/

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						//将PB1和PB0引脚初始化为上拉输入
    
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PB1和PB0引脚初始化为上拉输入

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);						//将PB1和PB0引脚初始化为上拉输入    
    
    
}

/**
  * 函    数：按键获取键码
  * 参    数：无
  * 返 回 值：按下按键的键码值，范围：0~2，返回0代表没有按键按下
  * 注意事项：此函数是阻塞式操作，当按键按住不放时，函数会卡住，直到按键松手
  */
void Key_GetNum(void)
{
	if(KEY1==0)
    {
        key.key_num=1;
    }
	else if(KEY2==0)
    {
        key.key_num=2;
    }
    else if(KEY3==0)
    {
        key.key_num=3;
    }    
	else if(KEY4==0)
    {
        key.key_num=4;
    }    
	else if(KEY5==0)
    {
        key.key_num=5;
    }
    else if(KEY6==0)
    {
        key.key_num=6;
    }
    else
    {
        key.key_num=0; //默认为0
    }
    
}



/**
  * 函    数：获取按键状态
  * 参    数：无
  * 返 回 值：按下按键的键码值，返回0代表没有按键按下
  * 注意事项：此函数是阻塞式操作，当按键按住不放时，函数会卡住，直到按键松手
  */

//放在while中
uint8_t key_loop()
{
    static u16 view_flag; 
    static u16 press_time=0;
   u8 Key_Down,Key_Up,uc_Key_Value;
    static  u8 Key_Old = 0;
    static  u8 keyState = 0;
    static  u8 clean_flag=0;

    static  u8 temp=0;
 

	OLED_ShowString(1,1,"text1:");
	OLED_ShowString(2,1,"text2:");
	OLED_ShowString(3,1,"text3:");
     OLED_ShowNum(4, 1, flag, 1);         
    
    if(key_shake)return(view_flag);
    key_shake = 1;//消抖标志  
    
    OLED_ShowNum(4, 5, flag, 1);      

    //三行代码得到按下或者弹起瞬间的值  
    Key_Down = key.key_num & (Key_Old ^ key.key_num);   //按下为按键值，其它为0
    Key_Up  = ~key.key_num & (Key_Old ^ key.key_num);  //松手为抬起前的按键值，其他为0
    Key_Old = key.key_num; 
        

//    OLED_ShowNum(4, 8, KeyState, 1);
//    OLED_ShowString(4,1,"key:");            
//    OLED_ShowNum(4, 5, key.key_num, 1);	         
//        
//        //	OLED_ShowString(1,1,"one:");
//	OLED_ShowString(2,1,"two:");
//	OLED_ShowString(3,1,"three:");

//    OLED_ShowNum(4, 8, flag, 1);
//    OLED_ShowString(4,1,"key:");            
//    OLED_ShowNum(4, 5, key.key_num, 1);	
    
    
    
    
    
    
    // Key_Down表示按下这个动作，Key_UP表示松开这个动作

if(Key_Down)
  {
      
   keyPressFlag = 1;//进程到了现在就认定为按下了按键，开始计按下时间
    switch(key.key_num)
    {
        case 1:
            KeyState=1;
            key_press_time=0;
        	flag++;
			if(flag==4) flag=1;	
//            view+=1;
//            OLED_Clear();            
            clean_flag=1;
            press_time=key_press_time;//储存一下时间
        
        break;
        case 2:
            KeyState=2;
            if(clean_flag==1)
            {
            clean_flag=0;
            OLED_Clear();
            }
            view=0;
            key_press_time=0;
            beep_control(1);
                
            press_time=key_press_time;
            

        break;
    
        case 3:
            KeyState=3;
            key.key_num=0;  //回到没有按下的状态
            key_press_time=0;
            beep_control(4);
            view+=1;
            OLED_Clear();
        
        
            view_flag=flag;
        
        switch(view_flag){
    case 1:
        OLED_Clear();
        OLED_ShowString(2,1,"key:");            
        OLED_ShowNum(2, 5, key.key_num, 1);	  
    break;    

    case 2:
        OLED_Clear();
		OLED_ShowNum(4,10,key_press_time,4);//记录按压时长         
    
    break;
    
    case 3:
         OLED_Clear();
         OLED_ShowString(2,1,"return:");
    if(key.key_num==3)
    goto one;
    break;    
    
    }

           return(view_flag);
        
        break;

        case 4:

            key.key_num=0;  //回到没有按下的状态
            key_press_time=0;
            
            beep_control(5);            
            
        break;        

        case 5:

            key.key_num=0;  //回到没有按下的状态
            key_press_time=0;

        break;        

        case 6:

            key.key_num=0;  //回到没有按下的状态
            key_press_time=0;

        break; 
//        default:
//            keyState=0;
//            keyPressFlag=0; //没有按键按下keyPressFlag置0，关闭计时
//            break;        
//        
        
        
      }
  }
  one:
switch(flag)      //光标移动
{
    case 1:
    {	
        OLED_ShowString(1,15,"*");
        OLED_ShowString(2,15," ");
        OLED_ShowString(3,15," ");
    }break;
    case 2:
    {
        OLED_ShowString(1,15," ");
        OLED_ShowString(2,15,"*");				
        OLED_ShowString(3,15," ");
    }break;
    case 3:
    {
        OLED_ShowString(1,15," ");
        OLED_ShowString(2,15," ");
        OLED_ShowString(3,15,"*");				
    }break;
}










    
//if(Key_Up)
//{
//        keyPressFlag = 0;   // 重置按键按下标志 
//        key.key_num=0;
//        key_press_time=0;   
//        KeyState=0;
//        switch(Key_Up){
//        case 1:
//        if(press_time>=100&&press_time<200)//1s长按
//        {
//            OLED_Clear();
//            key_type=1;
//            text=1;
//        }
//        if(press_time>=200)//2s长按
//        {
//            OLED_Clear();            
//            key_type=2;
//            text=2;
//            
//        }   

//           

//        break;
//        //长按1s处理
//        case 2:
//            KeyState=2;
//            if(clean_flag==1)
//            {
//            clean_flag=0;
//            OLED_Clear();
//            }
//            view=0;
//            key_press_time=0;
//            beep_control(1); 
//        break;

//    
//        }
//}
//     
//    return press_time;
    
}





















