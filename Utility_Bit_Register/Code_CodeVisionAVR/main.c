// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "utils/bit_register.h"

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

    Pin_t key = {
        .ddr   = &DDRB,
        .port  = &PORTB,
        .pin   = &PINB,
        .index = 3
    };

//    uint8_t value = 0;

    delay_ms(1000);

    Set_Bit_Reg8(led.ddr, led.index); delay_ms(500); // config output
    Set_Bit_Reg8(led.port, led.index); delay_ms(500);
    Clear_Bit_Reg8(led.port, led.index); delay_ms(1000);
    Write_Bit_Reg8(led.port, led.index, 1); delay_ms(500);
    Write_Bit_Reg8(led.port, led.index, 0); delay_ms(1000);
    Toggle_Bit_Reg8(led.port, led.index); delay_ms(500);
    Toggle_Bit_Reg8(led.port, led.index); delay_ms(1000);

    Clear_Bit_Reg8(key.ddr, key.index); delay_ms(500);  // config input
    Set_Bit_Reg8(key.port, key.index); delay_ms(500);   // config pull-up

    while(1){
         Write_Bit_Reg8(led.port, led.index, Get_Bit_Reg8(key.pin, key.index));
    };
}




