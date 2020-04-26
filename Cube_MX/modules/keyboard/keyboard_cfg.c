#include "keyboard_cfg.h"
/*
键盘发送给PC的数据每次8个字节
				BYTE0 BYTE1 BYTE2 BYTE3 BYTE4 BYTE5 BYTE6 BYTE7
				定义分别是：
				BYTE0 --
							 |--bit0:   Left Control是否按下，按下为1
							 |--bit1:   Left Shift  是否按下，按下为1
							 |--bit2:   Left Alt    是否按下，按下为1
							 |--bit3:   Left GUI    是否按下，按下为1
							 |--bit4:   Right Control是否按下，按下为1
							 |--bit5:   Right Shift 是否按下，按下为1
							 |--bit6:   Right Alt   是否按下，按下为1
							 |--bit7:   Right GUI   是否按下，按下为1
				BYTE1 -- 暂不清楚，有的地方说是保留位
				BYTE2--BYTE7 -- 这六个为普通按键
				键盘经过测试。
*/
Byte0_Offset Byte0;//枚举成员
keyboard_hid hid_info;

void keypad_calc(void)
{
	uint8_t i;
	for(i=0;i<MAX_KEYPAD_PAGE;i++)
	{
		//如果按键已经按下,且未使用,堆栈区未满
		if( hid_info.ord_key[i].press_it==1&&
			hid_info.ord_key[i].used_it==0 &&
			hid_info.stack_pointer<STACK_POINT_LENGTH)
		{
			hid_info.keypad_page[hid_info.stack_pointer] = i;
			hid_info.ord_key[i].used_it = 1;//标记此按键已使用
			hid_info.stack_pointer++;
		}
	}
}
void key_clear(void)
{
	uint8_t i,used_key;
	for(i=0;i<STACK_POINT_LENGTH;i++)
	{
//		hid_info.ord_key[hid_info.keypad_page[i]].press_it=0;//此标志完全由按键扫描结果决定，从此处不处理
		hid_info.ord_key[hid_info.keypad_page[i]].used_it=0;
		hid_info.keypad_page[i]=0;	
	}
	hid_info.stack_pointer = 0;
}
void keypad_Update(uint8_t *pTxbuf)
{
	uint8_t i;
	for(i=0;i<8;i++)pTxbuf[i]=0;
	keypad_calc();
	/*特殊按键特殊处理*/
    if(hid_info.byte0_off.Left_Control == 1)  pTxbuf[0]|= 1<<Left_Control;
    if(hid_info.byte0_off.Left_Shift == 1)	  pTxbuf[0]|= 1<<Left_Shift;
    if(hid_info.byte0_off.Left_Alt == 1)	  pTxbuf[0]|= 1<<Left_Alt;
    if(hid_info.byte0_off.Left_GUI == 1)	  pTxbuf[0]|= 1<<Left_GUI;
    if(hid_info.byte0_off.Right_Control == 1) pTxbuf[0]|= 1<<Right_Control;
    if(hid_info.byte0_off.Right_Shift == 1)	  pTxbuf[0]|= 1<<Right_Shift;
    if(hid_info.byte0_off.Right_Alt == 1)	  pTxbuf[0]|= 1<<Right_Alt;
    if(hid_info.byte0_off.Right_GUI == 1)	  pTxbuf[0]|= 1<<Right_GUI;
    pTxbuf[1]=0;
//	BYTE2--BYTE7 普通按键
	pTxbuf[2]=hid_info.keypad_page[0];        
	pTxbuf[3]=hid_info.keypad_page[1];
	pTxbuf[4]=hid_info.keypad_page[2];
	pTxbuf[5]=hid_info.keypad_page[3];
	pTxbuf[6]=hid_info.keypad_page[4];
	pTxbuf[7]=hid_info.keypad_page[5];
	key_clear();
}
