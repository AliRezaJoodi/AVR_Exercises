// GitHub Account:  GitHub.com/AliRezaJoodi
// MCU Frequency:   8Mhz

#include <io.h>
#include <delay.h>

#ifndef _BUZZER_INCLUDED
#define _BUZZER_INCLUDED

#ifndef BUZZER_HARDWARE
#define BUZZER_HARDWARE
    #define BUZZER_ACTIVE       1     
    #define BUZZER_DDR          DDRB.1
    #define BUZZER_PORT         PORTB.1
    #define BUZZER_PIN          PINB.1  
#endif

#define BEEP_UP         0
#define BEEP_DOWN       1
#define BEEP_SET        2
#define BEEP_ERROR      3

void Buzzer_Config(void);

#pragma used+
void Buzzer_MakeBeep_UpOrDownSound(void);
void Buzzer_MakeBeep_SetSound(void);
void Buzzer_MakeBeep_ErrorSound(void);
void Buzzer_MakeBeep(char);
#pragma used-

#pragma library buzzer.lib

#endif
