#ifndef _KEY_H_
#define _KEY_H_

#include "main.h"

#define KEY_1_CLKON		__HAL_RCC_GPIOC_CLK_ENABLE();
#define KEY_1_PORT		GPIOC
#define KEY_1_Pin		GPIO_PIN_7

#define KEY_Read_1		(KEY_1_PORT->IDR & KEY_1_Pin)

void KEY_GPIO_Config(void);
uint8_t KEY_Read1();

#endif
