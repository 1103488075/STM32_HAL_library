#ifndef _SONIC_H_
#define _SONIC_H_

#include "main.h"

#define BottomArea		176.715 //cm3
extern uint16_t Sonic_ZeroNum ;

void Sonic_Get_Data();
uint16_t Sonic_Conversion_Data(uint8_t* Array_Buff);
uint16_t Sonic_GetLVBO(uint8_t GET_NUM);

#endif
