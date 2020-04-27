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
