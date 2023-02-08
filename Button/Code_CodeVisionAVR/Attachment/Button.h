// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _BUTTON_INCLUDED_
    #define _BUTTON_INCLUDED_

#include <delay.h>

#ifndef _BUTTON_PORTS_
    #define _BUTTON_PORTS_

    #define BUTTON1_DDR         DDRB.0
    #define BUTTON1_PORT        PORTB.0
    #define BUTTON1_PIN         PINB.0
    #define BUTTON1             BUTTON1_PIN
    
    #define BUTTON2_DDR         DDRB.1
    #define BUTTON2_PORT        PORTB.1
    #define BUTTON2_PIN         PINB.1
    #define BUTTON2             BUTTON2_PIN
    
    #define BUTTON3_DDR         DDRB.2
    #define BUTTON3_PORT        PORTB.2
    #define BUTTON3_PIN         PINB.2
    #define BUTTON3             BUTTON3_PIN
    
    #define PRESSED             0    
#endif
      
//*************************************************
void Config_Button(void){
    BUTTON1_DDR=0; BUTTON1_PORT=!PRESSED;
}

#pragma used+

//*************************************************
unsigned char Set_Button(void){
    static bit last_status=!PRESSED; 
    
    if(BUTTON3==PRESSED && last_status==!PRESSED){
        delay_ms(30);
        if(BUTTON3==PRESSED){
            last_status=PRESSED;
            return 1;
        } 
    }
    if(BUTTON3==!PRESSED){last_status=!PRESSED;} 
    return 0;
}

//*************************************************
void IncreaseOneStep_Button(unsigned char *number){
    static bit last_status=!PRESSED; 
    
    if(BUTTON1==PRESSED && last_status==!PRESSED){
        delay_ms(30);
        if(BUTTON1==PRESSED){
            last_status=PRESSED;
            *number=*number+1; 
        } 
    }
    if(BUTTON1==!PRESSED){last_status=!PRESSED;}
}

//*************************************************
void IncreaseContinuously_Button(unsigned char *number){
    static unsigned int i=0;
    
    if(BUTTON2==PRESSED){
        ++i;
        if(i>=1000){
            i=0;
            *number=*number+1;  
        } 
    }
}

#pragma used-
#endif
