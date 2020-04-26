#ifndef _BSP_KEY_H
#define _BSP_KEY_H
#include "struct_typedef.h"
#include "stm32f4xx_hal.h"
#include "keyboard_cfg.h"
#define MAX_SEG 7
#define MAX_POS 14
#define MAX_KEY 87

#define KEY_NO_USER 255

#define KEY_LEFT_SHIFT 54
#define KEY_RIGHT_SHIFT 65
#define KEY_LEFT_CONTROL 66
#define KEY_LEFT_WIN 67
#define KEY_LEFT_ALT 68
#define KEY_RIGHT_ALT 70
#define KEY_RIGHT_WIN 71
#define KEY_RIGHT_CONTROL 73

typedef struct
{
	GPIO_TypeDef* gpio;
	uint16_t	gpio_pin;
}key_gpio;
typedef struct
{
	keypad_page_t key_char;
	uint8_t press_it:1;	
}key_press;
typedef struct
{
	key_gpio key_seg[MAX_SEG];
	key_gpio key_pos[MAX_POS];
	uint8_t key_is_press_seg[MAX_SEG][MAX_POS];//�������У��ж��Ƿ���
	key_press key_is_press[MAX_KEY]; 	  //���µ�ID
	keyboard_cfg keyboard;
}key_info_t;
void mx_key_init(key_info_t *key_cfg);
void key_scan_gpio_set(key_info_t *key_cfg,uint8_t seg);
void key_scan_gpio_read(key_info_t *key_cfg,uint8_t seg);

void key_scan(key_info_t *key_cfg,uint8_t seg);
void key_scan_updata(key_info_t *key_cfg);
void key_info_get(key_info_t *key_cfg);
void key_update(uint8_t *pTxbuf,key_info_t *key_cfg);
#endif
