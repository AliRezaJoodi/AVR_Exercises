//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
//#include <string.h>

char mode=1;

struct load{
    float volt;
    float amp;
    float volt_sp;
    float amp_sp;  
};
struct load device1;

//#define TURN_OFF_LCD    
#include "Attachment\DisplayManager.h"
    
void main(void){
    ConfigLCD();
    DDRC.0=0; PORTC.0=1;
     
    display.mode=LOADING_PAGE; DisplayValuesOnTheLCD();
    display.mode=AD_PAGE; DisplayValuesOnTheLCD();
     
    device1.volt=30; device1.amp=2;
    device1.volt_sp=35; device1.amp_sp=10;
    display.mode=MAIN_PAGE;
    
    while(1){ 
        DisplayValuesOnTheLCD();
        delay_ms(250);
        if(PINC.0==0){ 
            ++display.mode; if(display.mode>SETAMP_PAGE){display.mode=MAIN_PAGE;}
            //delay_ms(250);    
        }
    };
}



