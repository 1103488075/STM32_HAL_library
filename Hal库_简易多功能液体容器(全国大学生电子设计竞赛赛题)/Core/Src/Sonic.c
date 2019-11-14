#include "Sonic.h"

uint16_t Sonic_ZeroNum = 0 ;//无水状态探头到瓶底距离

void Sonic_Get_Data()
{
	UART_Writr(0xa0);//请求信号
	while(UART_GETNUM<3);//等待接收完成3位
	UART_GETNUM = 0 ;//读取后归零接收计数
	HAL_Delay(150);//等待超声波探头就绪
}

uint16_t Sonic_Conversion_Data(uint8_t* Array_Buff)
{
	uint16_t Array_Data = (Array_Buff[0]*65536+Array_Buff[1]*256+Array_Buff[2])/1000;
	return Array_Data;//返回解码后的数据
}

uint16_t Sonic_GetLVBO(uint8_t GET_NUM)
{
	uint16_t ADD[GET_NUM] ;
	for(uint8_t i=0 ; i<GET_NUM ; i++)
	{
		Sonic_Get_Data();//请求并接收
		//转换并保存到滤波数据
		ADD[i] = Sonic_Conversion_Data(UART_BUF);
	}
	return LVBO_uint16_t(ADD,GET_NUM);//使用滤波后的数据
}

float WaterVolume(uint16_t High)
{
	//返回立方厘米为单位的体积
	return BottomArea*(High/10.0) ;
}
