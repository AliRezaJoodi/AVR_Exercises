//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include "Attachment\Buzzer.h"

void main(void){ 
    char status_buzzer=1;
    Config_Buzzer(); 
    
    Sound1_Buzzer(); delay_ms(500);
    Sound2_Buzzer(); delay_ms(500);
    Sound3_Buzzer(); delay_ms(1000);
            
    while(1){
        delay_ms(8); 
        S1_Buzzer(&status_buzzer);
        S2_Buzzer(2);
    }
}




