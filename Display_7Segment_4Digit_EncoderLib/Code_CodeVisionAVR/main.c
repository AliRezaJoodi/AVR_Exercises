// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "display7segment4digit_decoder_float.h"

void IO_Init(void);

void main(void){
    uint8_t segments[4];

    IO_Init();

    Display7Segment4Digit_DecodeFloat_2d(24.36, &segments[0]);
    Display7Segment4Digit_Toggle4Byte( &segments[0] );

    while(1){
        PORTB=0x00; PORTD = segments[0]; PORTB.0=1;  delay_ms(5);
        PORTB=0x00; PORTD = segments[1]; PORTB.1=1;  delay_ms(5);
        PORTB=0x00; PORTD = segments[2]; PORTB.2=1;  delay_ms(5);
        PORTB=0x00; PORTD = segments[3]; PORTB.3=1;  delay_ms(5);
    };
}

///***************************
void IO_Init(void){
    DDRD = 0xFFU;
    PORTD = 0xFFU;

    DDRB = 0x0FU;
    PORTB = 0x00U;
}
