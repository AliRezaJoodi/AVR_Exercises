// GitHub Account: GitHub.com/AliRezaJoodi

#include <delay.h> 

#ifndef _OUTPUT_INCLUDED
#define _OUTPUT_INCLUDED

#ifndef OUT1_HARDWARE
#define OUT1_HARDWARE
    #define OUT1_DDR        DDRA.1
    #define OUT1_PORT       PORTA.1
    #define OUT1_PIN        PINA.1 
    #define OUT1_ACTIVE     1
#endif

/*
#ifndef OUT2_HARDWARE
#define OUT2_HARDWARE    
    #define OUT2_DDR        DDRA.2
    #define OUT2_PORT       PORTA.2
    #define OUT2_PIN        PINA.2 
    #define OUT2_ACTIVE     1
#endif 

#ifndef OUT3_HARDWARE
#define OUT3_HARDWARE
    #define OUT3_DDR        DDRA.3
    #define OUT3_PORT       PORTA.3
    #define OUT3_PIN        PINA.3 
    #define OUT3_ACTIVE     1
#endif

#ifndef OUT4_HARDWARE
#define OUT4_HARDWARE
    #define OUT4_DDR        DDRA.4
    #define OUT4_PORT       PORTA.4
    #define OUT4_PIN        PINA.4 
    #define OUT4_ACTIVE     1
#endif
 
#ifndef OUT5_HARDWARE
#define OUT5_HARDWARE
    #define OUT5_DDR        DDRA.5
    #define OUT5_PORT       PORTA.5
    #define OUT5_PIN        PINA.5
    #define OUT5_ACTIVE     1 
#endif

#ifndef OUT6_HARDWARE
#define OUT6_HARDWARE
    #define OUT6_DDR        DDRA.6
    #define OUT6_PORT       PORTA.6
    #define OUT6_PIN        PINA.6
    #define OUT6_ACTIVE     1 
#endif

#ifndef OUT7_HARDWARE
#define OUT7_HARDWARE
    #define OUT7_DDR        DDRA.7
    #define OUT7_PORT       PORTA.7
    #define OUT7_PIN        PINA.7
    #define OUT7_ACTIVE     1 
#endif 
*/

#ifdef OUT1_HARDWARE
    #define OUT1_CONFIG     OUT1_DDR=1; OUT1=!OUT1_ACTIVE;
    #define OUT1            OUT1_PORT
    #define OUT1_TURNON     OUT1=OUT1_ACTIVE;
    #define OUT1_TURNOFF    OUT1=!OUT1_ACTIVE;
#endif

#ifdef OUT2_HARDWARE
    #define OUT2_CONFIG     OUT2_DDR=1; OUT2=!OUT2_ACTIVE;
    #define OUT2            OUT2_PORT
    #define OUT2_TURNON     OUT2=OUT2_ACTIVE;
    #define OUT2_TURNOFF    OUT2=!OUT2_ACTIVE;
#endif

#ifdef OUT3_HARDWARE
    #define OUT3_CONFIG     OUT3_DDR=1; OUT3=!OUT3_ACTIVE;
    #define OUT3            OUT3_PORT
    #define OUT3_TURNON     OUT3=OUT3_ACTIVE;
    #define OUT3_TURNOFF    OUT3=!OUT3_ACTIVE;
#endif

#ifdef OUT4_HARDWARE
    #define OUT4_CONFIG     OUT4_DDR=1; OUT4=!OUT4_ACTIVE;
    #define OUT4            OUT4_PORT
    #define OUT4_TURNON     OUT4=OUT4_ACTIVE;
    #define OUT4_TURNOFF    OUT4=!OUT4_ACTIVE;
#endif

#ifdef OUT5_HARDWARE
    #define OUT5_CONFIG     OUT5_DDR=1; OUT5=!OUT5_ACTIVE;
    #define OUT5            OUT5_PORT
    #define OUT5_TURNON     OUT5=OUT5_ACTIVE;
    #define OUT5_TURNOFF    OUT5=!OUT5_ACTIVE;
#endif

#ifdef OUT6_HARDWARE 
    #define OUT6_CONFIG     OUT6_DDR=1; OUT6=!OUT6_ACTIVE;
    #define OUT6            OUT6_PORT
    #define OUT6_TURNON     OUT6=OUT6_ACTIVE;
    #define OUT6_TURNOFF    OUT6=!OUT6_ACTIVE;
#endif

#ifdef OUT7_HARDWARE
    #define OUT7_CONFIG     OUT7_DDR=1; OUT7=!OUT7_ACTIVE;
    #define OUT7            OUT7_PORT
    #define OUT7_TURNON     OUT7=OUT7_ACTIVE;
    #define OUT7_TURNOFF    OUT7=!OUT7_ACTIVE;
#endif 

//**********************************    
void Output_Config(void){ 
    #ifdef OUT1_HARDWARE
        OUT1_CONFIG;
    #endif
    
    #ifdef OUT2_HARDWARE
        OUT2_CONFIG;
    #endif

    #ifdef OUT3_HARDWARE
        OUT3_CONFIG;
    #endif

    #ifdef OUT4_HARDWARE
        OUT4_CONFIG; 
    #endif

    #ifdef OUT5_HARDWARE
        OUT5_CONFIG;
    #endif 

    #ifdef OUT6_HARDWARE
        OUT6_CONFIG;
    #endif  

    #ifdef OUT7_HARDWARE
        OUT7_CONFIG;
    #endif 
} 
 
#endif 

          


