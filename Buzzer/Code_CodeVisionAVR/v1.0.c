// GitHub Account:  GitHub.com/AliRezaJoodi
// MCU Frequency:   8Mhz

#include <mega16.h>
#include <delay.h>

#include "Attachment\HardwarePorting_v1.0.h"
#include <Buzzer.h>

void main(void){  
    Buzzer_Config(); 
    Buzzer_MakeBeep(BEEP_SET);
     
    while(1){
        delay_ms(3000);
        Buzzer_MakeBeep(BEEP_ERROR);
    }
}



