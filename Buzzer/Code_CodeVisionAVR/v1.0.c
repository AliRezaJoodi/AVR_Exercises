// GitHub Account: GitHub.com/AliRezaJoodi
// MCU Frequency: 8Mhz

#include <mega32a.h>
#include <delay.h>

#include "Attachment\Buzzer.h"

void main(void){  
    ConfigBuzzer(); 
    
    MakeBeep1(); delay_ms(1000);
    MakeBeep2(); delay_ms(1000);
    MakeBeep3(); delay_ms(1000);
     
    while(1){

    }
}



