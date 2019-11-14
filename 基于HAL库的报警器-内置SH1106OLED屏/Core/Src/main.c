
#include "main.h"


TIM_HandleTypeDef htim1;

void SystemClock_Config(void);
void System_Config(void);
void Systick_Config(void);
void warning_continue_time(void);
void MX_TIM1_Init(void);
u8 Scan_key(void);
void OLED_display_status(void);


u8 warning_flag = 0;
u8 flag = 0;
int main(void)
{

  System_Config();

  RGB_choose_close();
  Buzz_use(0);
  while (1)
  {

	  OLED_display_status();

	  if(Scan_key() == 1)
	  {
		  flag = !flag;
		  warning_flag = 0;
	  }
	  if(flag == 1)
		  Buzz_use(0);

  }
}

u8 Scan_key(void)
{
	  if(HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == 0)
		  {
				  HAL_Delay(5);
				  if(HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == 0)
				  {
					  while(HAL_GPIO_ReadPin(KEY1_GPIO,KEY1_GPIO_PIN) == 0);
					  	 return 1;
				  }
		  }
	  return 0;
}

//OLED显示状态
void OLED_display_status(void)
{
	  if( (HAL_GPIO_ReadPin(SR602_input_GPIO_Port,SR602_input_Pin) == 1)   )//OLED显示非法入侵
	  {
		  HAL_Delay(5);
		  if( (HAL_GPIO_ReadPin(SR602_input_GPIO_Port,SR602_input_Pin) == 1)   )
		  {
			  OLED_ShowStatus_1();
			  warning_flag = 1;
			  Buzz_use(1);
		  }
	  }
	  else if( (HAL_GPIO_ReadPin(SR602_input_GPIO_Port,SR602_input_Pin) == 0) && (warning_flag == 0))//OLED显示状态正常
	  {
		  HAL_Delay(5);
		  if( (HAL_GPIO_ReadPin(SR602_input_GPIO_Port,SR602_input_Pin) == 0) && (warning_flag == 0))
		  {
			  OLED_Display_On();	//开启显示屏
			  OLED_ShowStatus_0();
			  Buzz_use(0);
		  }
	  }
}

void HAL_SYSTICK_Callback(void)
{

	if(warning_flag == 1 )
	{
		RGB_choose_warning();//RGB灯报警模式
		OLED_Show_flicker();//OLE屏闪烁
		warning_continue_time();//报警持续时间


	}
	else if(warning_flag == 0 )
	{
		RGB_choose_move_colour();//RGB灯正常颜色流转
		Buzz_use(0);
	}


}


//报警持续时间
void warning_continue_time(void)
{
	static u32 num = 0;
	if(num++ >= 8000)
	{
		num = 0;
		warning_flag = 0; //回到正常模式
	}
}

void System_Config(void)
{
	  HAL_Init();
	  SystemClock_Config();
	  Systick_Config();	//Systick interrupt configuration
	  MX_GPIO_Init();	/*Oled and RGB Pin configuration*/
	  OLED_Init();
	  OLED_Clear();

}

void MX_TIM1_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 36000-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1000-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_Base_Init(&htim1);

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig);

}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;



  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;

  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);


}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim->Instance == TIM1){


	}

}

void Systick_Config(void)
{
	/**Configure the Systick interrupt time*/
	  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);	//1ms intterupt

	    /**Configure the Systick
	    */
	  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	  /* SysTick_IRQn interrupt configuration */
	  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

