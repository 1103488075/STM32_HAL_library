#include "HX711.h"

uint32_t HX711_ZeroNum = 0 ; //无任何负载时ADC的度数,之后的每个读取数值都应该与其相减

void HX711_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	HX711_GPIO_CLKON
	GPIO_InitStruct.Pin = HX711_PIN_SDA ;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT ;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN ;
	HAL_GPIO_Init(HX711_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = HX711_PIN_CLK ;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
	GPIO_InitStruct.Pull = GPIO_NOPULL ;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH ;
	HAL_GPIO_Init(HX711_GPIO_PORT, &GPIO_InitStruct);
}

void HX711_Config()
{
	HX711_GPIO_Config();

	//断电一段时间重新复位
	HX711_CLK_SET//开始复位
	HX711_Delay(10000);
	HX711_CLK_DOW//恢复工作
	HX711_Delay(10000);

	//预先多次采集待芯片稳定
	for(uint8_t i=0 ; i<20 ; i++)
		HX711_Read();
}

//使用128增益读取数据
uint32_t HX711_Read()
{
	uint32_t SBUF = 0 ;
	//等待数据线允许转换
	while(HX711_SDA_IN != 0);
	//接收24位有效数据
	for( uint8_t i=0 ; i<24 ; i++ )
	{
		SBUF <<= 1 ;
		HX711_CLK_SET//上升沿请求下一位数据
		HX711_Delay(HX711_CLK_Delay);//等待数据稳定
		SBUF |= HX711_SDA_IN ;//接收数据
		HX711_CLK_DOW//下降沿完成一次接收
		HX711_Delay(HX711_CLK_Delay);
	}
	//发出代表128增益的第25个时钟信号
	HX711_CLK_SET
	HX711_Delay(HX711_CLK_Delay);
	HX711_CLK_DOW
	HX711_Delay(HX711_CLK_Delay);

	SBUF &= 0x007FFFFF ; //只取前23位
	SBUF >>= 2 ;//再去掉低2位
	//返回32位(21位有效)的数据
	return SBUF ;
}

//时钟简单延时
void HX711_Delay(uint16_t NUM)
{
	while(NUM--);
}

//通过滤波的算法获得稳定的AD读数
uint32_t HX711_GetLVBO(uint8_t GET_NUM)
{
	uint32_t ADD[GET_NUM] ;
	for(uint8_t i=0 ; i<GET_NUM ; i++)
		ADD[i] = HX711_Read() ;
	return LVBO_uint32_t(ADD,GET_NUM);//使用滤波后的数据
}


//输入AD度数,获得g
uint16_t HX711_COVER_G(uint32_t ADDATA)
{
	double g = 0 ;
	if(ADDATA <= CV1)
	{



		g = ADDATA/FM200g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
	else if((ADDATA>CV1)&(ADDATA<CV2))
	{
		g = ADDATA/FM500g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
	else if((ADDATA>CV2)&(ADDATA<CV3))
	{
		g = ADDATA/FM700g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
	else if((ADDATA>CV3)&(ADDATA<CV4))
	{
		g = ADDATA/FM1000g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
	else if((ADDATA>CV4)&(ADDATA<CV5))
	{
		g = ADDATA/FM1200g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
	else if((ADDATA>CV5)&(ADDATA<CV6))
	{
		g = ADDATA/FM1500g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
	else if(ADDATA>CV6)
	{
		g = ADDATA/FM1700g_1g ;
		if(((uint16_t)(g*10)%10)>5)
			g += 1 ;
		return (uint16_t)g ;
	}
}
