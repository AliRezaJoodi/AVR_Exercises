// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
#include <io.h>

#include "hardware.h"
#include "seg7_driver.h"

void main(void){
    uint8_t segments[8] = {
        0x3FU,
        0x06U,
        0x5BU,
        0x4FU,
        0x66U,
        0x6DU,
        0x7DU,
        0x07U
    };

//    DDRD = 0xFF; PORTD = ~segments[7];
//    DDRB = 0xFF; PORTB.0 = 1;
    Seg7_Init();
    Seg7_SetBuffer(&segments[0]);

    while(1){
        Seg7_Refresh(); delay_ms(5);
    };
}
