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

    SET_BITMASK(DDRD, 0xFFU);
    CLEAR_BITMASK(DDRB, 0x78U); delay_ms(1000);

//    test_bit_macro1();
//    test_bit_macro2(&led);
//
//    SET_BIT(PORTD, 3); delay_ms(1000);
//    WriteField_Reg8(&PORTD, 0b00111100U, 9U);

    while(1){
//        Write4Bit_Reg8(&PORTD, 0, Get4Bit_Reg8(&PINB, 3));
        WriteField_Reg8(&PORTD, 0x0FU, GetField_Reg8(&PINB, 0b01111000U));
    };
}

//**********************************************
void test_bit_macro2(const Pin_t *led){
    SET_BIT(*led->ddr, led->index); delay_ms(500); // PORTA.0 is output

    SET_BIT(*led->port, led->index); delay_ms(500);
    CLEAR_BIT(*led->port, led->index); delay_ms(1000);

    WRITE_BIT(*led->port, led->index, 1); delay_ms(500);
    WRITE_BIT(*led->port, led->index, 0); delay_ms(1000);
}

//**********************************************
void test_bit_macro1(void){
    uint8_t value = 0;

    SET_BIT(PORTD, 7); delay_ms(500);
    CLEAR_BIT(PORTD, 7); delay_ms(1000);

    TOGGLE_BIT(PORTD, 0); delay_ms(500);
    TOGGLE_BIT(PORTD, 0); delay_ms(1000);

    SET_BITMASK(PORTD, 0b11000000); delay_ms(500);
    CLEAR_BITMASK(PORTD, 0b11000000); delay_ms(1000);

    SET_BITMASK(PORTD, 0xFFU); delay_ms(1000);
    SET_BITMASK_DIRECT(PORTD, 0b11000000); delay_ms(1000);
    SET_BIT_DIRECT(PORTD, 0); delay_ms(1000);

    SET_BITMASK(PORTD, 0x30U); delay_ms(1000);
    TOGGLE_BITMASK(PORTD, 0x30U); delay_ms(1000);
    TOGGLE_BITMASK(PORTD, 0x30U); delay_ms(1000);
    CLEAR_BITMASK(PORTD, 0x00U); delay_ms(1000);

    value=0b00100000; WRITE_BIT(PORTD, 1, GET_BIT(value,5)); delay_ms(1000);
    value = 0b00011110; WRITE_3BIT(PORTD, 4, GET_3BIT(value,1)); delay_ms(500);
    CLEAR_BITMASK(PORTD, 0xFFU); delay_ms(1000);
}




