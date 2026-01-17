// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega16a.h>
#include <delay.h>
#include <stdint.h>

#include <display7segment1digit_decoder.h>
#include <tm1638.h>

void main(void){
    uint8_t segments[16];
                
    TM1638_Config();

    Display7Segment1Digit_DecodeDigit(0, &segments[0]);
    segments[1]=0b00000000;    
    Display7Segment1Digit_DecodeDigit(1, &segments[2]); 
    segments[3]=0b00000001;  
    Display7Segment1Digit_DecodeDigit(2, &segments[4]); 
    segments[5]=0b00000000; 
    Display7Segment1Digit_DecodeDigit(3, &segments[6]); 
    segments[7]=0b00000000;  
    Display7Segment1Digit_DecodeDigit(4, &segments[8]);    
    segments[9]=0b00000000; 
    Display7Segment1Digit_DecodeDigit(5, &segments[10]); 
    segments[11]=0b00000000; 
    Display7Segment1Digit_DecodeDigit(6, &segments[12]); 
    segments[13]=0b00000001;  
    Display7Segment1Digit_DecodeDigit(7, &segments[14]); 
    segments[15]=0b00000000; 
               
    TM1638_SetSegments(segments, 16, 0); delay_ms(1000);
    TM1638_ResetSegments(); delay_ms(1000);
        
    Display7Segment1Digit_DecodeDigit(9, &segments[0]);    
    Display7Segment1Digit_DecodeDigit(0, &segments[1]); 
    Display7Segment1Digit_DecodeDigit(2, &segments[2]); 
    Display7Segment1Digit_DecodeDigit(7, &segments[3]); 
    Display7Segment1Digit_DecodeDigit(4, &segments[4]); 
    Display7Segment1Digit_DecodeDigit(6, &segments[5]); 
    Display7Segment1Digit_DecodeDigit(5, &segments[6]); 
    Display7Segment1Digit_DecodeDigit(3, &segments[7]); 
           
    TM1638_SetSegments_WithoutSeg9Seg10(segments, 8, 0); delay_ms(1000);
    TM1638_ResetSegments(); delay_ms(1000);

    TM1638_SetSegments_WithoutSeg9Seg10(segments, 2, 6); delay_ms(1000);
    TM1638_ResetSegments(); delay_ms(1000);
        
    TM1638_SetSegments_FixedAddress(segments[6], 0); delay_ms(1000);
    TM1638_SetSegments_FixedAddress(0b00000001, 0x0F); delay_ms(1000);
    TM1638_SetSegments_FixedAddress(0b00000001, 0x01); delay_ms(1000);
    
    TM1638_SendCommand(0b10000111); delay_ms(1000); 
    TM1638_SetDisplay(1, 7); delay_ms(1000);
      
    delay_ms(3000); TM1638_ResetSegments();
    
    while(1){                         
    };
}
