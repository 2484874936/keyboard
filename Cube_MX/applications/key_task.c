#include "key_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "main.h"
#include "keyboard_cfg.h"

#include "bsp_key.h"



key_info_t key_info;
uint8_t Tx_buffer[8]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
osThreadId key_sacn_TaskHandle;
void key_task_creat(void)
{
    osThreadDef(key_task,key_scan_task,osPriorityRealtime,0,128);
    key_sacn_TaskHandle = osThreadCreate(osThread(key_task), NULL);
}
void key_scan_task(void const *pvParameters)
{
	static uint8_t i=1;
	mx_key_init(&key_info);
	while(1)
	{
		for(i=1;i<=MAX_SEG;i++)
		{
			key_scan_gpio_set(&key_info,i);
			osDelay(5);
			key_scan_gpio_read(&key_info,i);
		}
		key_scan_updata(&key_info);
		key_update(Tx_buffer,&key_info);
		osDelay(5);
	}
}

