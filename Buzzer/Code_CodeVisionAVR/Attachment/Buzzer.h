// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef _BUZZER_INCLUDED_
    #define _BUZZER_INCLUDED_

#include <delay.h>

#ifndef _BUZZER_PORTS_
    #define _BUZZER_PORTS_
    
    #define BUZZER_DDR          DDRB.1
    #define BUZZER_PORT         PORTB.1
    #define BUZZER_PIN          PINB.1 
    #define BUZZER              BUZZER_PORT 
    
    #define ACTIVE_BUZZER           1 
    #define BUZZER_ACTIVITY_TIME    10    // 80ms/Timer Period(8ms) 
    #define PERIOD1                 625   // 5000ms/Timer Period(8ms) 
    #define PERIOD2                 250   // 2000ms/Timer Period(8ms)      
#endif

#pragma used+

//********************************************************
void Config_Buzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVE_BUZZER;
}

//*******************************************************
//Be Called Periodically
//Single Beep
void Beep_Buzzer(char *status){
    static unsigned char i=0;
    if(*status){ 
        BUZZER=ACTIVE_BUZZER; 
        ++i; if(i>=BUZZER_ACTIVITY_TIME){BUZZER=!ACTIVE_BUZZER; i=0; *status=0;}   
    }
}

//*******************************************************
//Be Called Periodically
//Periodicall Single Beep
void P1_Buzzer(char status){
    static unsigned int i=0;
    static char active=0; 
    
    if(status){
        ++i;  
        if(i>=PERIOD1){active=1;i=0;} 
        Beep_Buzzer(&active);
    }
}

//*******************************************************
//Be Called Periodically
//Periodicall 2-Beep
void P2_Buzzer(char status){
    static unsigned int i=0;
    static char active=0; 

    if(status){
        ++i; 
        if(i==PERIOD1){active=1;}  
        if(i>=(PERIOD1+(2*BUZZER_ACTIVITY_TIME))){active=1;i=0;}
        Beep_Buzzer(&active);
    }
}

//*******************************************************
//Be Called Periodically
//Periodicall Continuous Beep
void PC_Buzzer(char status){
    static unsigned int i=0;
    static char active=0; 

    if(status){
        ++i; 
        if(i>=PERIOD2){active=1;}  
        if(i>=(PERIOD2+(5*BUZZER_ACTIVITY_TIME))){active=1;i=0;}
        Beep_Buzzer(&active);
    }
}

//*******************************************************
void Sound1_Buzzer(void){
    unsigned int i;
    for (i=0;i<=350;++i) {
        BUZZER=ACTIVE_BUZZER; delay_us(150);
        BUZZER=!ACTIVE_BUZZER; delay_us(150);
    };   
}

//*******************************************************
void Sound2_Buzzer(void){
    unsigned int i;
    for (i=0;i<=100;++i) {
        BUZZER=ACTIVE_BUZZER; delay_us(400);
        BUZZER=!ACTIVE_BUZZER; delay_us(400);
    };  
}

//*******************************************************
void Sound3_Buzzer(void){
    unsigned int i;
    for (i=0;i<=30;++i) {
        BUZZER=ACTIVE_BUZZER; delay_ms(2);
        BUZZER=!ACTIVE_BUZZER; delay_ms(2);
    };   
}

#pragma used-

#endif
