#ifndef __RGB_H
#define __RGB_H

#include "stm32f1xx_hal.h"
#include "mxconstants.h"


void RGB_choose_blue(void);
void RGB_choose_red(void);
void RGB_choose_green(void);
void RGB_choose_colour(u8 num);
void RGB_choose_warning(void);
void RGB_choose_white(void);
void RGB_choose_close(void);
void RGB_choose_yellow(void);
void RGB_choose_violet(void);
void RGB_choose_blue_green(void);
void RGB_choose_move_colour(void);

#define   RGB_warning(a)   if(a) \
							RGB_choose_colour(3); \
							else  RGB_choose_colour(1);




#endif
