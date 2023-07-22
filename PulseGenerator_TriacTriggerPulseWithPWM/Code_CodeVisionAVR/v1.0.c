// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega16a.h>
#include <delay.h>

#define INT_GLOBAL_ENABLE          #asm("sei") // Globally enable interrupts

#include "Attachment\Timer0.h"

interrupt [EXT_INT0] void ext_int0_isr(void){
    T0_END; 
}

void ConfigINT0_RisingEdge(void);

void main(void){ 
    
    ConfigINT0_RisingEdge();    
    ConfigTimer0ForPWM();
    T0_OC0_INVERTED; 
    OCR0=140;    //From min to max with 153~0

    INT_GLOBAL_ENABLE;
     
    while(1){  
    }
}

//*****************************************
void ConfigINT0_RisingEdge(void){
    DDRD.2=0; PORTD.2=1;
    
// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Rising Edge
// INT1: Off
// INT2: Off
GICR|=(0<<INT1) | (1<<INT0) | (0<<INT2);
MCUCR=(0<<ISC11) | (0<<ISC10) | (1<<ISC01) | (1<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(0<<INTF1) | (1<<INTF0) | (0<<INTF2);
}





