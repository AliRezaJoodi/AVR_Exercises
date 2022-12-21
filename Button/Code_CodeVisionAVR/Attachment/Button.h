// GitHub Account:     GitHub.com/AliRezaJoodi

#include <delay.h>

#ifndef PRESS_BUTTON
    #define PRESS_BUTTON 0
#endif
#define DEFAULT_BUTTON !PRESS_BUTTON
    
#ifndef BUTTON1_DDR    
    #define BUTTON1_DDR DDRB.0
    #define BUTTON1_PORT PORTB.0
    #define BUTTON1_PIN PINB.0
#endif
#define BUTTON_INCR BUTTON1_PIN
    
//*************************************************
void Config_Button(void){
    BUTTON1_DDR=0; BUTTON1_PORT=1;
}

//*************************************************
void GetIncr_Button(unsigned char *number){
    static bit status_button1=DEFAULT_BUTTON; 
    
    static bit status_confige=0;
    if(status_confige==0){Config_Button(); status_confige=1;}
    
    if(BUTTON_INCR==PRESS_BUTTON && status_button1==DEFAULT_BUTTON){
        delay_ms(30);
        if(BUTTON_INCR==PRESS_BUTTON){
            *number=*number+1; 
            status_button1=PRESS_BUTTON;
        } 
    }
    if(BUTTON_INCR==DEFAULT_BUTTON){status_button1=DEFAULT_BUTTON;}
}