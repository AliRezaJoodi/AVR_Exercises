// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1637_INCLUDED
#define _TM1637_INCLUDED


#include <stdint.h>
#include <delay.h>

#include <utility.h> 
#include <tm1637_hw.h> 

void TM1637_Config(void);

#pragma used+
void TM1637_Start(void);
void TM1637_Stop(void);
uint8_t TM1637_WriteByte(uint8_t data);
void TM1637_SetOnOff(uint8_t status);
void TM1637_SetBrightness(uint8_t value_1To7);
void TM1637_SetSegments(uint8_t segments[], uint8_t length, uint8_t pos);
#pragma used-


#pragma library tm1637.lib
#endif
