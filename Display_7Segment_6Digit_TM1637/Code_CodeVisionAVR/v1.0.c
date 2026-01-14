// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
//#include <stdlib.h>
#include <stdint.h>

#include <tm1637.h>
#include <display_7segment_1digit.h>

void Display7Segment4Digit_Decoder_f32_2dp(float value,  uint8_t *seg){
    Display7Segment1Digit_DecoderDigitToSegments(4, (seg+0));
    Display7Segment1Digit_DecoderDigitToSegments(9, (seg+1));
    Display7Segment1Digit_DecoderChrToSegments(1, (seg+2));
    Display7Segment1Digit_DecoderChrToSegments(2, (seg+3));
    Display7Segment1Digit_ToggleSegments(seg+3);    
}

void main(void){
    uint8_t segments[4];
    uint8_t i=0; 
    float volt=9.52;
             
    TM1637_Config();

    Display7Segment4Digit_Decoder_f32_2dp(volt, &segments[0]);    
//    for (i=0; i<6; ++i){
//        segments[i] = Display7Segment1Digit_DecoderDigitToSegments(i);    
//    }
//    segments[0] = Display7Segment1Digit_DecoderDigitToSegments(4);
//    segments[1] = Display7Segment1Digit_DecoderDigitToSegments(3);
//    segments[2] = Display7Segment1Digit_DecoderDigitToSegments(2);
//    segments[3] = Display7Segment1Digit_DecoderDigitToSegments(1);
        
    TM1637_SetSegments(segments, 4, 0);
    
    while(1){
//        TM1637_SetOnOff(1); delay_ms(500);
//        TM1637_SetOnOff(0); delay_ms(500);                                  
    };
}
