#ifndef _OLED_TASK_H
#define _OLED_TASK_H
typedef struct
{
	float temp;
	float oled_button_ad;
}oled_show;

void oled_task_creat(void);
void oled_scan_task(void const *pvParameters);

#endif
