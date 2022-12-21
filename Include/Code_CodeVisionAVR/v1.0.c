//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include "Attachment\Hardware_v1.0.h"
void Config_IO(void);

bit status_button1=1;
bit status_button2=1;

void main(void){        
    Config_IO();        
    while(1){
        if(BUTTON1==PRESS_BUTTON && status_button1==DEFAULT_BUTTON){
            status_button1=PRESS_BUTTON;
            LED1=ACTIVATE_LED;
        }
        if(BUTTON1==DEFAULT_BUTTON){status_button1=DEFAULT_BUTTON;} 
        
        if(BUTTON2==PRESS_BUTTON && status_button2==DEFAULT_BUTTON){
            status_button2=PRESS_BUTTON;
            LED1=DEACTIVATE_LED;
        }
        if(BUTTON2==DEFAULT_BUTTON){status_button2=DEFAULT_BUTTON;}  
    }
}

//******************************************
void Config_IO(void){ 
    #define INPUT 0   
    #define OUTPUT !INPUT
    #define PULL_UP 1
    #define PULL_DOWN !PULL_UP
    
    BUTTON1_DDR=INPUT; BUTTON1_PORT=PULL_UP;
    BUTTON2_DDR=INPUT; BUTTON2_PORT=PULL_UP;
    LED1_DDR=OUTPUT; LED1_PORT=DEFAULT_LED;
}


