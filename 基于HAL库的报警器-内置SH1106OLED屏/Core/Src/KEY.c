#include "KEY.h"

u8 scan_key(void)
{
	static u8 flag = 0;
	  if(HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == 0)
		  {
			  HAL_Delay(5);
			  if(HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == 0)
			  {
				  while(HAL_GPIO_ReadPin(KEY1_GPIO,KEY1_GPIO_PIN) == 0);
				  flag = !flag;
				  return flag;
			  }
		  }
	 // return 0;
}
