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
BYTE1 0x0C �̶�ֵ�������ȣ�
BYTE2 0x00 �̶�ֵ
BYTE3 0xA1 �̶�ֵ
BYTE4 0x01 �̶�ֵ
BYTE5 �䶯ֵ��ALT��SHIFT��CTRL��GUI ����״ָ̬ʾ��
BYTE6 0x00 �̶�ֵ
BYTE7 �䶯ֵ����ͨ�������룩
BYTE8 �䶯ֵ����ͨ�������룩
BYTE9 �䶯ֵ����ͨ�������룩
BYTE10 �䶯ֵ����ͨ�������룩
BYTE11 �䶯ֵ����ͨ�������룩
BYTE12 �䶯ֵ����ͨ�������룩
*/
uint8_t bule_keyboard[12]={0x0C,0x00,0xA1,0x01,0,0,0,0,0,0,0,0};
//������Ҫʹ�����ַ�ʽ�����ã��������û��USBתTTL��û�취��
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
	/*ÿ���������¶�Ӧһ������̧�����������*/
	bule_keyboard[0] =  0x0C;//�̶�ֵ
	bule_keyboard[1] =  0x00;//�̶�ֵ
	bule_keyboard[2] =  0xA1;//�̶�ֵ
	bule_keyboard[3] =  0x01;//�̶�ֵ
	bule_keyboard[4] =  pTx_bule[0];//�䶯ֵ��ALT��SHIFT��CTRL��GUI ����״ָ̬ʾ��
	bule_keyboard[5] =  		  0;//�̶�ֵ
	bule_keyboard[6] =  pTx_bule[2];//�䶯ֵ1
	bule_keyboard[7] =  pTx_bule[3];//�䶯ֵ2
	bule_keyboard[8] =  pTx_bule[4];//�䶯ֵ3
	bule_keyboard[9] =  pTx_bule[5];//�䶯ֵ4
	bule_keyboard[10] = pTx_bule[6];//�䶯ֵ5
	bule_keyboard[11] = pTx_bule[7];//�䶯ֵ6
	HAL_UART_Transmit(&huart4,bule_keyboard,12,100);
//	bule_keyboard[4]=0;//��ֹ�ͼ���ʾ
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