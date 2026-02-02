// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include <utility_bit.h>
#include "hardware.h"
#include <tm1637.h>
#include <display7segment4digit_decoder_time.h>

void main(void){
    uint8_t segments[4];

    Time_t time_t = {
        .hour  = 23,
        .minute  = 58,
        .second = 50,
        .colon  = 1
    };

//TM1637_Pin_t tm_clk_t;
//TM1637_Pin_t tm_dio_t;
//TM1637_t tm1;
//
//tm_clk_t.ddr   = &DDRC;
//tm_clk_t.port  = &PORTC;
//tm_clk_t.pin   = &PINC;
//tm_clk_t.index = 0;
//
//tm_dio_t.ddr   = &DDRC;
//tm_dio_t.port  = &PORTC;
//tm_dio_t.pin   = &PINC;
//tm_dio_t.index = 1;
//
//tm1.clk = tm_clk_t;
//tm1.dio = tm_dio_t;

    TM1637_t tm1;
    
    tm1.clk.ddr     = &TM1637_CLK_DDR;
    tm1.clk.port    = &TM1637_CLK_PORT;
    tm1.clk.pin     = &TM1637_CLK_PIN;
    tm1.clk.index   =  TM1637_CLK_BIT;

    tm1.dio.ddr     = &TM1637_DIO_DDR;
    tm1.dio.port    = &TM1637_DIO_PORT;
    tm1.dio.pin     = &TM1637_DIO_PIN;
    tm1.dio.index   =  TM1637_DIO_BIT;
                 
    TM1637_Config(&tm1);

    Display7Segment4Digit_DecodeTime_HourMin(time_t, &segments[0]);        
    TM1637_Set8Segments_4Digits(&tm1, segments);
    
    while(1){
                                
    };
}
