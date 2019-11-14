#include "RGB.h"


void RGB_choose_blue(void)
{
	LED1_OFF();LED2_ON();LED3_ON();
}

void RGB_choose_red(void)
{
	LED1_ON();LED2_ON();LED3_OFF();
}

void RGB_choose_green(void)
{
	LED1_ON();LED2_OFF();LED3_ON();
}

void RGB_choose_white(void)
{
	LED1_OFF();LED2_OFF();LED3_OFF();
}

void RGB_choose_yellow(void)
{
	LED1_ON();LED2_OFF();LED3_OFF();
}

void RGB_choose_blue_green(void)
{
	LED1_OFF();LED2_OFF();LED3_ON();
}

void RGB_choose_violet(void)
{
	LED1_OFF();LED2_ON();LED3_OFF();
}

void RGB_choose_close(void)
{
	LED1_ON();LED2_ON();LED3_ON();
}
void RGB_choose_colour(u8 num)
{
	switch(num)
	{
	case 1:RGB_choose_blue();break;
	case 2:RGB_choose_green();break;
	case 3:RGB_choose_red();break;
	case 4:RGB_choose_white();break;
	case 5:RGB_choose_yellow();break;
	case 6:RGB_choose_blue_green();break;
	case 7:RGB_choose_violet();break;

	}
}
void RGB_choose_move_colour(void)
{
	static u16 num = 0,i = 1;

	if(num++ >= 3000)
	{
	num = 0;
	RGB_choose_colour(i);
		if(i++ > 7)i = 1;
	}
}

void RGB_choose_warning(void)
{
	static u32 sum = 0;
	static u8 flag = 0;

	if(sum++ >= 100)
	{
		sum = 0;
		flag = !flag;
		RGB_warning(flag);
 	}

}

