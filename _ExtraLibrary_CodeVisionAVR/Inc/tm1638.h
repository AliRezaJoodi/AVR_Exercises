// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1638_INCLUDED
#define _TM1638_INCLUDED


#include <stdint.h>
#include <delay.h>

#include <utility.h> 
#include <tm1638_hw.h> 

void TM1638_Config(void);

#pragma used+
void TM1638_SendCommand(uint8_t command);

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
uint8_t TM1638_SetDisplay(uint8_t onoff, uint8_t brightness);

/*
Clear all digits
reset Seg1 to Seg10.
*/
void TM1638_ResetSegments(void);

/*
Address increment mode.
    segments[]: Maximum 16-Byte for Seg1 to Seg10 pins status.
    length: 1 to 16
    address: 0 to 15
*/
uint8_t TM1638_SetSegments(uint8_t segments[], uint8_t length, uint8_t address);

/*
Address increment mode.
    segments[]: Maximum 8-Byte for Seg1 to Seg8 pins status.
    length: 1 to 8
    pos: 0 to 7
Note: length <= (8-pos)
Note: Will be wirte 0 value on the Seg9 and Seg10.
*/
uint8_t TM1638_SetSegments_WithoutSeg9Seg10(uint8_t segments[], uint8_t length, uint8_t pos);

/*
Write SRAM data in a fixed address mode
    data: 1-Byte for Seg pins status.
    address: 0 to 15
*/
uint8_t TM1638_SetSegments_FixedAddress(uint8_t data, uint8_t address);
#pragma used-


#pragma library tm1638.lib
#endif
