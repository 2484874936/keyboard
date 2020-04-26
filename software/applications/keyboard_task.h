#ifndef _KEY_BOARD_TASK_H
#define _KEY_BOARD_TASK_H
#include "struct_typedef.h"
#include "main.h"
#define USER_WIRED 0
#define USER_WIREDLESS 1
/*定义键盘模式 
	KEY_BOARD_MODE = 0	有线模式 
	KEY_BOARD_MODE = 1	使用无线模式
	*/
#define KEY_BOARD_MODE 1

void keyboard_task_creat(void);
void keyboard_task(void const *pvParameters);
extern uint8_t sts;
#endif
