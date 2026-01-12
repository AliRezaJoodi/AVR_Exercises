// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1637_INCLUDED
#define _TM1637_INCLUDED


#include <io.h>
#include <delay.h>
#include <stdint.h>

#include <utility.h> 

#define TM1637_CLK_DDR         DDRC
#define TM1637_CLK_PIN         PINC
#define TM1637_CLK_PORT        PORTC
#define TM1637_CLK_BIT         0

#define TM1637_DIO_DDR         DDRC
#define TM1637_DIO_PIN         PINC
#define TM1637_DIO_PORT        PORTC
#define TM1637_DIO_BIT         1

#define TM1637_DELAY            (uint8_t)100  // uS

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
