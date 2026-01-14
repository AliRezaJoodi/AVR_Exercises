// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdint.h>
#include <delay.h>

#include <utility.h>
#include <display7segment1digit_decoder.h>

void IO_Config(void);

void main(void){
    uint8_t value=0;
    uint8_t segment[1];
    
    IO_Config();
    
    while (1){
        for(value=0; value<=9; ++value){ 
            Display7Segment1Digit_DecodeDigit(value, &segment[0]);
            //Display7Segment1Digit_DecodeChr(value, &segment[0]);
            PORTD = segment[0];
            
            Display7Segment1Digit_ToggleSegments(&segment[0]);
            PORTB = segment[0]; 
            
            delay_ms(500);
        }
    };
}

//**************************************
void IO_Config(void){    
    DDRD=0xFF; PORTD=0xFF;
    DDRB=0xFF; PORTB=0xFF;
}
