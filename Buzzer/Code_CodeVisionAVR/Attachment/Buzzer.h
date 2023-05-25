// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef INCLUDED_BUZZER
    #define INCLUDED_BUZZER

#include <delay.h>

#ifndef PORTS_BUZZER
    #define PORTS_BUZZER

    #define ACTIVE_BUZZER   1     
    #define BUZZER_DDR      DDRB.1
    #define BUZZER_PORT     PORTB.1
    #define BUZZER_PIN      PINB.1 
    #define BUZZER          BUZZER_PORT 
#endif

//Single beep_mode
#define UP_DOWN_BEEP    1
#define SET_BEEP        2
#define ERROR_BEEP      3

//********************************************************
void ConfigBuzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVE_BUZZER;
}

#pragma used+

//*******************************************************
void _MakeUpOrDownBeep(void){
    BUZZER=ACTIVE_BUZZER;
    delay_ms(80);
    BUZZER=!ACTIVE_BUZZER;  
}

//*******************************************************
void _MakeSetBeep(void){    
    BUZZER=ACTIVE_BUZZER;
    delay_ms(220);
    BUZZER=!ACTIVE_BUZZER;
}

//*******************************************************
void _MakeErrorBeep(void){
    BUZZER=ACTIVE_BUZZER;
    delay_ms(500);
    BUZZER=!ACTIVE_BUZZER;  
}

//*******************************************************
// Call in Main
void DriveBuzzer(char mode){    
    switch(mode){
        case UP_DOWN_BEEP:
            _MakeUpOrDownBeep();
            break;
        case SET_BEEP: 
            _MakeSetBeep();
            break;
        case ERROR_BEEP: 
            _MakeErrorBeep();
            break;
    }
} 

#pragma used-

#endif
