#include "uart.h"

uint8_t UART_BUF[UART_BUF_SIZE];//串口接收缓存区
uint8_t UART_GETNUM = 0 ;//缓存区接收字节数

//设置UART
void UART_Config()
{
	UART_CLKON//打开串口时钟
	UART_HandleTypeDef huart1;
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 9600;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart1);
	UART_GPIO_Config();
	MX_NVIC_Init();
	//打开中断接收
	UART_PORT->CR1 |= 0x20 ;
}

//设置UART相关GPIO
void UART_GPIO_Config()
{
	UART_GPIO_CLKON//打开相关GPIO时钟
	GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = UART_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(UART_GPIO_PORT, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = UART_RX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(UART_GPIO_PORT, &GPIO_InitStruct);
}

//设置中断优先级
void MX_NVIC_Init(void)
{
  HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
}

//发一个字节
void UART_Writr(uint8_t BYTE)
{
	UART_PORT->DR = BYTE ;//准备一个字节
	while(!(UART_PORT->SR & 0x40));//等待发送完成
}

//中断处理
void USART1_IRQ()
{
	if(UART_PORT->SR & 0x20)//如果是接收触发中断
	{
		UART_BUF[UART_GETNUM] = UART_PORT->DR ;//保存到串口缓存区
		UART_GETNUM ++ ;//缓存字节数加1
		//如果缓存字节数值达到缓存区大小上限
		if(UART_GETNUM >= UART_BUF_SIZE)
			UART_GETNUM = 0 ;//归零重新计算
	}
}
