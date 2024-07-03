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

#define BUTTON1             BUTTON1_PIN
#define BUTTON2             BUTTON2_PIN
#define BUTTON3             BUTTON3_PIN
          
//*************************************************
void Button_Config(void){
    #ifndef INPUT
        #define INPUT   0
    #endif

    BUTTON1_DDR=INPUT; BUTTON1_PORT=!PRESSED;  
    BUTTON2_DDR=INPUT; BUTTON2_PORT=!PRESSED;
    BUTTON3_DDR=INPUT; BUTTON3_PORT=!PRESSED;
}

#pragma used+

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

#pragma used-
#endif
