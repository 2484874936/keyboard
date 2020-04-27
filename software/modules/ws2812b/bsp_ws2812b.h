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
#ifndef _BSP_WS2812B_H
#define _BSP_WS2812B_H
#include "struct_typedef.h"

#define MAX_WS2812B_NUM 35
#define WS2812B_R_OFFSET 1
#define WS2812B_G_OFFSET 2
#define WS2812B_B_OFFSET 0
typedef enum
{
	L_DIN_1=1,
	L_DIN_2,
	L_DIN_3,
}din_ch;
typedef union
{
    uint32_t WS2812B_RGB;
    uint8_t RGB_OFFSET[4];
} ws2812b_led;
typedef struct
{
    uint8_t id;
    uint8_t name;
    din_ch  id_ch;
	uint8_t id_ch_id;//ch中所在id
    uint8_t id_column;//所在列
    uint8_t id_line;//所在行
    ws2812b_led rgb_set;
} keyboard_rgb;

void mx_ws2812b_init(keyboard_rgb *board_rgb_led);
void mx_ws2812b_low(uint8_t ch);
void mx_ws2812b_high(uint8_t ch);
void mx_ws2812b_reset(void);
void ws2812b_id_cfg(keyboard_rgb *board_rgb_led);
void ws2812b_IRQ(void);

#endif
