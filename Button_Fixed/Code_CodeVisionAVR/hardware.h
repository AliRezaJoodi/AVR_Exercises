// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED


#define _BUTTON_FIXED_HARDWARE    
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
