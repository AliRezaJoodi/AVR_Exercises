// GitHub Account: GitHub.com/AliRezaJoodi
// MCU Frequency: 8Mhz

#include <mega16.h>
#include <delay.h>

#include "Attachment\Buzzer.h"

char single_beep_mode=0;

void main(void){  
    ConfigBuzzer(); 
    
    DriveBuzzer(SET_BEEP);
     
    while(1){
        DriveBuzzer(single_beep_mode);
        
        single_beep_mode=ERROR_BEEP; delay_ms(3000); 
    }
}



