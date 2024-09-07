// GitHub Account: GitHub.com/AliRezaJoodi

#include <io.h>
#include <delay.h>

#ifndef _BUTTON_INCLUDED
#define _BUTTON_INCLUDED
    
#ifndef _BUTTON_HARDWARE
#define _BUTTON_HARDWARE
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

#define _BUTTON_Delay_ms(VALUE) delay_ms(VALUE);

#ifdef BUTTON1_DDR
    #define BUTTON1             BUTTON1_PIN
    #define BUTTON1_CONFIG      BUTTON1_DDR=0; BUTTON1_PORT=!PRESSED;
#endif

#ifdef BUTTON2_DDR
    #define BUTTON2             BUTTON2_PIN 
    #define BUTTON2_CONFIG      BUTTON2_DDR=0; BUTTON2_PORT=!PRESSED;
#endif

#ifdef BUTTON3_DDR
    #define BUTTON3             BUTTON3_PIN
    #define BUTTON3_CONFIG      BUTTON3_DDR=0; BUTTON3_PORT=!PRESSED;
#endif
          
void Button_Config(void);

#pragma used+

#ifdef BUTTON1
    char Button1_OneStep(void);
    char Button1_Continuous(void);
#endif

#ifdef BUTTON2
    char Button2_OneStep(void);
    char Button2_Continuous(void);
#endif

#ifdef BUTTON3 
    char Button3_OneStep(void);
    char Button3_Continuous(void);
#endif

#pragma used-

#pragma library button.lib

#endif
