// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1637_INCLUDED
#define _TM1637_INCLUDED


#include <stdint.h>
#include <delay.h>

#include <utility.h> 
#include <tm1637_hw.h> 

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
void TM1637_SetDisplay(uint8_t onoff, uint8_t brightness);

/*
Write SRAM data in address auto increment 1 mode.
    segments[]: 1~6 Byte for SEG pins status.
    length: 1 to 6
    address: 0 to 5
        0: GRID1
        1: GRID2
        2: GRID3
        3: GRID4
        4: GRID5
        5: GRID6
*/
void TM1637_SetSegments(uint8_t segments[], uint8_t length, uint8_t address);

/*
Write SRAM data in a fixed address mode
    data: One Byte for SEG pins status.
    address: 0 to 5
        0: GRID1
        1: GRID2
        2: GRID3
        3: GRID4
        4: GRID5
        5: GRID6
*/
void TM1637_SetSegments_FixedAddress(uint8_t data, uint8_t address);
#pragma used-


#pragma library tm1637.lib
#endif
