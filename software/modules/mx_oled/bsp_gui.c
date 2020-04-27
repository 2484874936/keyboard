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
#include "bsp_gui.h"
#include "bsp_adc.h"
#include "bmp.h"
/*	���Ե�ѹ(��λ: mV)
	���� 	0		0		1		0
	�� 		638		638		637		637
	��		1328	1326	1324	1323
	��		1965	1968	1963	1961
	��		2599	2602	2597	2591
*/
oled_gui mx_oled_info_s;
/****************************************************************/
/*				GUI�ַ��б� �Զ���7*7�ֽ�����ʾ 				*/
//������Ҫ��������ʾ����
u8 mx_oled_gui_str	[7][MAX_SIZE_LENGTH] = 
{".adc_text  ",".imu_task  ",".power     ",".hello4    ",".hello5    ",".hello6    ",".hello7    "};
/*adc_text*/
u8 mx_oled_gui_task1[7][MAX_SIZE_LENGTH] = 
{".adc_button",".dbus_key  ",".task1_p3  ",".task1_p4  ",".task1_p5  ",".task1_p6  ",".task1_p7  "};

u8 mx_oled_gui_task2[7][MAX_SIZE_LENGTH] = 
{".mpu6600  ",".temp_test",".task2_p3  ",".task2_p4  ",".task2_p5  ",".task2_p6  ",".task2_p7  "};

u8 mx_oled_gui_task3[7][MAX_SIZE_LENGTH] = 
{".ina226   ",".task3_p2  ",".task3_p3  ",".task3_p4  ",".task3_p5  ",".task3_p6  ",".task3_p7  "};

u8 mx_oled_gui_task4[7][MAX_SIZE_LENGTH] = 
{".task4_p1  ",".task4_p2  ",".task4_p3  ",".task4_p4  ",".task4_p5  ",".task4_p6  ",".task4_p7  "};

u8 mx_oled_gui_task5[7][MAX_SIZE_LENGTH] = 
{".task5_p1  ",".task5_p2  ",".task5_p3  ",".task5_p4  ",".task5_p5  ",".task5_p6  ",".task5_p7  "};

u8 mx_oled_gui_task6[7][MAX_SIZE_LENGTH] = 
{".task6_p1  ",".task6_p2  ",".task6_p3  ",".task6_p4  ",".task6_p5  ",".task6_p6  ",".task6_p7  "};

u8 mx_oled_gui_task7[7][MAX_SIZE_LENGTH] = 
{".task7_p1  ",".task7_p2  ",".task7_p3  ",".task7_p4  ",".task7_p5  ",".task7_p6  ",".task7_p7  "};
/*				GUI�ַ��б� �Զ���7*7�ֽ�����ʾ 				*/
/****************************************************************/
/*��ʼ��gui ����gui����ָ��*/
const oled_gui* get_oled_info_data(void)
{
	oled_gui_init();
	return  &mx_oled_info_s;
}
//��ʼ��GUI����
void oled_gui_init(void)
{
	mx_oled_info_s.oled_options_s[0] = 1;
	mx_oled_info_s.oled_options_s[1] = 1;
	mx_oled_info_s.oled_directory = 0;
	mx_oled_info_s.oled_gui_lock=0;		//Ĭ��adc������Ч��gui����״̬
	mx_oled_info_s.olde_gui_max = MAX_GUI;
	mx_oled_info_s.oled_Interface_update = interface_main;
}
/*����������adc����ֵ*/
u8 range_comparison(u16 get,u16 target)
{
	u16 d;
	if(target>70){d=target-70; }
	else if(target<70){d=0;}
	if(get>=d&&get<=(target+70))
	{
		return 1;
	}
	else return 0 ;
}

/*��ȡadc������Ϣ*/
void get_oled_button_ad(void)
{
	static u8 error_data = 0;
	mx_oled_info_s.adc_key_val = get_oled_voltage();
	if(range_comparison(mx_oled_info_s.adc_key_val,KEY_ON)==1){mx_oled_info_s.oled_key_button_s = mx_key_on;error_data = 0;}
	if(range_comparison(mx_oled_info_s.adc_key_val,KEY_LEFT)==1){mx_oled_info_s.oled_key_button_s = mx_key_left;error_data = 0;}
	if(range_comparison(mx_oled_info_s.adc_key_val,KEY_RIGHT)==1){mx_oled_info_s.oled_key_button_s = mx_key_right;error_data = 0;}
	if(range_comparison(mx_oled_info_s.adc_key_val,KEY_TOP)==1){mx_oled_info_s.oled_key_button_s = mx_key_top;error_data = 0;}
	if(range_comparison(mx_oled_info_s.adc_key_val,KEY_BOTTOM)==1){mx_oled_info_s.oled_key_button_s = mx_key_bottom;error_data = 0;}
	if(range_comparison(mx_oled_info_s.adc_key_val,KEY_NULL)==1){mx_oled_info_s.oled_key_button_s = mx_key_null;error_data = 0;}
	else {error_data++;}
	if(error_data >=20)
	{	
		mx_oled_info_s.oled_key_button_s = mx_key_null;
//		printf("key_button_ad:error!");//����adc��ֵ���ڷ�Χ��
	}
}

/*gui������Ϣ���� ���������Ϣ����*/
void interface_main(void)
{
	get_oled_button_ad();//��ȡadc������Ϣ
	switch(mx_oled_info_s.oled_key_button_s)
	{
		case mx_key_null   :break;
		case mx_key_on     :break;
		case mx_key_left   : 
		{
			if(mx_oled_info_s.oled_gui_lock==0)
			if(mx_oled_info_s.oled_directory>0)
			{
				mx_oled_info_s.oled_directory--;
				OLED_Clear();//������������
			}
		}break;
		case mx_key_right  :
		{
			if(mx_oled_info_s.oled_gui_lock==0)
			if(mx_oled_info_s.oled_directory<MAX_D)
			{
				mx_oled_info_s.oled_directory++;
				OLED_Clear();//������������
			}
		}
		break;
		case mx_key_top    :
			{
				if(mx_oled_info_s.oled_directory==0)break;//��ǰ��0����������
				if(mx_oled_info_s.oled_directory==3)break;//��ǰ��3����������
				if(mx_oled_info_s.oled_options_s[mx_oled_info_s.oled_directory-1]>1)
				{mx_oled_info_s.oled_options_s[mx_oled_info_s.oled_directory-1]--;}
			}
			break;
		case mx_key_bottom :
			{
				if(mx_oled_info_s.oled_directory==0)break;
				if(mx_oled_info_s.oled_directory==3)break;
				if(mx_oled_info_s.oled_options_s[mx_oled_info_s.oled_directory-1]<mx_oled_info_s.olde_gui_max)
				{mx_oled_info_s.oled_options_s[mx_oled_info_s.oled_directory-1]++;}
			}break;	
	}		
	switch(mx_oled_info_s.oled_directory)
	{
		case 0:{OLED_DrawBMP(0,0,128,6,BMP2);mx_oled_info_s.oled_options_s[0]=1;};break;
		case 1:{interface_finger(mx_oled_info_s.oled_options_s[0],
								mx_oled_gui_str);
				mx_oled_info_s.oled_options_s[1]=1;
			  };break;
		case 2:interface_second();break;
		case 3:interface_second();break;
	}
}

/*gui��Ŀ������ʾ����*/
void interface_second(void)
{
	switch(mx_oled_info_s.oled_options_s[0])
	{
		case 1:interface_task1();break;
		case 2:interface_task2();break;
		case 3:interface_task3();break;
		case 4:interface_task4();break;
		case 5:interface_task5();break;
		case 6:interface_task6();break;
		case 7:interface_task7();break;
	}
}

void interface_finger(u8 get_finger,u8 fin_mx_task[7][MAX_SIZE_LENGTH])
{
	u8 k;
	static u8 min=1,max=4;
	if(get_finger>max)
	{
		min=get_finger-3;
		max = get_finger;
	}
	if(get_finger<min)
	{
		min=get_finger;
		max = get_finger+3;
	}
	for(k=0;k<4;k++)
	{
		if(min+k==get_finger)OLED_ShowChar(0,(k)*2,'-');
		else OLED_ShowChar(0,(k)*2,' ');
		OLED_ShowNum(10,(k)*2,min+k,1,16);
		OLED_ShowString(20,(k)*2,&fin_mx_task[min+k-1][0]);
	}
}

/*gui���溯��1*/
void interface_task1(void)
{
	if(mx_oled_info_s.oled_directory==2)
				interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task1);
	if(mx_oled_info_s.oled_directory==3)
	{
		switch(mx_oled_info_s.oled_options_s[1])
		{
			case 1:task1_adc_button();break;
			case 2:dbus_show();break;
			case 3:;break;
			case 4:;break;
			case 5:;break;
			case 6:;break;
			case 7:;break;
		}
	}
}
/*gui���溯��2*/
void interface_task2(void)
{
	if(mx_oled_info_s.oled_directory==2)
		interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task2);
	if(mx_oled_info_s.oled_directory==3)
	{
		switch(mx_oled_info_s.oled_options_s[1])
		{
			case 1:task2_imu();break;
			case 2:task2_temp();break;
			case 3:;break;
			case 4:;break;
			case 5:;break;
			case 6:;break;
			case 7:;break;
		}
	}
}
/*gui���溯��3*/
void interface_task3(void)
{
	if(mx_oled_info_s.oled_directory==2)
		interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task3);
	if(mx_oled_info_s.oled_directory==3)
	{
		switch(mx_oled_info_s.oled_options_s[1])
		{
			case 1:ina226_task3();break;
			case 2:task2_temp();break;
			case 3:;break;
			case 4:;break;
			case 5:;break;
			case 6:;break;
			case 7:;break;
		}
	}
}
/*gui���溯��4*/
void interface_task4(void)
{
	interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task4);
}
/*gui���溯��5*/
void interface_task5(void)
{
	interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task5);
}
/*gui���溯��6*/
void interface_task6(void)
{
	interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task6);
}
/*gui���溯��7*/
void interface_task7(void)
{
	interface_finger(mx_oled_info_s.oled_options_s[1],					
				mx_oled_gui_task7);
}

/*adc_button������ʾ����*/
void task1_adc_button(void)
{
	gui_lock();//��Ϊ��adc�������ԣ�������ui����
	OLED_ShowString(2,0,(u8*)"button_ad_text");
	OLED_ShowNum(10,4,mx_oled_info_s.adc_key_val,7,16);
	OLED_ShowString(80,4,(u8*)"mV");
	//����adc��������������gui�������ֶ�����
	gui_unlock_s();
}
void dbus_show(void)
{
	//
}
/*imu������ʾ����*/
void task2_imu(void)
{

}
void task2_temp(void)
{

}

void ina226_task3(void)
{

}
//����ui����
void gui_lock(void)
{
	mx_oled_info_s.oled_gui_lock = 1;
}
//gui�����ֶ�����,������ⲿ������������������ϵ���������
void gui_unlock_s(void)
{
//	if(mx_info_sum.key_info_s->key_info.states != KEY_UPSPRING)
//	{
//		OLED_Clear();
//		mx_oled_info_s.oled_gui_lock = 0;
//		mx_oled_info_s.oled_directory--;
//	}
}

