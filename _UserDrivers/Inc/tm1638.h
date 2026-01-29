// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1638_INCLUDED
#define _TM1638_INCLUDED


#include <stdint.h>
#include <io.h>
#include <delay.h>

#include <utility_bit.h> 
#include "hardware.h"

#ifndef TM1638_HARDWARE
#define TM1638_HARDWARE
    #warning "TM1638_HARDWARE is not defined. Using default TM1638 pin configuration."
    #define TM1638_CLK_DDR         DDRC
    #define TM1638_CLK_PORT        PORTC
    #define TM1638_CLK_BIT         7

    #define TM1638_DIO_DDR         DDRC
    #define TM1638_DIO_PIN         PINC
    #define TM1638_DIO_PORT        PORTC
    #define TM1638_DIO_BIT         6
#endif 

#ifndef TM1638_HARDWARE_EXTRA
#define TM1638_HARDWARE_EXTRA
    #define TM1638_STB1_DDR        DDRA
    #define TM1638_STB1_PORT       PORTA
    #define TM1638_STB1_BIT        7
#endif 

/*
TM1637_BIT_US Unit: uS  
Clock Frequenc: 1 / (TM1637_BIT_US*2)
Typical clock frequency: 500KHz
Maximum clock frequency: 1MHz
*/
#ifndef TM1637_BIT_US
#define TM1637_BIT_US            1
#endif 

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} TM1638_Pin_t;

typedef struct {
    TM1638_Pin_t stb;
} TM1638_t;

void TM1638_Config(TM1638_t *tm);
void TM1638_SendCommand(TM1638_t *tm, uint8_t command);

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
uint8_t TM1638_SetDisplay(TM1638_t *tm, uint8_t onoff, uint8_t brightness);

/*
reset Seg1 to Seg10.
Clear all digits and leds
*/
void TM1638_ResetSegments(TM1638_t *tm);

/*
Address increment mode.
    segments[]: Array of up to 16 bytes, representing the status of Seg1 to Seg10.
    length: 1 to 16
    address: 0 to 15
*/
uint8_t TM1638_SetSegments_Seg1ToSeg10(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t address);

/*
Address increment mode.
    segments[]: Array of up to 8 bytes, representing the status of Seg1 to Seg8.
    length: Number of digits (1 to 8).
    pos: Starting position (0 to 7)
Note: length <= (8-pos)
Note: SEG9 and SEG10 will be written with value 0.
*/
uint8_t TM1638_SetSegments_Seg1ToSeg8_OverWriteSeg9Seg10(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t pos);

/*
Address increment mode.
    segments[]: Array of up to 8 bytes, representing the status of Seg1 to Seg8.
    length: Number of digits (1 to 8).
    pos: Starting position (0 to 7)
Note: length <= (8-pos)
Note: Does not affect on the SEG9 and SEG10.
*/
uint8_t TM1638_SetSegments_Seg1ToSeg8_KeepSeg9Seg10(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t pos);

/*
Write SRAM data in a fixed address mode
    data: 1-Byte for Seg pins status.
    address: 0 to 15
*/
uint8_t TM1638_SetSegments_FixedAddress(TM1638_t *tm, uint8_t data, uint8_t address);

/*
data: 8-Bit 
    Bit 0: LED connected to SEG9 and GRID1 
    ...
    Bit 7: LED connected to SEG9 and GRID8
Note: SEG10 will be written with value 0.
*/
void TM1638_SetLeds_Seg9(TM1638_t *tm, uint8_t data);

/*
data: 16-Bit 
    Bit 0: LED connected to SEG9 and GRID1
    Bit 1: LED connected to SEG10 and GRID1 
    ...
    Bit 14: LED connected to SEG9 and GRID8
    Bit 15: LED connected to SEG10 and GRID8
*/
void TM1638_SetLeds_Seg9Seg10(TM1638_t *tm, uint16_t data);

/*
Multi press
Scan buttons that connected to K1, K2, and K3 lines.
key:    4-Byte
*/
void TM1638_GetButtons_K1K2K3(TM1638_t *tm, uint8_t *key);

/*
Multi press
Scan 1 to 8 buttons that connected to K3 lines.
key:    1-Byte
*/
void TM1638_GetButtons_K3(TM1638_t *tm, uint8_t *key);

/*
Multi press
Scan 1 to 8 buttons that connected to K3 lines.
*/
uint8_t TM1638_ReturnButtons_K3(TM1638_t *tm);

#pragma library tm1638.lib
#endif
