// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef INCLUDED_BUZZER
    #define INCLUDED_BUZZER

#include <delay.h>

#ifndef PORTS_BUZZER
    #define PORTS_BUZZER
    
    #define BUZZER_DDR              DDRB.1
    #define BUZZER_PORT             PORTB.1
    #define BUZZER_PIN              PINB.1 
    #define BUZZER                  BUZZER_PORT 
    
    #define ACTIVESTATUS_BUZZER     1 
    #define ACTIVETIME_BUZZER       10    // Sound Period/Call Period  ==> 80ms/8ms
    #define PERIOD1                 625   // Sound Period/Call Period  ==> 5000ms/8ms
    #define PERIOD2                 250   // Sound Period/Call Period  ==> 2000ms/8ms       
#endif


//********************************************************
void Config_Buzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVESTATUS_BUZZER;
}

#pragma used+

//*******************************************************
//Be Called Periodically
//Single Beep
void Beep_Buzzer(char *status){
    static unsigned char i=0;
    if(*status){ 
        BUZZER=ACTIVESTATUS_BUZZER; 
        ++i; if(i>=ACTIVETIME_BUZZER){BUZZER=!ACTIVESTATUS_BUZZER; i=0; *status=0;}   
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
        if(i>=(PERIOD1+(2*ACTIVETIME_BUZZER))){active=1;i=0;}
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
        if(i>=(PERIOD2+(5*ACTIVETIME_BUZZER))){active=1;i=0;}
        Beep_Buzzer(&active);
    }
}

//*******************************************************
void Sound1_Buzzer(void){
    unsigned int i;
    for (i=0;i<=350;++i) {
        BUZZER=ACTIVESTATUS_BUZZER; delay_us(150);
        BUZZER=!ACTIVESTATUS_BUZZER; delay_us(150);
    };   
}

//*******************************************************
void Sound2_Buzzer(void){
    unsigned int i;
    for (i=0;i<=100;++i) {
        BUZZER=ACTIVESTATUS_BUZZER; delay_us(400);
        BUZZER=!ACTIVESTATUS_BUZZER; delay_us(400);
    };  
}

//*******************************************************
void Sound3_Buzzer(void){
    unsigned int i;
    for (i=0;i<=30;++i) {
        BUZZER=ACTIVESTATUS_BUZZER; delay_ms(2);
        BUZZER=!ACTIVESTATUS_BUZZER; delay_ms(2);
    };   
}

#pragma used-

#endif
