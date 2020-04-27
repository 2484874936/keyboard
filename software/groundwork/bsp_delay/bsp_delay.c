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
#include "bsp_delay.h"
//修改__weak函数，配置HAL_DELAY为us延时
//HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
//{
//  /*将SysTick配置为在1us时间内中断*/
//  if (HAL_SYSTICK_Config(SystemCoreClock / 1000000) > 0U)
//  {
//    return HAL_ERROR;
//  }
//  /*配置系统SysTick IRQ优先级*/
//  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
//  {
//    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
//    uwTickPrio = TickPriority;
//  }
//  else
//  {
//    return HAL_ERROR;
//  }
//  /*返回功能状态*/
//  return HAL_OK;
//}
////创建us级延时函数
//void delay_us(uint32_t Delay)
//{
//  uint32_t tickstart = HAL_GetTick();
//  uint32_t wait = Delay;
//  /* Add a freq to guarantee minimum wait */
//  if (wait < HAL_MAX_DELAY)
//  {
//    wait += (uint32_t)(uwTickFreq);
//  }
//  while((HAL_GetTick() - tickstart) < wait)
//  {
//  }
//}
//不会引起任务调度
void delay_ms(uint32_t nms)
{
//	uint32_t i;
//	for(i=0;i<nms;i++) delay_us(1000);
	HAL_Delay(nms);
}
////不会引起任务调度,兼容传统HAL_Delay延时
//void HAL_Delay(uint32_t nms)
//{
//	uint32_t i;
//	for(i=0;i<nms;i++) delay_us(1000);
//}
