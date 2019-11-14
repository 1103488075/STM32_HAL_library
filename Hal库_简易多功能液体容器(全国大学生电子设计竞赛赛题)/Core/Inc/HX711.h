#ifndef _HX711_H_
#define _HX711_H_

#include "main.h"

//使用各种重量砝码校准后得到的1g的对应数值
#define FM200g_1g  		97.808
#define FM500g_1g 		97.884
#define FM700g_1g 		97.932
#define FM1000g_1g 		97.885
#define FM1200g_1g  		97.897
#define FM1500g_1g  		97.876
#define FM1700g_1g  		97.842

		g = AD值/97.884;

		g = AD值/97.932;

		g = AD值/97.885;

		g = AD值/97.897;

		g = AD值/97.876;

		g = AD值/97.842;

//转换常量阈值
#define CV1				34252
#define CV2				58747
#define CV3				83219
#define CV4				107681
#define CV5				132145
#define CV6				156573

extern uint32_t HX711_ZeroNum ;

#define HX711_GPIO_CLKON		__HAL_RCC_GPIOC_CLK_ENABLE();
#define HX711_GPIO_PORT		GPIOC

#define HX711_PIN_SDA		GPIO_PIN_5
#define HX711_PIN_CLK		GPIO_PIN_4

#define HX711_SDA_IN			((HX711_GPIO_PORT->IDR & HX711_PIN_SDA) >> 5)
#define HX711_CLK_SET		HX711_GPIO_PORT->BSRR = HX711_PIN_CLK ;
#define HX711_CLK_DOW		HX711_GPIO_PORT->BRR  = HX711_PIN_CLK ;

#define HX711_CLK_Delay		4

void HX711_GPIO_Config();
void HX711_Config();
uint32_t HX711_Read();
void HX711_Delay(uint16_t NUM);
uint32_t HX711_GetLVBO(uint8_t GET_NUM);
uint16_t HX711_COVER_G(uint32_t ADDATA);

#endif
