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
    
    #define ACTIVE_BUZZER       1 
    #define TIMER_PERIOD        8                   //ms
    #define BEEZER_ACTIVE_TIME  80/TIMER_PERIOD     //ms 
    #define PERIOD1             5000/TIMER_PERIOD   //ms 
    #define PERIOD2             2000/TIMER_PERIOD   //ms      
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
        ++i; if(i>=BEEZER_ACTIVE_TIME){BUZZER=!ACTIVE_BUZZER; i=0; *status=0;}   
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
        if(i>=(PERIOD1+(2*BEEZER_ACTIVE_TIME))){active=1;i=0;}
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
        if(i>=(PERIOD2+(5*BEEZER_ACTIVE_TIME))){active=1;i=0;}
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
