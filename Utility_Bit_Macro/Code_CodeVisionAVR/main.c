// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "aj_bit_macro.h"

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

    AJ_SET_BITS_MASK(DDRD, 0xFFU);
    AJ_CLEAR_BITS_MASK(DDRB, 0x78U); delay_ms(1000);

    test_bit_macro1();
    test_bit_macro2(&led);

    AJ_SET_BIT_POS(PORTD, 3); delay_ms(1000);

    while(1){

    };
}

//**********************************************
void test_bit_macro2(const Pin_t *led){
    AJ_SET_BIT_POS(*led->ddr, led->index); delay_ms(500); // PORTA.0 is output

    AJ_SET_BIT_POS(*led->port, led->index); delay_ms(500);
    AJ_CLEAR_BIT_POS(*led->port, led->index); delay_ms(1000);

    AJ_WRITE_BIT_POS(*led->port, led->index, 1); delay_ms(500);
    AJ_WRITE_BIT_POS(*led->port, led->index, 0); delay_ms(1000);
}

//**********************************************
void test_bit_macro1(void){
    uint8_t value = 0;

    AJ_SET_BIT_POS(PORTD, 7); delay_ms(500);
    AJ_CLEAR_BIT_POS(PORTD, 7); delay_ms(1000);

    AJ_TOGGLE_BIT_POS(PORTD, 0); delay_ms(500);
    AJ_TOGGLE_BIT_POS(PORTD, 0); delay_ms(1000);

    AJ_SET_BITS_MASK(PORTD, 0b11000000); delay_ms(500);
    AJ_CLEAR_BITS_MASK(PORTD, 0b11000000); delay_ms(1000);

    AJ_SET_BITS_MASK(PORTD, 0xFFU); delay_ms(1000);

    AJ_SET_BITS_MASK(PORTD, 0x30U); delay_ms(1000);
    AJ_TOGGLE_BITS_MASK(PORTD, 0x30U); delay_ms(1000);
    AJ_TOGGLE_BITS_MASK(PORTD, 0x30U); delay_ms(1000);
    AJ_CLEAR_BITS_MASK(PORTD, 0x00U); delay_ms(1000);

    value=0b00100000; AJ_WRITE_BIT_POS(PORTD, 1, AJ_GET_BIT_POS(value,5)); delay_ms(1000);
    value = 0b00011110; AJ_WRITE_3BITS_POS(PORTD, 4, AJ_GET_3BITS_POS(value,1)); delay_ms(500);
    AJ_CLEAR_BITS_MASK(PORTD, 0xFFU); delay_ms(1000);
}




