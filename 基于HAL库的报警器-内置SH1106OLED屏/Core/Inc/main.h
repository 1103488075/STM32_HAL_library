
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "memory.h"

//#include "bmp.h"
#include "gpio.h"
#include "oled.h"
#include "RGB.h"


#define   Buzz_use(a)   if(a) \
		 	 	 	 	 	 HAL_GPIO_WritePin ( Buzz_GPIO, Buzz_GPIO_PIN, GPIO_PIN_RESET); \
							else   HAL_GPIO_WritePin ( Buzz_GPIO, Buzz_GPIO_PIN, GPIO_PIN_SET);

void Systick_Interrupt_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
