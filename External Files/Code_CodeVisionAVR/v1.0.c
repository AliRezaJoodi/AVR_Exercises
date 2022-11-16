//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include "Attachment\Hardware_v1.0.h"
void Config_IO(void);

bit button1_status=1;
bit button2_status=1;

void main(void){        
    Config_IO();        
    while(1){
        if(BUTTON1==PRESS_BUTTON && button1_status==DEFAULT_BUTTON){
            button1_status=PRESS_BUTTON;
            LED1=ACTIVATE_LED;
        }
        if(BUTTON1==DEFAULT_BUTTON){button1_status=DEFAULT_BUTTON;} 
        
        if(BUTTON2==PRESS_BUTTON && button2_status==DEFAULT_BUTTON){
            button2_status=PRESS_BUTTON;
            LED1=DEACTIVATE_LED;
        }
        if(BUTTON2==DEFAULT_BUTTON){button2_status=DEFAULT_BUTTON;}  
    }
}

//******************************************
void Config_IO(void){    
    #define OUTPUT 1
    #define INPOUT 0
    #define PULL_UP 1
    #define PULL_DOWN 0
    
    BUTTON1_DDR=INPOUT; BUTTON1_PORT=PULL_UP;
    BUTTON2_DDR=INPOUT; BUTTON2_PORT=PULL_UP;
    LED1_DDR=OUTPUT; LED1_PORT=DEFAULT_LED;
}


