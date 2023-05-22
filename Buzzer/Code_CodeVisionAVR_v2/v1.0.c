// GitHub Account:     GitHub.com/AliRezaJoodi
// MCU Frequency: 8Mhz

#include <mega16.h>

#include "Attachment\Buzzer.h"

void main(void){  
    ConfigBuzzer(); 
        
    single_beep=1;
    periodical_single_beep=0;
    periodical_double_beep=1;
    periodical_continuous_beep=0;
     
    while(1){

    }
}




