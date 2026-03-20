// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega16a.h>
#include <delay.h>

#include "hardware.h"
#include "buzzer.h"

void main(void){
    Buzzer_Init();

    Buzzer_MakeBeep_UpDown(); delay_ms(2000);
    Buzzer_MakeBeep_Set(); delay_ms(2000);
    Buzzer_MakeBeep_Error(); delay_ms(2000);

    Buzzer_Active(BUZZER_COUNT2);

    while(1){
        Buzzer_Refresh();
    }
}



