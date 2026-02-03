// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _BUTTON_FIXED_INCLUDED
#define _BUTTON_FIXED_INCLUDED


#include <io.h>
#include <delay.h>

#include "hardware.h"

#ifndef BUTTON_FIXED_HARDWARE
#define BUTTON_FIXED_HARDWARE
    #warning "BUTTON_FIXED_HARDWARE is not defined; default configuration will be used."    
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

char Button1_SingleClick(void);
char Button1_AutoRepeat_NonBlocking(void);

char Button2_SingleClick(void);
char Button2_AutoRepeat_NonBlocking(void);

char Button3_SingleClick(void);
char Button3_AutoRepeat_NonBlocking(void);

#pragma used-

#pragma library button_fixed.lib

#endif
