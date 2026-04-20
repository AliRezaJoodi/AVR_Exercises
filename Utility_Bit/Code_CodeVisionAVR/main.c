// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "utils/bit.h"

void main(void){
    typedef struct {
        volatile uint8_t *ddr;
        volatile uint8_t *port;
        volatile uint8_t *pin;
        const uint8_t    index;
    } Pin_t;

    Pin_t led = {
        .ddr   = &DDRA,
        .port  = &PORTA,
        .pin   = &PINA,
        .index = 0
    };

    uint8_t value = 0;

    delay_ms(1000);

    SET_BIT(*led.ddr, led.index); delay_ms(500); // PORTA.0 is output
    SET_BIT(*led.port, led.index); delay_ms(500);
    CLEAR_BIT(*led.port, led.index); delay_ms(1000);
    WRITE_BIT(*led.port, led.index, 1); delay_ms(500);
    WRITE_BIT(*led.port, led.index, 0); delay_ms(1000);

    SET_BIT(DDRA, 1); delay_ms(500); // PORTA.1is output
    value=0b00100000; WRITE_BIT(PORTA, 1, GET_BIT(value,5)); delay_ms(500);
    value=0b11011111; WRITE_BIT(PORTA, 1, GET_BIT(value,5)); delay_ms(500);

    DDRC = 0xFF; delay_ms(500);
    value = 0b00001111; WRITE_4BIT(PORTC, 0, GET_4BIT(value,0)); delay_ms(500);
    TOGGLE_4BIT(PORTC, 0); delay_ms(500);
    value = 0b00000110; WRITE_2BIT(PORTC, 2, GET_2BIT(value,1)); delay_ms(500);

    CLEAR_4BIT(DDRB, 3);

    while(1){
         WRITE_4BIT(PORTC, 0, GET_4BIT(PINB,3));
    };
}




