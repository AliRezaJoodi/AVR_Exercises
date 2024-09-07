// GitHub Account:  GitHub.com/AliRezaJoodi
// MCU Frequency:   8Mhz

#include <mega32a.h>
#include <delay.h>

#include "Attachment\hardware_v1.0.h"
#include <buzzer.h>

void main(void){  
    Buzzer_Config(); 
    Buzzer_MakeBeep_SetSound();
     
    while(1){
        delay_ms(3000);
        Buzzer_MakeBeep(BEEP_ERROR);
    }
}



