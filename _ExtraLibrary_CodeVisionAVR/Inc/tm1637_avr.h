// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _TM1637_AVR_INCLUDED
#define _TM1637_AVR_INCLUDED

#include <delay.h>

#include <utility.h>

#define TM1637_Delay_us(VALUE)                         delay_us(VALUE);

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
    //TM1637_DIO_SetInput();
    return GetBit(TM1637_DIO_PIN, TM1637_DIO_BIT);
}


#endif
