// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "bit.h"

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    const uint8_t    index;
    const uint8_t    mask;
} Pin_t;

void test_bit_macro1(void);
void test_bit_macro2(const Pin_t *led);

void main(void){
    Pin_t led = {
        .ddr   = &DDRA,
        .port  = &PORTA,
        .pin   = &PINA,
        .index = 0U,
        .mask  = (1U << 0)
    };

    BM_SET_BITMASK(DDRD, 0xFFU);
    BM_CLEAR_BITMASK(DDRB, 0x78U); delay_ms(1000);

//    test_bit_macro1();
//    test_bit_macro2(&led);
//
//    BM_SET_BIT(PORTD, 3); delay_ms(1000);
//    WriteField_Reg8(&PORTD, 0b00111100U, 9U);

    while(1){
//        Write4Bit_Reg8(&PORTD, 0, Get4Bit_Reg8(&PINB, 3));
        WriteField_Reg8(&PORTD, 0x0FU, GetField_Reg8(&PINB, 0b01111000U));
    };
}

//**********************************************
void test_bit_macro2(const Pin_t *led){
    BM_SET_BIT(*led->ddr, led->index); delay_ms(500); // PORTA.0 is output

    BM_SET_BIT(*led->port, led->index); delay_ms(500);
    BM_CLEAR_BIT(*led->port, led->index); delay_ms(1000);

    BM_WRITE_BIT(*led->port, led->index, 1); delay_ms(500);
    BM_WRITE_BIT(*led->port, led->index, 0); delay_ms(1000);
}

//**********************************************
void test_bit_macro1(void){
    uint8_t value = 0;

    BM_SET_BIT(PORTD, 7); delay_ms(500);
    BM_CLEAR_BIT(PORTD, 7); delay_ms(1000);

    BM_TOGGLE_BIT(PORTD, 0); delay_ms(500);
    BM_TOGGLE_BIT(PORTD, 0); delay_ms(1000);

    BM_SET_BITMASK(PORTD, 0b11000000); delay_ms(500);
    BM_CLEAR_BITMASK(PORTD, 0b11000000); delay_ms(1000);

    BM_SET_BITMASK(PORTD, 0xFFU); delay_ms(1000);

    BM_SET_BITMASK(PORTD, 0x30U); delay_ms(1000);
    BM_TOGGLE_BITMASK(PORTD, 0x30U); delay_ms(1000);
    BM_TOGGLE_BITMASK(PORTD, 0x30U); delay_ms(1000);
    BM_CLEAR_BITMASK(PORTD, 0x00U); delay_ms(1000);

    value=0b00100000; BM_WRITE_BIT(PORTD, 1, BM_GET_BIT(value,5)); delay_ms(1000);
    value = 0b00011110; BM_WRITE_3BIT(PORTD, 4, BM_GET_3BIT(value,1)); delay_ms(500);
    BM_CLEAR_BITMASK(PORTD, 0xFFU); delay_ms(1000);
}




