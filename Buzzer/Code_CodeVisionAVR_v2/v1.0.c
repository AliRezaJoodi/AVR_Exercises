// GitHub Account: GitHub.com/AliRezaJoodi
// MCU Frequency: 8Mhz

#include <mega16.h>
#include <delay.h>
#include "Attachment\Buzzer.h"

void main(void){ 
    ConfigBuzzer(); 
    
    single_beep=1;        
    beep_mode=1;    //0 or 1 or 2 or 3
     
    while(1){
        RunTheBuzzerTasks();  
    }
}




