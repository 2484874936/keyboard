/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY_POS12_Pin GPIO_PIN_13
#define KEY_POS12_GPIO_Port GPIOC
#define KEY_POS13_Pin GPIO_PIN_14
#define KEY_POS13_GPIO_Port GPIOC
#define KEY_POS14_Pin GPIO_PIN_15
#define KEY_POS14_GPIO_Port GPIOC
#define KEY_POS1_Pin GPIO_PIN_0
#define KEY_POS1_GPIO_Port GPIOC
#define KEY_POS2_Pin GPIO_PIN_1
#define KEY_POS2_GPIO_Port GPIOC
#define KEY_POS3_Pin GPIO_PIN_2
#define KEY_POS3_GPIO_Port GPIOC
#define KEY_POS4_Pin GPIO_PIN_3
#define KEY_POS4_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOA
#define BUTTON_AD_Pin GPIO_PIN_3
#define BUTTON_AD_GPIO_Port GPIOA
#define OLED_DC_Pin GPIO_PIN_4
#define OLED_DC_GPIO_Port GPIOA
#define OLED_CLK_Pin GPIO_PIN_5
#define OLED_CLK_GPIO_Port GPIOA
#define OLED_RST_Pin GPIO_PIN_6
#define OLED_RST_GPIO_Port GPIOA
#define OLED_MOSI_Pin GPIO_PIN_7
#define OLED_MOSI_GPIO_Port GPIOA
#define KEY_POS5_Pin GPIO_PIN_4
#define KEY_POS5_GPIO_Port GPIOC
#define KEY_POS6_Pin GPIO_PIN_5
#define KEY_POS6_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_0
#define LED2_GPIO_Port GPIOB
#define KEY_SEG1_Pin GPIO_PIN_1
#define KEY_SEG1_GPIO_Port GPIOB
#define KEY_SEG2_Pin GPIO_PIN_10
#define KEY_SEG2_GPIO_Port GPIOB
#define KEY_SEG3_Pin GPIO_PIN_11
#define KEY_SEG3_GPIO_Port GPIOB
#define KEY_SEG4_Pin GPIO_PIN_12
#define KEY_SEG4_GPIO_Port GPIOB
#define KEY_SEG5_Pin GPIO_PIN_13
#define KEY_SEG5_GPIO_Port GPIOB
#define KEY_SEG6_Pin GPIO_PIN_14
#define KEY_SEG6_GPIO_Port GPIOB
#define KEY_SEG7_Pin GPIO_PIN_15
#define KEY_SEG7_GPIO_Port GPIOB
#define KEY_POS7_Pin GPIO_PIN_6
#define KEY_POS7_GPIO_Port GPIOC
#define KEY_POS8_Pin GPIO_PIN_7
#define KEY_POS8_GPIO_Port GPIOC
#define KEY_POS9_Pin GPIO_PIN_8
#define KEY_POS9_GPIO_Port GPIOC
#define KEY_POS10_Pin GPIO_PIN_9
#define KEY_POS10_GPIO_Port GPIOC
#define KEY_POS11_Pin GPIO_PIN_8
#define KEY_POS11_GPIO_Port GPIOA
#define CAN2_RX_Pin GPIO_PIN_5
#define CAN2_RX_GPIO_Port GPIOB
#define CAN2_TX_Pin GPIO_PIN_6
#define CAN2_TX_GPIO_Port GPIOB
#define DIN_3V3_1_Pin GPIO_PIN_7
#define DIN_3V3_1_GPIO_Port GPIOB
#define DIN_3V3_2_Pin GPIO_PIN_8
#define DIN_3V3_2_GPIO_Port GPIOB
#define DIN_3V3_3_Pin GPIO_PIN_9
#define DIN_3V3_3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
