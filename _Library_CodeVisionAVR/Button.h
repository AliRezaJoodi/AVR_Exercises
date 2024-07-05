// GitHub Account: GitHub.com/AliRezaJoodi

#include <delay.h>

#ifndef _BUTTON_INCLUDED
#define _BUTTON_INCLUDED
    
#ifndef _BUTTON_PORTS
#define _BUTTON_PORTS
    #define PRESSED             0  
    #define BUTTONLAG           1000      //Button Lag: 0~65535
        
    #define BUTTON1_DDR         DDRB.0
    #define BUTTON1_PORT        PORTB.0
    #define BUTTON1_PIN         PINB.0
    
    #define BUTTON2_DDR         DDRB.1
    #define BUTTON2_PORT        PORTB.1
    #define BUTTON2_PIN         PINB.1
    
    #define BUTTON3_DDR         DDRB.2
    #define BUTTON3_PORT        PORTB.2
    #define BUTTON3_PIN         PINB.2  
#endif

#ifdef BUTTON1_DDR
    #define BUTTON1             BUTTON1_PIN
#endif

#ifdef BUTTON2_DDR
    #define BUTTON2             BUTTON2_PIN
#endif

#ifdef BUTTON3_DDR
    #define BUTTON3             BUTTON3_PIN
#endif
          
//*************************************************
void Button_Config(void){
    #ifdef BUTTON1_DDR   
        BUTTON1_DDR=0; BUTTON1_PORT=!PRESSED;
    #endif

    #ifdef BUTTON2_DDR  
        BUTTON2_DDR=0; BUTTON2_PORT=!PRESSED;
    #endif

    #ifdef BUTTON3_DDR
        BUTTON3_DDR=0; BUTTON3_PORT=!PRESSED; 
    #endif
}

#pragma used+

#ifdef BUTTON1_DDR
//*************************************************
char Button1_OneStep(void){
    static bit last_status=!PRESSED; 
    
    if(BUTTON1==PRESSED && last_status==!PRESSED){
        delay_ms(30);
        if(BUTTON1==PRESSED){
            last_status=PRESSED;
            return 1; 
        } 
    }
    if(BUTTON1==!PRESSED){last_status=!PRESSED;}
    
    return 0; 
}

//*************************************************
char Button1_Continuous(void){
    static unsigned int i=0;
        
    if(BUTTON1==PRESSED){
        ++i;
        if(i>=BUTTONLAG){i=0; return 1;} 
    }
    
    return 0; 
}
#endif

#ifdef BUTTON2_DDR 
//*************************************************
char Button2_OneStep(void){
    static bit last_status=!PRESSED; 
    
    if(BUTTON2==PRESSED && last_status==!PRESSED){
        delay_ms(30);
        if(BUTTON2==PRESSED){
            last_status=PRESSED;
            return 1; 
        } 
    }
    if(BUTTON2==!PRESSED){last_status=!PRESSED;}
    
    return 0; 
}

//*************************************************
char Button2_Continuous(void){
    static unsigned int i=0;
        
    if(BUTTON2==PRESSED){
        ++i;
        if(i>=BUTTONLAG){i=0; return 1;} 
    }
    
    return 0; 
}
#endif

#ifdef BUTTON3_DDR 
//*************************************************
char Button3_OneStep(void){
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
char Button3_Continuous(void){
    static unsigned int i=0;
        
    if(BUTTON3==PRESSED){
        ++i;
        if(i>=BUTTONLAG){i=0; return 1;} 
    }
    
    return 0; 
}
#endif

#pragma used-
#endif
