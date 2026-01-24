// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdint.h>

#include <tm1637_fixed.h>
#include <display7segment4digit_decoder_time.h>

void main(void){
    uint8_t segments[4];

    Time_t time_t = {
        .hour  = 23,
        .minute  = 59,
        .second = 50,
        .colon  = 1
    };
                 
    TM1637_Config();

    Display7Segment4Digit_DecodeTime_HourMin(time_t, &segments[0]);        
    TM1637_SetSegments(segments, 4, 0);
    
    while(1){
                                
    };
}
