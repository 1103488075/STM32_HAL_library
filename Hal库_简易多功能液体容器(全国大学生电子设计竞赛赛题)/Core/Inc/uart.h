#ifndef _UART_H_
#define _UART_H_

#include "main.h"

#define UART_BUF_SIZE	32 //设置缓存区大小
extern uint8_t UART_BUF[UART_BUF_SIZE];
extern uint8_t UART_GETNUM ;

#define UART_CLKON			__HAL_RCC_USART1_CLK_ENABLE();
#define UART_GPIO_CLKON		__HAL_RCC_GPIOA_CLK_ENABLE();

#define UART_PORT			USART1
#define UART_GPIO_PORT		GPIOA
#define UART_RX_PIN			GPIO_PIN_10
#define UART_TX_PIN			GPIO_PIN_9

void UART_Config();//设置UART
void UART_GPIO_Config();//设置UART相关GPIO
void UART_Writr(uint8_t BYTE);//串口发送一个字节
void MX_NVIC_Init();//设置优先级
void USART1_IRQ();//回调函数

#endif
