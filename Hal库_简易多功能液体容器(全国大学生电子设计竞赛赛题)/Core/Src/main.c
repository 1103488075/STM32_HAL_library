#include "main.h"

/*系统基础变量...*/
uint8_t KEY ;
uint8_t fist_test = 1 ;//基础:初次测量标志位
uint16_t last_test_g = 0 ; //基础:上一个测量的数值

/*重要测量参数变量!!!*/
uint16_t MAIN_g = 0 ;	//测量出的质量 g
uint16_t MAIN_high = 0 ;//测量出来的高度 mm
float MAIN_cm3 = 0.0 ;	//计算出来的体积 cm3
float MAIN_midu = 0.0 ;	//计算出来的密度 g/cm3

const uint8_t SHOW_NONE[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0',};//清行

int main()
{
	System_Config();//初始化硬件
	SYSTEM_INIT();//测量传感器统一归零,显示欢迎界面
	while(1)
	{
		//基础测量循环
		while(1)
		{
			KEY = KEY_Read1();//等待按键触发
			if(KEY)
			{
				if(KEY == 1)
					Basis();//基础测量
				//长按跳出循环进入种类测量
				else if(KEY == 2)
					break ;
			}
		}
		//种类测量循环
		while(1)
		{
			KEY = KEY_Read1();//等待按键触发
			if(KEY)
			{
				if(KEY == 1)
					Basis();//基础测量
				//长按跳出循环进入种类测量
				else if(KEY == 2)
					break ;
			}
		}
	}
}

void SYSTEM_INIT()//称重去皮归零,水位高度测量归零
{
	//提示文字
	const uint8_t str1[]={0xBB,0xB6,0xD3,0xAD,0xCA,0xB9,0xD3,0xC3,'\0'};//欢迎使用
	LCD_Show(0,4,str1);
	const uint8_t str2[]={0xA1,0xBE,0xCF,0xB5,0xCD,0xB3,0xB3,0xF5,0xCA,0xBC,0xBB,0xAF,0xD6,0xD0,0xA1,0xBF,'\0'};//系统初始化中
	LCD_Show(2,0,str2);
	//----------------------------------------------------
	//HX711_ZeroNum = HX711_GetLVBO(128);//获取称重归零
	Sonic_ZeroNum = Sonic_GetLVBO(255);//获取水位归零
	//----------------------------------------------------
	LCD_Show(2,0,SHOW_NONE);//清空上次显示
	const uint8_t str3[]={0xA1,0xBE,0xC9,0xE8,0xD6,0xC3,0xCD,0xEA,0xB3,0xC9,0xA1,0xBF,'\0'};//设置完成
	LCD_Show(2,2,str3);
	Delay(12000);//延时3s
	//LCD_Clean();//清空屏幕
}

void Basis()//基础测量
{

}

void Senior()//高级测量
{

}

/*
 * 以下为硬件初始化函数及简易功能函数
 */
void System_Config(void)
{
	HAL_Init();
	SystemClock_Config();
	UART_Config();
	LCD_Config();
	HX711_Config();
	KEY_GPIO_Config();
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
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
}

void Delay(uint16_t num)
{
	for(uint16_t i=0 ; i<num ; i++)
		for(uint16_t j=0 ; j<1000 ; j++) ;
}
