// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
//#include <stdlib.h>
#include <stdint.h>

#include <tm1637.h>
//#include <display7segment1digit_decoder.h>
#include <display7segment4digit_decoder_value.h>
#include <display7segment4digit_decoder_time.h>

void main(void){
    uint8_t segments[6];
    uint8_t i=0; 
//    float volt=0.521;

//Time_t time_t = {
//    .hour  = 23,
//    .minute  = 59,
//    .second = 50,
//    .colon  = 1
//};
                 
    TM1637_Config();

//    Display7Segment4Digit_DecodeDigits_f32_2dp(volt, &segments[0]); 
//    Display7Segment4Digit_DecodeTime_HourMin(time_t, &segments[0]); 
  
    for (i=0; i<6; ++i){
        Display7Segment1Digit_DecodeDigit(i, &segments[i]);    
    }
        
    TM1637_SetSegments(segments, 6, 0);
    
    while(1){
//        TM1637_SetOnOff(1); delay_ms(500);
//        TM1637_SetOnOff(0); delay_ms(500);                                  
    };
}
