// GitHub Account:  GitHub.com/AliRezaJoodi
// MCU Frequency:   8Mhz

#include <mega16a.h>
#include <delay.h>

#include "hardware.h"
#include "buzzer.h"

void main(void){
    Buzzer_Config();

    Buzzer_MakeBeep_UpOrDownSound(); delay_ms(2000);
    Buzzer_MakeBeep_SetSound(); delay_ms(2000);
    Buzzer_MakeBeep_ErrorSound(); delay_ms(2000);

    Buzzer_MakeBeep(BEEP_UP); delay_ms(2000);

    while(1){

    }
}



