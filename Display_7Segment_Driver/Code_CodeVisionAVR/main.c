// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
#include <io.h>

#include "hardware.h"
#include "drivers/seg7_driver.h"

void main(void){
    uint8_t segments[8] = {
        0x3FU,  /* 0 */
        0x06U,  /* 1 */
        0x5BU,  /* 2 */
        0x4FU,  /* 3 */
        0x66U,  /* 4 */
        0x6DU,  /* 5 */
        0x7DU,  /* 6 */
        0x07U   /* 7 */
    };

//    DDRD = 0xFF; PORTD = ~segments[7];
//    DDRB = 0xFF; PORTB.0 = 1;
    Seg7_Init();
    Seg7_SetBuffer(&segments[0]);

    while(1){
        Seg7_Refresh(); delay_ms(5);
    };
}
