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
        const uint8_t    mask;
    } Pin_t;

    Pin_t led = {
        .ddr   = &DDRA,
        .port  = &PORTA,
        .pin   = &PINA,
        .index = 0U,
        .mask  = (1U << 0U)
    };

    Pin_t led2 = {
        .ddr   = &DDRA,
        .port  = &PORTA,
        .pin   = &PINA,
        .index = 1U,
        .mask  = (1U << 1U)
    };

    Pin_t key = {
        .ddr   = &DDRB,
        .port  = &PORTB,
        .pin   = &PINB,
        .index = 3U,
        .mask = (1U << 3U)
    };

//    uint8_t value = 0;

    delay_ms(1000);
    SetBit_Reg8(led.ddr, led.index); delay_ms(1000); // config output

    SetBit_Reg8(led.port, led.index); delay_ms(500);
    ClearBit_Reg8(led.port, led.index); delay_ms(1000);

    WriteBit_Reg8(led.port, led.index, 1); delay_ms(500);
    WriteBit_Reg8(led.port, led.index, 0); delay_ms(1000);

    ToggleBit_Reg8(led.port, led.index); delay_ms(500);
    ToggleBit_Reg8(led.port, led.index); delay_ms(1000);


    SetBitMask_Reg8(led2.ddr, led2.mask); delay_ms(1000); // config output

    SetBitMask_Reg8(led2.port, led2.mask); delay_ms(500);
    ClearBitMask_Reg8(led2.port, led2.mask); delay_ms(1000);

    ToggleBitMask_Reg8(led2.port, led2.mask); delay_ms(500);
    ToggleBitMask_Reg8(led2.port, led2.mask); delay_ms(1000);


    ClearBit_Reg8(key.ddr, key.index); delay_ms(10);  // config input
    SetBit_Reg8(key.port, key.index); delay_ms(10);   // config pull-up

    while(1){
         WriteBit_Reg8(led.port, led.index, ReadBit_Reg8(key.pin, key.index));
         WriteBit_Reg8(led2.port, led2.index, ReadBitMask_Reg8(key.pin, key.mask));
    };
}




