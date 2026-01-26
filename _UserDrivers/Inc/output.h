// GitHub Account: GitHub.com/AliRezaJoodi

#include <delay.h> 

#ifndef _OUTPUT_INCLUDED
#define _OUTPUT_INCLUDED

#ifndef OUTPUT_HARDWARE
#define OUTPUT_HARDWARE
    #define OUT1_ACTIVE     1
    #define OUT1_DDR        DDRA.1
    #define OUT1_PORT       PORTA.1
    #define OUT1_PIN        PINA.1 
    
#endif

#ifdef OUT1_PORT
    #define OUT1            OUT1_PORT
    #define OUT1_TURNON     OUT1=OUT1_ACTIVE;
    #define OUT1_TURNOFF    OUT1=!OUT1_ACTIVE;
#endif

#ifdef OUT2_PORT
    #define OUT2            OUT2_PORT
    #define OUT2_TURNON     OUT2=OUT2_ACTIVE;
    #define OUT2_TURNOFF    OUT2=!OUT2_ACTIVE;
#endif

#ifdef OUT3_PORT
    #define OUT3            OUT3_PORT
    #define OUT3_TURNON     OUT3=OUT3_ACTIVE;
    #define OUT3_TURNOFF    OUT3=!OUT3_ACTIVE;
#endif

#ifdef OUT4_PORT
    #define OUT4            OUT4_PORT
    #define OUT4_TURNON     OUT4=OUT4_ACTIVE;
    #define OUT4_TURNOFF    OUT4=!OUT4_ACTIVE;
#endif

#ifdef OUT5_PORT
    #define OUT5            OUT5_PORT
    #define OUT5_TURNON     OUT5=OUT5_ACTIVE;
    #define OUT5_TURNOFF    OUT5=!OUT5_ACTIVE;
#endif

#ifdef OUT6_PORT
    #define OUT6            OUT6_PORT
    #define OUT6_TURNON     OUT6=OUT6_ACTIVE;
    #define OUT6_TURNOFF    OUT6=!OUT6_ACTIVE;
#endif

#ifdef OUT7_PORT
    #define OUT7            OUT7_PORT
    #define OUT7_TURNON     OUT7=OUT7_ACTIVE;
    #define OUT7_TURNOFF    OUT7=!OUT7_ACTIVE;
#endif 

//**********************************    
void Output_Config(void){ 
    #ifdef OUT1_PORT
        OUT1_DDR=1; OUT1_PORT=!OUT1_ACTIVE;
    #endif
    
    #ifdef OUT2_PORT
        OUT2_DDR=1; OUT2_PORT=!OUT2_ACTIVE;
    #endif

    #ifdef OUT3_PORT
        OUT3_DDR=1; OUT3_PORT=!OUT1_ACTIVE;
    #endif

    #ifdef OUT4_PORT
        OUT4_DDR=1; OUT4_PORT=!OUT4_ACTIVE;
    #endif

    #ifdef OUT5_PORT
        OUT5_DDR=1; OUT5_PORT=!OUT5_ACTIVE;
    #endif 

    #ifdef OUT6_PORT
        OUT6_DDR=1; OUT6_PORT=!OUT6_ACTIVE;
    #endif  

    #ifdef OUT7_PORT
        OUT7_DDR=1; OUT7_PORT=!OUT7_ACTIVE;
    #endif 
} 
 
#endif 

          


