/*MIT License

Copyright (c) 2020 SEASKY-Master

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "key_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "main.h"
#include "keyboard_cfg.h"

#include "bsp_key.h"
#include "bsp_bulehid.h"


key_info_t key_info;

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
			osDelay(READ_DELAY_TIME);
			key_scan_gpio_read(&key_info,i);
		}
		key_scan_updata(&key_info);
	}
}

