// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "seg7_4digit_encoder.h"

void IO_Init(void);

void main(void){
    uint8_t segments[4];

    IO_Init();

    Seg7_4Digit_EncodeFloat_2DP(12.34, &segments[0]);
    Seg7_4Digit_ToggleSegments( &segments[0] );

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
