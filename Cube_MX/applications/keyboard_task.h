#ifndef _KEY_BOARD_TASK_H
#define _KEY_BOARD_TASK_H
#include "struct_typedef.h"
#include "main.h"
#define USER_WIRED 0
#define USER_WIREDLESS 1
/*�������ģʽ 
	KEY_BOARD_MODE = 0	����ģʽ 
	KEY_BOARD_MODE = 1	ʹ������ģʽ
	*/
#define KEY_BOARD_MODE 1

void keyboard_task_creat(void);
void keyboard_task(void const *pvParameters);
extern uint8_t sts;
#endif
