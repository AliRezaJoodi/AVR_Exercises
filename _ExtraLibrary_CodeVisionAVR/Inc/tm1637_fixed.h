// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1637_FIXED_INCLUDED
#define _TM1637_FIXED_INCLUDED

#include <main.h>
#include <stdint.h>
#include <io.h>
#include <delay.h>

#include <utility_bit.h>

#ifndef _TM1637_FIXED_HARDWARE
#define _TM1637_FIXED_HARDWARE     
    #define TM1637_CLK_DDR         DDRC
    #define TM1637_CLK_PIN         PINC
    #define TM1637_CLK_PORT        PORTC
    #define TM1637_CLK_BIT         0

    #define TM1637_DIO_DDR         DDRC
    #define TM1637_DIO_PIN         PINC
    #define TM1637_DIO_PORT        PORTC
    #define TM1637_DIO_BIT         1

    #define TM1637_HALF_BIT_US     1
#endif

void TM1637_Config(void);

#pragma used+
void TM1637_SendCommand(uint8_t command);

/*
Display control:
    onoff: 0 or 1
        1: Display ON
        0: Display OFF
    brightness: 0~ 7
        0: Pulse width is set as 1/16. 
        1: Pulse width is set as 2/16.
        2: Pulse width is set as 4/16.
        3: Pulse width is set as 10/16.
        4: Pulse width is set as 11/16.
        5: Pulse width is set as 12/16.
        6: Pulse width is set as 13/16.
        7: Pulse width is set as 14/16.     
*/
uint8_t TM1637_SetDisplay(uint8_t onoff, uint8_t brightness);

/*
Clear all digits.
reset Seg1 to Seg10.
*/
void TM1637_ResetSegments(void);

/*
Write SRAM data in address auto increment 1 mode.
    segments[]: 1~6 Byte for SEG pins status.
    length: 1 to 6
    address: 0 to 5
        0: GRID1
        ...
        5: GRID6
*/
uint8_t TM1637_SetSegments(uint8_t segments[], uint8_t length, uint8_t address);

/*
Write SRAM data in a fixed address mode
    data: One Byte for SEG pins status.
    address: 0 to 5
        0: GRID1
        ...
        5: GRID6
*/
uint8_t TM1637_SetSegments_FixedAddress(uint8_t data, uint8_t address);
#pragma used-


#pragma library tm1637_fixed.lib
#endif
