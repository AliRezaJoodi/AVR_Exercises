// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef _BUZZER_INCLUDED_
    #define _BUZZER_INCLUDED_

#ifndef _BUZZER_PORTS_
    #define _BUZZER_PORTS_
    
    #define BUZZER_DDR      DDRB.0
    #define BUZZER_PORT     PORTB.0
    #define BUZZER_PIN      PINB.0 
    #define BUZZER          BUZZER_PORT 
    
    #define ACTIVE_BUZZER   1       
#endif

#pragma used+

//********************************************************
void Config_Buzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVE_BUZZER;
}

//*******************************************************
void S1_Buzzer(char *status){
    static unsigned char i=0;
    if(*status){ 
        BUZZER=ACTIVE_BUZZER; 
        ++i; if(i>=10){BUZZER=!ACTIVE_BUZZER; i=0; *status=0;}   
    }
}

//*******************************************************
void S2_Buzzer(char mode){
    static unsigned int i1=0; 
    static unsigned int i2=0; 
    static char active=0;
    
    S1_Buzzer(&active);
    
    switch (mode){ 
        case 1:
            ++i1;  
            if(i1>=625){active=1;i1=0;} 
            break;
        case 2:
            ++i1; 
            if(i1==625){active=1;}  
            if(i1>=650){active=1;i1=0;} 
            break;
        case 3:
            ++i1; 
            if(i1>=250){active=1;}  
            if(i1>=300){active=1;i1=0;}
            break;  
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
