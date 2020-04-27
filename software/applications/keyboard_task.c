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
#include "keyboard_task.h"
#include "usb_device.h"
#include "usbd_hid.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "keyboard_cfg.h"
#include "bsp_bulehid.h"

#include "key_task.h"
#include "bsp_key.h"
extern USBD_HandleTypeDef hUsbDeviceFS;
extern key_info_t key_info;

uint8_t Tx_buffer[8]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

uint8_t sts;
osThreadId keyboard_TaskHandle;
void keyboard_task_creat(void)
{
    osThreadDef(keyboard_task_T,keyboard_task,osPriorityRealtime,0,128);
    keyboard_TaskHandle = osThreadCreate(osThread(keyboard_task_T), NULL);
}
void keyboard_task(void const *pvParameters)
{
    while(1)
        {
#if KEY_BOARD_MODE==USER_WIRED
			key_update(Tx_buffer,&key_info);
            USBD_HID_SendReport(&hUsbDeviceFS,Tx_buffer,8);//·¢ËÍ±¨ÎÄ
			
#elif KEY_BOARD_MODE==USER_WIREDLESS
            key_update(Tx_buffer,&key_info);
		    bule_keyboard_updata(Tx_buffer);
#endif
            osDelay(20);
        }
}

/*

*/
