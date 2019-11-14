#include "LVBO.h"

void PAIXU_float(float *list , uint8_t num)
{
	for(uint8_t i=0 ; i<num-1 ; i++)
	{
		for(uint8_t j=0 ; j<num-i ; j++)
		{
			if(list[j]>list[j+1])
			{
				float BUF = list[j] ;
				list[j] = list[j+1] ;
				list[j+1] = BUF ;
			}
		}
	}
}

void PAIXU_uint16_t(uint16_t *list , uint8_t num)
{
	for(uint8_t i=0 ; i<num-1 ; i++)
	{
		for(uint8_t j=0 ; j<num-i ; j++)
		{
			if(list[j]>list[j+1])
			{
				uint16_t BUF = list[j] ;
				list[j] = list[j+1] ;
				list[j+1] = BUF ;
			}
		}
	}
}

void PAIXU_uint32_t(uint32_t *list , uint8_t num)
{
	for(uint8_t i=0 ; i<num-1 ; i++)
	{
		for(uint8_t j=0 ; j<num-i ; j++)
		{
			if(list[j]>list[j+1])
			{
				uint32_t BUF = list[j] ;
				list[j] = list[j+1] ;
				list[j+1] = BUF ;
			}
		}
	}
}

float LVBO_float(float *list , uint8_t num)
{
	PAIXU_float(list,num);//排序
	uint8_t get_num = (uint8_t)(num*(1/5.0)) ;//20%
	uint8_t start_num = (num/2)-(get_num/2);//计算从哪一位开始累加
	double ADD = 0.0 ;
	for( uint8_t i=start_num ; i<start_num+get_num ; i++)
		ADD += list[i] ;//累加数据
	return ADD/get_num*1.0 ;//返回平均值
}

uint16_t LVBO_uint16_t(uint16_t *list , uint8_t num)
{
	PAIXU_uint16_t(list,num);//排序
	uint8_t get_num = (uint8_t)(num*(1/5.0)) ;//20%
	uint8_t start_num = (num/2)-(get_num/2);//计算从哪一位开始累加
	uint16_t ADD = 0.0 ;
	for( uint8_t i=start_num ; i<start_num+get_num ; i++)
		ADD += list[i] ;//累加数据
	uint16_t OUT = ADD/get_num ;
	if((ADD % get_num) > 5) OUT += 1 ;
	return OUT ;//返回平均值
}

uint32_t LVBO_uint32_t(uint32_t *list , uint8_t num)
{
	PAIXU_uint32_t(list,num);//排序
	uint8_t get_num = (uint8_t)(num*(1/5.0)) ;//20%
	uint8_t start_num = (num/2)-(get_num/2);//计算从哪一位开始累加
	uint32_t ADD = 0.0 ;
	for( uint8_t i=start_num ; i<start_num+get_num ; i++)
		ADD += list[i] ;//累加数据
	uint32_t OUT = ADD/get_num ;
	if((ADD % get_num) > 5) OUT += 1 ;
	return OUT ;//返回平均值
}
