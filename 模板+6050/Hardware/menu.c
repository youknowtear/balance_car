#include "menu.h"
#include "math.h"

u16 press_time;
#define PI 3.14


/**********************************************************

                     所有的界面

**********************************************************/
// 索引，上下翻，确认
key_table table[30]=
{
	//第0层
	{0,0,0,1,(*fun_0)},
	
    //第1层
	{1,4,2, 5,(*fun_a1)},
	{2,1,3, 9,(*fun_b1)},
	{3,2,4,13,(*fun_c1)},		
	{4,3,1, 0,(*fun_d1)},
	
    //第2层
	{5,8,6,17,(*fun_a21)},					
	{6,5,7,18,(*fun_a22)},
	{7,6,8,19,(*fun_a23)},						                	
	{8,7,5, 1,(*fun_a24)},
	
	{ 9,12,10,20,(*fun_b21)},					
	{10, 9,11,21,(*fun_b22)},
	{11,10,12,22,(*fun_b23)},						                	
	{12,11, 9, 2,(*fun_b24)},
	
	{13,16,14,23,(*fun_c21)},					
	{14,13,15,24,(*fun_c22)},				                	
	{15,14,16,25,(*fun_c23)},				                	
	{16,15,13, 3,(*fun_c24)},
	
    //第3层
	{17,17,17,5,(*fun_a31)},			                	
	{18,18,18,6,(*fun_a32)},		                	
	{19,19,19,7,(*fun_a33)},
	
	{20,20,20, 9,(*fun_b31)},				                	
	{21,21,21,10,(*fun_b32)},			                	
	{22,22,22,11,(*fun_b33)},
	
	{23,23,23,13,(*fun_c31)},			                	
	{24,24,24,14,(*fun_c32)},			                	
	{25,25,25,15,(*fun_c33)},								
};



/**********************************************************

                     以下为一级菜单

**********************************************************/
//int menu1()           
//{
//	int flag=1;         //记录你的选择
//	OLED_ShowString(1,1,"text1:");
//	OLED_ShowString(2,1,"text2:");
//	OLED_ShowString(3,1,"text3:");

//	while(1)
//	{
////    OLED_ShowNum(4, 8, KeyState, 1);
////    OLED_ShowString(4,1,"key:");            
////    OLED_ShowNum(4, 5, key.key_num, 1);	         
////        
////        //	OLED_ShowString(1,1,"one:");
////	OLED_ShowString(2,1,"two:");
////	OLED_ShowString(3,1,"three:");

////    OLED_ShowNum(4, 8, flag, 1);
////    OLED_ShowString(4,1,"key:");            
////    OLED_ShowNum(4, 5, key.key_num, 1);	
//        Key_GetNum();  
//        
//       press_time= key_loop();  
//        OLED_ShowNum(4, 2, flag, 1); 
        
        
//        
//        if(key.key_num==1){
//                flag++;
//			if(flag==4) flag=1;
//        }
//        
//        else if(key.key_num==2){
//        
//			OLED_Clear();   //清屏
//			return(flag);   //返回你的选择        
//        
//        }
//        
//        switch( KeyState)
//            {
//            case 1:


//            
//            break;            
//          case 2:
//			OLED_Clear();   //清屏
//          return(flag);
//        break;
//    }
//      
//    
//		switch(flag)      //光标移动
//		{
//			case 1:
//			{	
//                OLED_ShowString(1,15,"*");
//				OLED_ShowString(2,15," ");
//				OLED_ShowString(3,15," ");

//			}break;
//			case 2:
//			{
//				OLED_ShowString(1,15," ");
//				OLED_ShowString(2,15,"*");				
//                OLED_ShowString(3,15," ");
//			}break;
//			case 3:
//			{
//				OLED_ShowString(1,15," ");
//				OLED_ShowString(2,15," ");
//				OLED_ShowString(3,15,"*");				
//			}break;
//		}		
		
//        switch(KeyState){
//        
//            case 1:
//			flag++;
//			if(flag==4) flag=1;			
//             OLED_ShowString(0,0,"*");            
//            
//		break;
//            
//            case 2:
//			OLED_Clear();   //清屏
//			return(flag);   //返回你的选择

//        break;
//    }
//      
//    
//		switch(flag)      //光标移动
//		{
//			case 1:
//			{	
//                OLED_ShowString(1,15,"*");
//				OLED_ShowString(2,15," ");
//				OLED_ShowString(3,15," ");

//			}break;
//			case 2:
//			{
//				OLED_ShowString(1,15," ");
//				OLED_ShowString(2,15,"*");				
//                OLED_ShowString(3,15," ");
//			}break;
//			case 3:
//			{
//				OLED_ShowString(1,15," ");
//				OLED_ShowString(2,15," ");
//				OLED_ShowString(3,15,"*");				
//			}break;
//		}		
		
//	}
//}


/**********************************************************

                     以下为二级菜单

**********************************************************/

//********************* 手势识别部分 **********************
//int menu2_gesture()
//{
//	int gesture;
//	OLED_ShowStr(0,0,"Your gesture:",2);
//	while(1)
//	{
//		gesture = Gesture_recog(); //得到手势识别结果
//		
//		//1.屏幕显示结果:
//		switch(gesture)                 
//		{
//			case 1: OLED_ShowStr(45,3,"Up       ",2);break; //向上
//			case 2: OLED_ShowStr(45,3,"Dowm     ",2);break; //向下
//			case 3: OLED_ShowStr(45,3,"Left     ",2);break; //向左
//			case 4: OLED_ShowStr(45,3,"Right    ",2);break; //向右
//			case 5: OLED_ShowStr(45,3,"Forward  ",2);break; //向前
//			case 6: OLED_ShowStr(45,3,"Backward ",2);break; //向后
//			case 7: OLED_ShowStr(45,3,"Clockwise",2);break; //顺时针
//			case 8: OLED_ShowStr(45,3,"AntiClock",2);break; //逆时针
//			case 9: OLED_ShowStr(45,3,"Wave     ",2);break; //挥动	
//		}
//		delay_ms(150);
//		OLED_ShowStr(45,3,"         ",2);
//		
//		//2.led显示结果:
//		if(gesture==3) GPIO_SetBits(GPIOA,GPIO_Pin_8);    //关灯
//		if(gesture==4) GPIO_ResetBits(GPIOA,GPIO_Pin_8);  //开灯
//		
//		//3.串口发送
//		if(gesture)		
//		switch(gesture)                 
//		{
//			case 1: printf("Up ");break;                    //向上
//			case 2: printf("Dowm ");break;                  //向下
//			case 3: printf("Left ");break; 									//向左
//			case 4: printf("Right ");break; 								//向右
//			case 5: printf("Forward ");break;								//向前
//			case 6: printf("Backward ");break; 							//向后
//			case 7: printf("Clockwise ");break; 						//顺时针
//			case 8: printf("AntiClock ");break; 						//逆时针
//			case 9: printf("Wave ");break; 									//挥动	
//		}		
//		
//		
//		if(key_up==1)//***返回***
//		{
//			delay_ms(10);	    //防抖
//			while(key_up==1); //按下后不松手，则停在这
//			delay_ms(10);	    //防抖
//			OLED_Clear();
//			return 0;
//		}
//	}
//}

















