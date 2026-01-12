// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
//#include <stdlib.h>
#include <stdint.h>

#include <tm1637.h>
#include <display_7segment_decoder.h>

void main(void){
    uint8_t segments[6];
    uint8_t i=0;
             
    TM1637_Config();
    
    for (i=0; i<6; ++i){
        segments[i] = Display_DecoderDigitTo7Segment(i);    
    }
    
    TM1637_SetSegments(segments, 6, 0);
    
    while(1){
        TM1637_SetOnOff(1); delay_ms(500);
        TM1637_SetOnOff(0); delay_ms(500);                                  
    };
}
