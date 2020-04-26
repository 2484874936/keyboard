#ifndef _BSP_BULEHID_H
#define _BSP_BULEHID_H
#include "stm32f4xx_hal.h"

#define ALT_SHIFT_CTRL_GUI 4
#define Variable_value1	6
#define Variable_value2	7
#define Variable_value3	8
#define Variable_value4	9
#define Variable_value5	10
#define Variable_value6	11
void mx_bulehid_init(void);
void bule_keyboard_updata(uint8_t* pTx_bule);



#endif
