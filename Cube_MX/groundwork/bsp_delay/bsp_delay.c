#include "bsp_delay.h"
//�޸�__weak����������HAL_DELAYΪus��ʱ
//HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
//{
//  /*��SysTick����Ϊ��1usʱ�����ж�*/
//  if (HAL_SYSTICK_Config(SystemCoreClock / 1000000) > 0U)
//  {
//    return HAL_ERROR;
//  }
//  /*����ϵͳSysTick IRQ���ȼ�*/
//  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
//  {
//    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
//    uwTickPrio = TickPriority;
//  }
//  else
//  {
//    return HAL_ERROR;
//  }
//  /*���ع���״̬*/
//  return HAL_OK;
//}
////����us����ʱ����
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
//���������������
void delay_ms(uint32_t nms)
{
//	uint32_t i;
//	for(i=0;i<nms;i++) delay_us(1000);
	HAL_Delay(nms);
}
////���������������,���ݴ�ͳHAL_Delay��ʱ
//void HAL_Delay(uint32_t nms)
//{
//	uint32_t i;
//	for(i=0;i<nms;i++) delay_us(1000);
//}
