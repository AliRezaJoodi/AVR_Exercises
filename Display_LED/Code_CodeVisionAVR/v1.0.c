// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>  

#include "Attachment\HardwarePorting_v1.0.h" 
#include <Out.h>

void main(void){
    Out_Config();
    
    LED1=OUT1_ACTIVATE;
    LED2_TURNON; delay_ms(1000); LED2_TURNOFF;
    
    while(1){ 
    }
}

