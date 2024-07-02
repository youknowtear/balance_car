#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MPU6050.h"
#include "headfile.h"

int flag=1;         //记录你的选择  

uint8_t ID;								//定义用于存放ID号的变量
int16_t AX, AY, AZ, GX, GY, GZ;			//定义用于存放各个数据的变量



int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	MPU6050_Init();		//MPU6050初始化
	Key_Init();
    Timer3_Init();
   uint8_t key_sta;
    u16 press_time1;
    int menu2;
    
	while (1)
	{
        
        Key_GetNum();
	

        MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);		//获取MPU6050的数据
        
       press_time1= key_loop(); 

//        menu2 = menu1();    
        
//    OLED_ShowNum(4, 1, flag, 1);      
   OLED_ShowNum(4, 7, press_time1, 1);          
        
//    if(view){
//        OLED_ShowString(1,1,"type:");
//        OLED_ShowNum(1, 6, key_type, 1); 

//        OLED_ShowString(2,1,"key:");            
//        OLED_ShowNum(2, 5, key.key_num, 1);	 
//                 
//        OLED_ShowNum(2, 8, KeyState, 1);
//        
//        OLED_ShowString(3,1,"value:");
//        OLED_ShowNum(3, 7, text, 3);
//        
//		OLED_ShowNum(4,2,key_press_time,5);//记录按压时长
////        OLED_ShowSignedNum(4,2,timerms,5);    
//		OLED_ShowNum(4,8,press_time,4);//记录按压时长    
//    
//    
//    }
    
    
    
    
//        if(view==0)
//        {
//        OLED_ShowString(1,1,"view:");
//        OLED_ShowSignedNum(1, 5, view, 1);	             
//        OLED_ShowString(1,1,"key:");            
//        OLED_ShowSignedNum(2, 5, key.key_num, 1);	 
//            
//		OLED_ShowNum(3,2,key_press_time,5);//记录按压时长
//        OLED_ShowSignedNum(4,2,timerms,5);

//        }
        
//        if(view==1)
//		{
//            
//        OLED_ShowString(1,1,"view:");
//        OLED_ShowSignedNum(1, 5, view, 1);	            
//        OLED_ShowString(1,7,"sta:");
//        OLED_ShowSignedNum(1, 11, key_type, 1);           
//		OLED_ShowSignedNum(2, 1, AX, 5);					//OLED显示数据
//		OLED_ShowSignedNum(3, 1, AY, 5);
//		OLED_ShowSignedNum(4, 1, AZ, 5);
//		OLED_ShowSignedNum(2, 8, GX, 5);
//		OLED_ShowSignedNum(3, 8, GY, 5);
//		OLED_ShowSignedNum(4, 8, GZ, 5);
//        }
//        if(view==2)
//		{
//        OLED_ShowString(1,1,"view:");
//        OLED_ShowSignedNum(1, 5, view, 1);	            
//        OLED_ShowString(1,7,"sta:");
//        OLED_ShowSignedNum(1, 11, key_type, 1);            
//		OLED_ShowSignedNum(2, 1, text, 5);					//OLED显示数据

//        }
        
        
        
	}
}
