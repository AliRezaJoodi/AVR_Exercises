// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdint.h>

#include <tm1637.h>
#include <display7segment1digit_decoder.h>

void main(void){
    uint8_t segments[6];
    uint8_t i=0; 
                
    TM1637_Config();
  
    for (i=0; i<6; ++i){
        Display7Segment1Digit_DecodeDigit(i, &segments[i]);    
    }
        
    TM1637_SetSegments(segments, 6, 0); delay_ms(1000); 
    TM1637_SetSegments_FixedAddress(segments[5], 2); delay_ms(1000);
    TM1637_ResetSegments(); delay_ms(1000);
    TM1637_SetSegments_FixedAddress(segments[2], 5); delay_ms(1000);    
    TM1637_SendCommand(0b10000111); delay_ms(1000); //Turn off the display 
    TM1637_SetDisplay(1, 7); 
    
    while(1){
                                 
    };
}
