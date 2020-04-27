#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "ws2812b_task.h"


#define RGB_FLOW_COLOR_CHANGE_TIME  1000
#define RGB_FLOW_COLOR_LENGHT   6
//blue-> green(dark)-> red -> blue(dark) -> green(dark) -> red(dark) -> blue
//蓝 -> 绿(灭) -> 红 -> 蓝(灭) -> 绿 -> 红(灭) -> 蓝 
uint32_t RGB_flow_color[RGB_FLOW_COLOR_LENGHT + 1] = {0xFF0000FF, 0x0000FF00, 0xFFFF0000, 0x000000FF, 0xFF00FF00, 0x00FF0000, 0xFF0000FF};

ws2812b_led ws2812b_data;
/*
1.2us -- 0.833MHz
需要配置小于 0.83MHz
TIM4-APB1 42MHz->84MHz
PSC（7-1） ->  12MHz
ARR (96-1)   -> 0.25MHz ->8us
ARR (1200-1)  -> 0.01MHz ->100us 
*/
fp32 delta_alpha, delta_red, delta_green, delta_blue;
fp32 alpha,red,green,blue;

keyboard_rgb board_rgb[87];

osThreadId Ws2812b_TaskHandle;
void ws2812b_task_creat(void)
{
	osThreadDef(rgbled_task,ws2812b_task,osPriorityRealtime,0,128);
    Ws2812b_TaskHandle = osThreadCreate(osThread(rgbled_task), NULL);
}
void ws2812b_task(void const *pvParameters)
{
	HAL_TIM_Base_Start(&htim4);
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
    ws2812b_data.RGB_OFFSET[WS2812B_R_OFFSET] = 0;
	ws2812b_data.RGB_OFFSET[WS2812B_G_OFFSET] = 0;
	ws2812b_data.RGB_OFFSET[WS2812B_B_OFFSET] = 0;
    uint8_t k;	
	uint16_t i, j;
    uint32_t aRGB;
	mx_ws2812b_init(board_rgb);
	while(1)
	{
		for(i = 0; i < RGB_FLOW_COLOR_LENGHT; i++)
        {

            red = ((RGB_flow_color[i] & 0x00FF0000) >> 16);
            green = ((RGB_flow_color[i] & 0x0000FF00) >> 8);
            blue = ((RGB_flow_color[i] & 0x000000FF) >> 0);

            delta_red = (fp32)((RGB_flow_color[i + 1] & 0x00FF0000) >> 16) - (fp32)((RGB_flow_color[i] & 0x00FF0000) >> 16);
            delta_green = (fp32)((RGB_flow_color[i + 1] & 0x0000FF00) >> 8) - (fp32)((RGB_flow_color[i] & 0x0000FF00) >> 8);
            delta_blue = (fp32)((RGB_flow_color[i + 1] & 0x000000FF) >> 0) - (fp32)((RGB_flow_color[i] & 0x000000FF) >> 0);

            delta_red /= RGB_FLOW_COLOR_CHANGE_TIME;
            delta_green /= RGB_FLOW_COLOR_CHANGE_TIME;
            delta_blue /= RGB_FLOW_COLOR_CHANGE_TIME;
            for(j = 0; j < RGB_FLOW_COLOR_CHANGE_TIME; j++)
            {
                red += delta_red;
                green += delta_green;
                blue += delta_blue;
                aRGB =  ((uint32_t)(red)) << 16 | ((uint32_t)(green)) << 8 | ((uint32_t)(blue)) << 0;
				ws2812b_data.RGB_OFFSET[WS2812B_R_OFFSET] = red/10;
				ws2812b_data.RGB_OFFSET[WS2812B_G_OFFSET] = green/10;
				ws2812b_data.RGB_OFFSET[WS2812B_B_OFFSET] = blue/10;
				/*实际效果可以精确控制指定LED*/
				for(k=0;k<87;k++)
				{
					board_rgb[k].rgb_set.WS2812B_RGB = ws2812b_data.WS2812B_RGB;
				}
				ws2812b_id_cfg(board_rgb);
                osDelay(2);
            }
        }
	}
}
