#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <string.h>
#include "stm32f1xx_hal.h"
#include "LCD.h"
#include "HX711.h"
#include "KEY.h"
#include "LVBO.h"
#include "uart.h"
#include "Sonic.h"


/*
 * 硬件初始化与基础函数...
 */
void System_Config(void);
void SystemClock_Config(void);
void Delay(uint16_t num);


/*
 * 重要的系统函数!!!
 */
void SYSTEM_INIT();//称重去皮归零,水位高度测量归零



#endif
