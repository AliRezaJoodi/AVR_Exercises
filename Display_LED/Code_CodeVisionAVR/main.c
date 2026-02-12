// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>  

#include "hardware.h"
 
void Output_Init(void);

void main(void){
    Output_Init();
    
    while(1){ 
        LED1 = OUT1_ACTIVE; delay_ms(500);
        LED1 = !OUT1_ACTIVE; delay_ms(500);
    }
}

//**********************************    
void Output_Init(void){ 
    OUT1_DDR = 1; 
    OUT1_PORT =! OUT1_ACTIVE;
}


