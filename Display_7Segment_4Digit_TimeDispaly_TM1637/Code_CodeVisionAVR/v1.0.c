// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdint.h>

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
    
    tm1.clk.ddr  = &DDRC;
    tm1.clk.port = &PORTC;
    tm1.clk.pin  = &PINC;
    tm1.clk.index  = 0;

    tm1.dio.ddr  = &DDRC;
    tm1.dio.port = &PORTC;
    tm1.dio.pin  = &PINC;
    tm1.dio.index  = 1;
                 
    TM1637_Config(&tm1);

    Display7Segment4Digit_DecodeTime_HourMin(time_t, &segments[0]);        
    TM1637_SetSegments_4Digits(&tm1, segments);
    
    while(1){
                                
    };
}
