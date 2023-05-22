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


//********************************************************
void ConfigBuzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVE_BUZZER;
}

#pragma used+

//*******************************************************
void MakeBeep1(void){
    unsigned int i;
    for (i=0;i<=350;++i) {
        BUZZER=ACTIVE_BUZZER; delay_us(150);
        BUZZER=!ACTIVE_BUZZER; delay_us(150);
    };   
}

//*******************************************************
void MakeBeep2(void){
    unsigned int i;
    for (i=0;i<=100;++i) {
        BUZZER=ACTIVE_BUZZER; delay_us(400);
        BUZZER=!ACTIVE_BUZZER; delay_us(400);
    };  
}

//*******************************************************
void MakeBeep3(void){
    unsigned int i;
    for (i=0;i<=30;++i) {
        BUZZER=ACTIVE_BUZZER; delay_ms(2);
        BUZZER=!ACTIVE_BUZZER; delay_ms(2);
    };   
}

#pragma used-

#endif
