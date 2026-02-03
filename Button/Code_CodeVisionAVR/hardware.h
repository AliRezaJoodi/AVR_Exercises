#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED


#define BUTTON_HARDWARE
    #define BUTTON_PRESSED              0
    #define BUTTON_SINGLE_CLICK_LAG     30          // Single Click Lag, Value: 0~65535, Unit: ms  
    #define BUTTON_AUTO_REPEAT_LAG      500         // Auto Repeat Lag, Value: 0~65535
    #define BUTTON_LONG_PRESS_LAG       10000       // Long Press Lag, Value: 0~65535
    
#define BUTTON_HARDWARE_EXTRA    
    #define BUTTON1_DDR         DDRB
    #define BUTTON1_PIN         PINB
    #define BUTTON1_PORT        PORTB
    #define BUTTON1_BIT         0 
    
#define BUTTON2_DDR         DDRB
#define BUTTON2_PIN         PINB
#define BUTTON2_PORT        PORTB
#define BUTTON2_BIT         1
    
#define BUTTON3_DDR         DDRB
#define BUTTON3_PIN         PINB
#define BUTTON3_PORT        PORTB
#define BUTTON3_BIT         2  


#endif

       
