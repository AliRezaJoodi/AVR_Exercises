// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega16a.h>
#include <delay.h>

#include "Attachment\Watchdog.h"

void main(void){
    ConfigWatchdog(); 

    DDRC.5=1; PORTC.5=1;
    DDRD.3=1; PORTD.3=0;
        
    delay_ms(200); PORTC.5=0;

    while(1){ 
        ResetWatchdog(); 
        PORTD.3=!PORTD.3; //delay_ms(250);
    };
}