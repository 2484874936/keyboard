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
#ifndef _BSP_KEY_H
#define _BSP_KEY_H
#include "struct_typedef.h"
#include "stm32f4xx_hal.h"
#include "keyboard_cfg.h"

#define MAX_SEG 7
#define MAX_POS 14
#define MAX_KEY 87

#define PRESS_LEVEL 1 //���尴������ʱ�ĵ�ƽ

#define READ_DELAY_TIME 1	//�����л�ɨ��IO�����ʱʱ�� 
#define READ_TIME 7         //MAX_SEG*READ_DELAY_TIME

#define TIME_CYCLE  7	    //MAX_SEG*READ_DELAY_TIME ��λms

#define TIME_RESTER_COUNT  2	//���尴����λʱ�䣬һ����˵����������ñȰ������¿�

#define TIME_PRESS_COUNT   3    //ʵ��ʱ�� TIME_CYCLE*TIME_P_COUNT (��λms)ȷ��Ϊ�̰�ʱ��
#define TIME_PRESS_L_COUNT 100	//ʵ��ʱ�� TIME_CYCLE*TIME_L_COUNT (��λms)ȷ��Ϊ����ʱ��
#define TIME_MAX_COUNT     300  //���尴�������ʱ��

#define KEY_NO_USER 255

/*�궨�����ⰴ�� ����if�жϵ�ʹ��*/
#define KEY_LEFT_SHIFT 54
#define KEY_RIGHT_SHIFT 65
#define KEY_LEFT_CONTROL 66
#define KEY_LEFT_WIN 67
#define KEY_LEFT_ALT 68
#define KEY_RIGHT_ALT 70
#define KEY_RIGHT_WIN 71
#define KEY_RIGHT_CONTROL 73

typedef enum
{
    KEY_UPSPRING,    //��������
    KEY_PRESS,		 //��������
    KEY_PRESS_L_TIME,//��������
} key_states;

typedef struct
{
    key_states states;	//����״̬
    uint16_t time_count;//��������ʱ��
    uint8_t rester_time_count;//������λʱ��
} key_time_info;

typedef struct
{
    GPIO_TypeDef* gpio;
    uint16_t	gpio_pin;
} key_gpio;
typedef struct
{
    keypad_page_t key_char;
    key_time_info press_it;

} key_press;
typedef struct
{
    key_gpio key_seg[MAX_SEG];
    key_gpio key_pos[MAX_POS];
    uint8_t key_is_press_seg[MAX_SEG][MAX_POS];//�������У��ж��Ƿ���
    key_press key_is_press[MAX_KEY]; 	  //���µ�ID
    keyboard_cfg keyboard;
} key_info_t;

void mx_key_init(key_info_t *key_cfg);
void key_scan_gpio_set(key_info_t *key_cfg,uint8_t seg);
void key_scan_gpio_read(key_info_t *key_cfg,uint8_t seg);

void key_scan_updata(key_info_t *key_cfg);
void key_update(uint8_t *pTxbuf,key_info_t *key_cfg);
#endif
