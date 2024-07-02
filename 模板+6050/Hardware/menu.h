#ifndef __menu_H_
#define __menu_H_

#include "headfile.h"

typedef struct
{
	unsigned char current;
	unsigned char up;//向上翻索引号
	unsigned char down;//向下翻索引号
	unsigned char enter;//确认索引号
	void (*current_operation)();
} key_table;







int menu1(void);



#endif
