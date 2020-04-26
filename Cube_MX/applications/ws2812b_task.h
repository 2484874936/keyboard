#ifndef _WS2812B_TASK_H
#define _WS2812B_TASK_H
#include "tim.h"
#include "struct_typedef.h"
#include "bsp_ws2812b.h"

typedef struct
{
	ws2812b_led mx_ws2812b_one[27];
}keyboard_led;
void ws2812b_task_creat(void);
void ws2812b_task(void const *pvParameters);

extern ws2812b_led ws2812b_data;

#endif
