#include "LCD.h"

uint8_t LCD_SHOWLIST[4][16];
uint8_t LCD_HanAddr[4] = { 0x80 , 0x90 , 0x88 , 0x98 };

//LCD引脚初始化
void LCD_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	LCD_GPIO_CLKON
	GPIO_InitStruct.Pin = LCD_PIN_RS|LCD_PIN_E;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_GPIO_COM_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LCD_PIN_DATA;
	HAL_GPIO_Init(LCD_GPIO_DATA_PORT, &GPIO_InitStruct);
	LCD_E_DOW
}

//向LCD发送一个字节指令
void LCD_COM(uint8_t BYTE)
{
	LCD_RS_DOW//RS 0 为指令
	LCD_Delay(CLK_DELAY);
	//改变低八位引脚电平
	LCD_GPIO_DATA_PORT->ODR = \
			(LCD_GPIO_DATA_PORT->ODR & 0xff00)|BYTE ;
	LCD_Delay(CLK_DELAY);
	LCD_E_SET//使能脉冲
	LCD_Delay(CLK_DELAY);
	LCD_E_DOW
	LCD_Delay(COM_DELAY);
}

//向LCD发送一个字节数据
void LCD_DAT(uint8_t BYTE)
{
	LCD_RS_SET//RS 1 为数据
	//改变低八位引脚电平
	LCD_GPIO_DATA_PORT->ODR = \
		(LCD_GPIO_DATA_PORT->ODR & 0xff00)|BYTE ;
	LCD_Delay(CLK_DELAY);
	LCD_E_SET//使能脉冲
	LCD_Delay(CLK_DELAY);
	LCD_E_DOW
	LCD_Delay(DAT_DELAY);
}

//初始化屏幕
void LCD_Config()
{
	LCD_GPIO_Config();
	LCD_Delay(60000);//LCD上电初始化时间
	LCD_Delay(60000);
	LCD_Delay(60000);

	LCD_COM(0x30);//标准指令

	LCD_COM(0x01);//清屏
	LCD_Delay(60000);//7ms

	LCD_COM(0x03);//地址归位
	LCD_Delay(60000);//7ms

	LCD_COM(0x06);//光标右移,画面固定,AC++
	LCD_COM(0x0C);//开显示,开光标,闪烁
}

//时序延时
void LCD_Delay(uint16_t num)
{
	while(num--);
}

void LCD_Clean()
{
	LCD_COM(0x01);//清屏
	LCD_Delay(60000);//7ms
}

//显示所有显存数据
void LCD_ShowAll()
{
	uint8_t BUF , i ;
	LCD_COM(0x80);//定位到第1行
	for( i=0 ; i<16 ; i++)
	{
		BUF = LCD_SHOWLIST[0][i] ;
		if(BUF != '\0') LCD_DAT(BUF);
		else LCD_DAT(' ');
	}
	for( i=0 ; i<16 ; i++)
	{
		BUF = LCD_SHOWLIST[2][i] ;
		if(BUF != '\0') LCD_DAT(BUF);
		else LCD_DAT(' ');
	}
	for( i=0 ; i<16 ; i++)
	{
		BUF = LCD_SHOWLIST[1][i] ;
		if(BUF != '\0') LCD_DAT(BUF);
		else LCD_DAT(' ');
	}
	for( i=0 ; i<16 ; i++)
	{
		BUF = LCD_SHOWLIST[3][i] ;
		if(BUF != '\0') LCD_DAT(BUF);
		else LCD_DAT(' ');
	}
}

//从某处更改数据(偶数的前一位被覆盖为空格);
void LCD_Show(uint8_t han , uint8_t wei , char *p)
{
	LCD_COM(LCD_HanAddr[han]+(wei/2));
	if(wei%2) LCD_DAT(' ');
	while(*p != '\0')
	{
		LCD_DAT(*p);
		p++ ;
	}
}
