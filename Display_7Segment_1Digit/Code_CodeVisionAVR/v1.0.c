// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdint.h>
#include <delay.h>

#include <utility.h>
#include <seg7_1digit_encoder.h>

void IO_Init(void);

void main(void){
    uint8_t value=0;
    uint8_t segment[1];

    IO_Init(); delay_ms(1000);

    while (1){
        for(value=0; value<=9; ++value){
            Seg7_1Digit_EncodeDigit_ByRef(value, &segment[0]);
            PORTD = segment[0];

            Seg7_1Digit_ToggleSegments_ByRef(&segment[0]);
            PORTB = segment[0];

            delay_ms(500);
        }

        for(value=0; value<=10; ++value){
            Seg7_1Digit_EncodeAlpha_ByRef(value, &segment[0]);
            PORTD = segment[0];

            Seg7_1Digit_ToggleSegments_ByRef(&segment[0]);
            PORTB = segment[0];

            delay_ms(500);
        }

        for(value=0; value<=1; ++value){
            Seg7_1Digit_EncodeSymbol_ByRef(value, &segment[0]);
            PORTD = segment[0];

            Seg7_1Digit_ToggleSegments_ByRef(&segment[0]);
            PORTB = segment[0];

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
