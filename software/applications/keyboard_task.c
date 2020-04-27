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
