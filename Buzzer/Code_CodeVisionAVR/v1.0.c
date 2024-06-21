// GitHub Account: GitHub.com/AliRezaJoodi
// MCU Frequency: 8Mhz
// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega16.h>
#include <delay.h>

#include "Attachment\Buzzer.h"

void main(void){  
    Buzzer_Config(); 
    Buzzer_MakeBeep(BEEP_SET);
     
    while(1){
        Buzzer_MakeBeep(BEEP_ERROR);
        delay_ms(3000); 
    }
}



