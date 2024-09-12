// GitHub Account: GitHub.com/AliRezaJoodi

#include <io.h>
#include <delay.h>

#ifndef _BUTTON_INCLUDED
#define _BUTTON_INCLUDED
    
#ifndef BUTTON_HARDWARE
#define BUTTON_HARDWARE
    #define PRESSED             0 
    #define BUTTONLAG1          30        //ms 
    #define BUTTONLAG2          1000      //Button Lag
        
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
          
void Button_Config(void);

#pragma used+

#ifdef BUTTON1_PIN
    char Button1_OneStep(void);
    char Button1_Continuous(void);
#endif

#ifdef BUTTON2_PIN
    char Button2_OneStep(void);
    char Button2_Continuous(void);
#endif

#ifdef BUTTON3_PIN 
    char Button3_OneStep(void);
    char Button3_Continuous(void);
#endif

#pragma used-

#pragma library button.lib

#endif
