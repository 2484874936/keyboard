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
