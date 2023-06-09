//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <string.h>

char mode=1;

struct load{
    float volt;
    float amp;  
}device1={15,2};

//#define TURN_OFF_THE_LCD    
#include "Attachment\DisplayManager.h"
    
void main(void){
    ConfigLCD();

    mode=0; DisplayValuesOnTheLCD(mode); delay_ms(500);
    
    mode=1;
    device1.volt=30; 
    DisplayValuesOnTheLCD(mode);
    
    while(1){
    };
}



