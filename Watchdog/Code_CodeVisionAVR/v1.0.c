// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega16a.h>
#include <delay.h>

#include "Attachment\Watchdog.h"

void main(void){
    ConfigWatchdog(); 

    DDRC.5=1; PORTC.5=1;
    DDRD.3=1; PORTD.3=0;
     
    DDRA=0b11111111; PORTA=0b00000000;
    DDRB=0b11111111; PORTB=0b00000000;
    
    ///#asm("sei")
    delay_ms(200); PORTC.5=0;
    ///MCUCSR=MCUCSR & 0b11110111;
    
    while(1){
        PORTA=WDTCR; 
        PORTB=MCUCSR;
        //ResetWatchdog();
        ///MCUCSR=MCUCSR & 0b11110111; 
        PORTD.3=!PORTD.3; //delay_ms(1);
    };
}