// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdint.h>
#include <delay.h>

#include <utility.h>
#include <display_7segment_decoder.h>

void IO_Config(void);

void main(void){
    uint8_t value=0;
    uint8_t buf=0;
    
    IO_Config();
    
    while (1){
        for(value=0; value<=9; ++value){ 
            buf = Display_DecoderDigitTo7Segment(value);
            //buf = Display_DecoderChrTo7Segment(10);
             
            PORTD = buf;
            PORTB =  Display_Toggle7Segment(buf);
            delay_ms(500);
        }
    };
}

//**************************************
void IO_Config(void){    
    DDRD=0xFF; PORTD=0xFF;
    DDRB=0xFF; PORTB=0xFF;
}
