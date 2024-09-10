// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>  

#include "Attachment\hardware_v1.0.h" 
#include <output.h>

void main(void){
    Output_Config();
    
    LED1=OUT1_ACTIVE;
    LED2_TURNON; delay_ms(1000); LED2_TURNOFF;
    
    while(1){ 
    }
}

