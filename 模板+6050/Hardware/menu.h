#ifndef __menu_H_
#define __menu_H_

#include "headfile.h"

typedef struct
{
	unsigned char current;
	unsigned char up;//���Ϸ�������
	unsigned char down;//���·�������
	unsigned char enter;//ȷ��������
	void (*current_operation)();
} key_table;







int menu1(void);



#endif
