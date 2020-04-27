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
#include "bsp_bulehid.h"
#include "usart.h"
#include "cmsis_os.h"
#include "keyboard_cfg.h"
/*
BYTE1 0x0C 固定值（包长度）
BYTE2 0x00 固定值
BYTE3 0xA1 固定值
BYTE4 0x01 固定值
BYTE5 变动值（ALT、SHIFT、CTRL、GUI 按键状态指示）
BYTE6 0x00 固定值
BYTE7 变动值（普通按键编码）
BYTE8 变动值（普通按键编码）
BYTE9 变动值（普通按键编码）
BYTE10 变动值（普通按键编码）
BYTE11 变动值（普通按键编码）
BYTE12 变动值（普通按键编码）
*/
uint8_t bule_keyboard[12]={0x0C,0x00,0xA1,0x01,0,0,0,0,0,0,0,0};
//尽量不要使用这种方式来设置，我是身边没有USB转TTL，没办法。
void mx_bulehid_init(void)
{	
//	osDelay(100);
//	printf("AT+BAUD=115200\r\n");
//	osDelay(100);
//	printf("AT+NAME=MX_Blue_Keyboard\r\n");
//	osDelay(100);
//	printf("AT+AUTH=1\r\n");
//	osDelay(100);
// 	printf("AT+NAME?\r\n");
//	osDelay(100);
//	printf("AT+PSWD=20200407\r\n");
//	osDelay(100);
//	printf("AT+DEFAULT\r\n");

}
void bule_keyboard_updata(uint8_t* pTx_bule)
{
	/*每个按键按下对应一个按键抬起，特殊键除外*/
	bule_keyboard[0] =  0x0C;//固定值
	bule_keyboard[1] =  0x00;//固定值
	bule_keyboard[2] =  0xA1;//固定值
	bule_keyboard[3] =  0x01;//固定值
	bule_keyboard[4] =  pTx_bule[0];//变动值（ALT、SHIFT、CTRL、GUI 按键状态指示）
	bule_keyboard[5] =  		  0;//固定值
	bule_keyboard[6] =  pTx_bule[2];//变动值1
	bule_keyboard[7] =  pTx_bule[3];//变动值2
	bule_keyboard[8] =  pTx_bule[4];//变动值3
	bule_keyboard[9] =  pTx_bule[5];//变动值4
	bule_keyboard[10] = pTx_bule[6];//变动值5
	bule_keyboard[11] = pTx_bule[7];//变动值6
	HAL_UART_Transmit(&huart4,bule_keyboard,12,100);
//	bule_keyboard[4]=0;//防止滞键提示
	bule_keyboard[6]=0;
	bule_keyboard[7]=0;
	bule_keyboard[8]=0;
	bule_keyboard[9]=0;
	bule_keyboard[10]=0;
	bule_keyboard[11]=0;
	HAL_UART_Transmit(&huart4,bule_keyboard,12,100);
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
//	if(huart==&huart4)
//	{
//		UART4_BUFF[USART_LEN] = huart4.Instance->DR;
//		USART_LEN++;
//	}
}