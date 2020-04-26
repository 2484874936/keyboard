#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "oled_task.h"
#include "bsp_adc.h"
#include "bsp_gui.h"
#include "bsp_oled.h"

oled_show oled_info;

osThreadId Oled_TaskHandle;
void oled_task_creat(void)
{
    osThreadDef(oled_task,oled_scan_task,osPriorityRealtime,0,128);
    Oled_TaskHandle = osThreadCreate(osThread(oled_task), NULL);
}
void oled_scan_task(void const *pvParameters)
{
	OLED_Clear();
	while(1)
	{
		interface_main();
		oled_info.temp = get_temprate();
		osDelay(100);
	}
}
