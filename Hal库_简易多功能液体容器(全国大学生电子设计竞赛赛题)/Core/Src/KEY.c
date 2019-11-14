#include "KEY.h"

void KEY_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  KEY_1_CLKON
  GPIO_InitStruct.Pin = KEY_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY_1_PORT, &GPIO_InitStruct);
  KEY_1_PORT->BSRR = KEY_1_Pin ;
}

uint8_t KEY_Read1()//读取按键1
{
	if(KEY_Read_1 == 0)
	{
		KEY_Delay(2500);
		if(KEY_Read_1 == 0)
		{
			while(KEY_Read_1);//等待按键放开
			return 2 ;//返回长按
		}
		else
			return 1 ;//返回短按
	}
	else return 0 ;//返回无按动
}

void KEY_Delay(uint16_t num)
{
	for(uint16_t i=0 ; i<num ; i++)
		for(uint16_t j=0 ; j<1000 ; j++) ;
}
