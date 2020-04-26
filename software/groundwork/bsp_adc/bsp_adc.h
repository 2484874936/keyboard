#ifndef BSP_ADC_H
#define BSP_ADC_H
#include "struct_typedef.h"
void init_vrefint_reciprocal(void);
fp32 get_temprate(void);
fp32 get_voltage(void);
fp32 get_oled_voltage(void);
#endif
