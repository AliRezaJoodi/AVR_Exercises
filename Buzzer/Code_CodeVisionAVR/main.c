// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega16a.h>
#include <delay.h>

#include "hardware.h"
#include "buzzer.h"

void main(void){
    Buzzer_Init();

    Buzzer_Start(BUZZER_COUNT2);

    while(1){
        Buzzer_Refresh();
    }
}



