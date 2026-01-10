// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1637_INCLUDED
#define _TM1637_INCLUDED

#include <io.h>
#include <delay.h>
#include <stdint.h>
#include <utility.h> 

#define TM1637_CLK_DDR         DDRB
#define TM1637_CLK_PIN         PINB
#define TM1637_CLK_PORT        PORTB
#define TM1637_CLK_BIT         0

#define TM1637_DIO_DDR         DDRB
#define TM1637_DIO_PIN         PINB
#define TM1637_DIO_PORT        PORTB
#define TM1637_DIO_BIT         1

#define TM1637_I2C_COMM1    0x40	//01	Data command setting
#define TM1637_I2C_COMM2    0xC0	//11	Address command setting
#define TM1637_I2C_COMM3    0x80	//10	Display and control command setting

void TM1637_Config(void);

#pragma used+
static inline void TM1637_Delay(void){
    delay_us(100);
} 

static inline void TM1637_CLK_SetInput(void){
    ClearBit(TM1637_CLK_DDR, TM1637_CLK_BIT);
    ClearBit(TM1637_CLK_PORT, TM1637_CLK_BIT);
}

static inline void TM1637_CLK_SetOutput(uint8_t status){
    if(status){
        TM1637_CLK_SetInput();
    }
    else{
        SetBit(TM1637_CLK_DDR, TM1637_CLK_BIT);
        ClearBit(TM1637_CLK_PORT, TM1637_CLK_BIT);    
    }
}

static inline void TM1637_DIO_SetInput(void){
    ClearBit(TM1637_DIO_DDR, TM1637_DIO_BIT);
    ClearBit(TM1637_DIO_PORT, TM1637_DIO_BIT);
}

static inline void TM1637_DIO_SetOutput(uint8_t status){
    if(status){
        TM1637_DIO_SetInput();
    }
    else{
        SetBit(TM1637_DIO_DDR, TM1637_DIO_BIT);
        ClearBit(TM1637_DIO_PORT, TM1637_DIO_BIT);    
    }
}

static inline uint8_t TM1637_DIO_GetInput(void){
    TM1637_DIO_SetInput();
    return GetBit(TM1637_DIO_PIN, TM1637_DIO_BIT);
}

void TM1637_Start(void);
void TM1637_Stop(void);
uint8_t TM1637_WriteByte(uint8_t b);

#pragma used-


#pragma library tm1637.lib
#endif
