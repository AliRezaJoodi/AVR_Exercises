// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdint.h>
#include <delay.h>

#include "seg7_font.h"

void IO_Init(void);

void main(void){
    uint8_t value = 0;
    uint8_t i = 0;
    uint8_t segment[1];

    IO_Init(); delay_ms(1000);

    while (1){
        for(value=0; value<=9; ++value){
            segment[0] = seg7_font_digit[value];
            PORTD = segment[0];
            PORTB = ~(segment[0]);
            delay_ms(500);
        }

        for(i=0; i<=10; ++i){
            segment[0] = seg7_font_alpha[i];
            PORTD = segment[0];
            PORTB = ~(segment[0]);
            delay_ms(500);
        }

        for(i=0; i<=1; ++i){
            segment[0] = seg7_font_symbol[i];
            PORTD = segment[0];
            PORTB = ~(segment[0]);
            delay_ms(500);
        }
    };
}

//**************************************
void IO_Init(void){
    DDRD = 0xFF;
    PORTD = 0x00;

    DDRB = 0xFF;
    PORTB = 0xFF;
}
