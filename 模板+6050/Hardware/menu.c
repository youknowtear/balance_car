#include "menu.h"
#include "math.h"

u16 press_time;
#define PI 3.14


/**********************************************************

                     ���еĽ���

**********************************************************/
// ���������·���ȷ��
key_table table[30]=
{
	//��0��
	{0,0,0,1,(*fun_0)},
	
    //��1��
	{1,4,2, 5,(*fun_a1)},
	{2,1,3, 9,(*fun_b1)},
	{3,2,4,13,(*fun_c1)},		
	{4,3,1, 0,(*fun_d1)},
	
    //��2��
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
	
    //��3��
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

                     ����Ϊһ���˵�

**********************************************************/
//int menu1()           
//{
//	int flag=1;         //��¼���ѡ��
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
//			OLED_Clear();   //����
//			return(flag);   //�������ѡ��        
//        
//        }
//        
//        switch( KeyState)
//            {
//            case 1:


//            
//            break;            
//          case 2:
//			OLED_Clear();   //����
//          return(flag);
//        break;
//    }
//      
//    
//		switch(flag)      //����ƶ�
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
//			OLED_Clear();   //����
//			return(flag);   //�������ѡ��

//        break;
//    }
//      
//    
//		switch(flag)      //����ƶ�
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

                     ����Ϊ�����˵�

**********************************************************/

//********************* ����ʶ�𲿷� **********************
//int menu2_gesture()
//{
//	int gesture;
//	OLED_ShowStr(0,0,"Your gesture:",2);
//	while(1)
//	{
//		gesture = Gesture_recog(); //�õ�����ʶ����
//		
//		//1.��Ļ��ʾ���:
//		switch(gesture)                 
//		{
//			case 1: OLED_ShowStr(45,3,"Up       ",2);break; //����
//			case 2: OLED_ShowStr(45,3,"Dowm     ",2);break; //����
//			case 3: OLED_ShowStr(45,3,"Left     ",2);break; //����
//			case 4: OLED_ShowStr(45,3,"Right    ",2);break; //����
//			case 5: OLED_ShowStr(45,3,"Forward  ",2);break; //��ǰ
//			case 6: OLED_ShowStr(45,3,"Backward ",2);break; //���
//			case 7: OLED_ShowStr(45,3,"Clockwise",2);break; //˳ʱ��
//			case 8: OLED_ShowStr(45,3,"AntiClock",2);break; //��ʱ��
//			case 9: OLED_ShowStr(45,3,"Wave     ",2);break; //�Ӷ�	
//		}
//		delay_ms(150);
//		OLED_ShowStr(45,3,"         ",2);
//		
//		//2.led��ʾ���:
//		if(gesture==3) GPIO_SetBits(GPIOA,GPIO_Pin_8);    //�ص�
//		if(gesture==4) GPIO_ResetBits(GPIOA,GPIO_Pin_8);  //����
//		
//		//3.���ڷ���
//		if(gesture)		
//		switch(gesture)                 
//		{
//			case 1: printf("Up ");break;                    //����
//			case 2: printf("Dowm ");break;                  //����
//			case 3: printf("Left ");break; 									//����
//			case 4: printf("Right ");break; 								//����
//			case 5: printf("Forward ");break;								//��ǰ
//			case 6: printf("Backward ");break; 							//���
//			case 7: printf("Clockwise ");break; 						//˳ʱ��
//			case 8: printf("AntiClock ");break; 						//��ʱ��
//			case 9: printf("Wave ");break; 									//�Ӷ�	
//		}		
//		
//		
//		if(key_up==1)//***����***
//		{
//			delay_ms(10);	    //����
//			while(key_up==1); //���º����֣���ͣ����
//			delay_ms(10);	    //����
//			OLED_Clear();
//			return 0;
//		}
//	}
//}

















