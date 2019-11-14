#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"

extern uint8_t LCD_SHOWLIST[4][16];

#define LCD_GPIO_CLKON		__HAL_RCC_GPIOA_CLK_ENABLE();\
							__HAL_RCC_GPIOB_CLK_ENABLE();

#define LCD_GPIO_DATA_PORT	GPIOA
#define LCD_GPIO_COM_PORT	GPIOB

#define 	LCD_PIN_RS			GPIO_PIN_0
#define 	LCD_PIN_E			GPIO_PIN_1
#define	LCD_PIN_DATA		GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2\
		|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7

#define CLK_DELAY			4
#define COM_DELAY			4000
#define DAT_DELAY			400

#define LCD_RS_SET 			LCD_GPIO_COM_PORT->BSRR = LCD_PIN_RS ;
#define LCD_RS_DOW 			LCD_GPIO_COM_PORT->BRR = LCD_PIN_RS ;
#define LCD_E_SET 			LCD_GPIO_COM_PORT->BSRR = LCD_PIN_E ;
#define LCD_E_DOW 			LCD_GPIO_COM_PORT->BRR = LCD_PIN_E ;

//初始化设置lcd_gpio
void LCD_GPIO_Config();
void LCD_COM(uint8_t BYTE);
void LCD_DAT(uint8_t BYTE);
void LCD_Config();
//简单延时
void LCD_Delay(uint16_t num);
void LCD_Clean();
void LCD_ShowAll();
void LCD_Show(uint8_t han , uint8_t wei , char *p);
#endif
