#ifndef _KEYBOARD_CFG_H
#define _KEYBOARD_CFG_H
#include "struct_typedef.h"
#define MAX_KEYPAD_PAGE 104
#define STACK_POINT_LENGTH 6
typedef enum
{
    Key_board_Null = 0,
    Keyboard_a =4,// Keyboard a and A
    Keyboard_b=5,// Keyboard b and B
    Keyboard_c=6,// Keyboard c and C
    Keyboard_d=7,// Keyboard d and D
    Keyboard_e=8,// Keyboard e and E
    Keyboard_f=9,// Keyboard f and F
    Keyboard_g=10,// Keyboard g and G
    Keyboard_h=11,// Keyboard h and H
    Keyboard_i=12,// Keyboard i and I
    Keyboard_j=13,// Keyboard j and J
    Keyboard_k=14,// Keyboard k and K
    Keyboard_l=15,// Keyboard l and L
    Keyboard_m=16,// Keyboard m and M
    Keyboard_n=17,// Keyboard n and N
    Keyboard_o=18,// Keyboard o and O
    Keyboard_p=19,// Keyboard p and P
    Keyboard_q=20,// Keyboard q and Q
    Keyboard_r=21,// Keyboard r and R
    Keyboard_s=22,// Keyboard s and S
    Keyboard_t=23,// Keyboard t and T
    Keyboard_u=24,// Keyboard u and U
    Keyboard_v=25,// Keyboard v and V
    Keyboard_w=26,// Keyboard w and W
    Keyboard_x=27,// Keyboard x and X
    Keyboard_y=28,// Keyboard y and Y
    Keyboard_z=29,// Keyboard z and Z
    Keyboard_1=30,// Keyboard 1 and !
    Keyboard_2=31,// Keyboard 2 and @
    Keyboard_3=32,// Keyboard 3 and #
    Keyboard_4=33,// Keyboard 4 and $
    Keyboard_5=34,// Keyboard 5 and %
    Keyboard_6=35,// Keyboard 6 and ^
    Keyboard_7=36,// Keyboard 7 and &
    Keyboard_8=37,// Keyboard 8 and *
    Keyboard_9=38,// Keyboard 9 and (
    Keyboard_0=39,// Keyboard 0 and )
    Keyboard_ENTER=40,// Keyboard ENTER 
    Keyboard_ESCAPE=41,// Keyboard ESCAPE
    Keyboard_Backspace=42,// Keyboard Backspace
    Keyboard_Tab=43,// Keyboard Tab
    Keyboard_KongGe=44,// Keyboard Spacebar
    Keyboard_JianHao=45,// Keyboard - and _(underscore)
    Keyboard_DengHao=46,// Keyboard = and +
    Keyboard_ZuoZhongKuoHao=47,// Keyboard [ and {
    Keyboard_YouZhongKuoHao=48,// Keyboard ] and }
    Keyboard_FanXieGang= 49,// Keyboard \ and |
    Keyboard_FenHao=51,// Keyboard ; and :
    Keyboard_DanYinHao= 52,// Keyboard ‘ and “
    Keyboard_BoLangXian= 53,// Keyboard `(Grave Accent) and ~(Tilde)
    Keyboard_Douhao=54,// Keyboard, and <
    Keyboard_JuHao=55,// Keyboard . and >
    Keyboard_XieGang_WenHao=56,// Keyboard / and ?
    Keyboard_CapsLock=57,// Keyboard Caps Lock
    Keyboard_F1=58,// Keyboard F1
    Keyboard_F2=59,// Keyboard F2
    Keyboard_F3=60,// Keyboard F3
    Keyboard_F4=61,// Keyboard F4
    Keyboard_F5=62,// Keyboard F5
    Keyboard_F6=63,// Keyboard F6
    Keyboard_F7=64,// Keyboard F7
    Keyboard_F8=65,// Keyboard F8
    Keyboard_F9=66,// Keyboard F9
    Keyboard_F10= 67,// Keyboard F10
    Keyboard_F11= 68,// Keyboard F11
    Keyboard_F12= 69,// Keyboard F12
    Keyboard_PrintScreen=70,// Keyboard PrintScreen
    Keyboard_ScrollLock= 71,// Keyboard Scroll Lock
    Keyboard_Pause=72,// Keyboard Pause
    Keyboard_Insert=73,// Keyboard Insert
    Keyboard_Home= 74,// Keyboard Home
    Keyboard_PageUp=75,// Keyboard PageUp
    Keyboard_Delete=76,// Keyboard Delete
    Keyboard_End=77,// Keyboard End
    Keyboard_PageDown=78,// Keyboard PageDown
    Keyboard_RightArrow=79,// Keyboard RightArrow
    Keyboard_LeftArrow=80,// Keyboard LeftArrow
    Keyboard_DownArrow= 81,// Keyboard DownArrow
    Keyboard_UpArrow=82,// Keyboard UpArrow
    Keypad_NumLock=83,// Keypad Num Lock and Clear
    Keypad_ChuHao=84,// Keypad /
    Keypad_ChengHao=85,// Keypad *
    Keypad_JianHao=86,// Keypad -
    Keypad_JiaHao=87,// Keypad +
    Keypad_ENTER=88,// Keypad ENTER
    Keypad_1_and_End=89,// Keypad 1 and End
    Keypad_2_and_DownArrow=90,// Keypad 2 and Down Arrow
    Keypad_3_and_PageDn= 91,// Keypad 3 and PageDn
    Keypad_4_and_LeftArrow=92,// Keypad 4 and Left Arrow
    Keypad_5=93,			// Keypad 5
    Keypad_6_and_RightArrow=94,// Keypad 6 and Right Arrow
    Keypad_7_and_Home=95,// Keypad 7 and Home
    Keypad_8_and_UpArrow=96,// Keypad 8 and Up Arrow
    Keypad_9_and_PageUp= 97,// Keypad 9 and PageUp
    Keypad_0_and_Insert= 98,// Keypad 0 and Insert
    Keypad_Dian_and_Delete=99,// Keypad . and Delete
    Keyboard_Application=101,// Keyboard Application
	Keyboard_Menu=118,

    Keyboard_LeftControl=224,
    Keyboard_LeftShift= 225,
    Keyboard_LeftAlt=226,
    Keyboard_LeftWindows=227,
    Keyboard_RightControl=228,
    Keyboard_RightShift= 229,
    Keyboard_RightAlt=230,
    Keyboard_RightWindows=231
}keypad_page_t;
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
typedef enum
{
    Left_Control=0,
    Left_Shift,
    Left_Alt,
    Left_GUI,
    Right_Control,
    Right_Shift,
    Right_Alt,
    Right_GUI,
} Byte0_Offset;
typedef struct
{
    struct
    {
        uint8_t Left_Control:1;
        uint8_t Left_Shift:1;
        uint8_t Left_Alt:1;
        uint8_t Left_GUI:1;
        uint8_t Right_Control:1;
        uint8_t Right_Shift:1;
        uint8_t Right_Alt:1;
        uint8_t Right_GUI:1;
    } byte0_off;
	//六键无冲缓冲区
    uint8_t stack_pointer;
    keypad_page_t  keypad[6];
}keyboard_cfg;


typedef struct
{
	uint8_t press_it:1;
	uint8_t used_it:1;
}Ordinary_key;
typedef struct
{
    struct
    {
        uint8_t Left_Control:1;
        uint8_t Left_Shift:1;
        uint8_t Left_Alt:1;
        uint8_t Left_GUI:1;
        uint8_t Right_Control:1;
        uint8_t Right_Shift:1;
        uint8_t Right_Alt:1;
        uint8_t Right_GUI:1;
    } byte0_off;
	//六键无冲缓冲区
    uint8_t stack_pointer;
    keypad_page_t  keypad_page[6];
	Ordinary_key ord_key[MAX_KEYPAD_PAGE];
} keyboard_hid;
void keypad_Update(uint8_t *pTxbuf);
extern keyboard_hid hid_info;
#endif
