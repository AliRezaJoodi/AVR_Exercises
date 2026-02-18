// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "seg7_font.h"
#include "seg7_encoder.h"

void IO_Init(void);

void main(void){
    uint8_t segments[4]={0, 0, 0, 0};
//    segments[0] = seg7_font_digit[1];
//    segments[1] = seg7_font_digit[2];
//    segments[2] = seg7_font_digit[3];
//    segments[3] = seg7_font_digit[4];

    IO_Init();

    Seg7_Encode4Digits_U16(4321, &segments[0]);
    Seg7_Reverse4Bytes(&segments[0]);

    while(1){
        PORTB=0x00; PORTD = ~segments[0]; PORTB.0=1;  delay_ms(5);
        PORTB=0x00; PORTD = ~segments[1]; PORTB.1=1;  delay_ms(5);
        PORTB=0x00; PORTD = ~segments[2]; PORTB.2=1;  delay_ms(5);
        PORTB=0x00; PORTD = ~segments[3]; PORTB.3=1;  delay_ms(5);
    };
}

///***************************
void IO_Init(void){
    DDRD = 0xFFU;
    PORTD = 0xFFU;

    DDRB = 0xFFU;
    PORTB = 0x00U;
}
