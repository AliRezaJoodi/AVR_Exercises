// GitHub Account: GitHub.com/AliRezaJoodi

#include <delay.h> 

#ifndef _OUT_INCLUDED
#define _OUT_INCLUDED

#ifndef _OUT_PORTS
#define _OUT_PORTS
    #define OUT_ACTIVATE   1
    
    #define OUT1_DDR        DDRA.1
    #define OUT1_PORT       PORTA.1
    #define OUT1_PIN        PINA.1 
    #define OUT1_ACTIVATE   1
    
    #define OUT2_DDR        DDRA.2
    #define OUT2_PORT       PORTA.2
    #define OUT2_PIN        PINA.2 
    #define OUT2_ACTIVATE   1

    #define OUT3_DDR        DDRA.3
    #define OUT3_PORT       PORTA.3
    #define OUT3_PIN        PINA.3 
    #define OUT3_ACTIVATE   1

    #define OUT4_DDR        DDRA.4
    #define OUT4_PORT       PORTA.4
    #define OUT4_PIN        PINA.4 
    #define OUT4_ACTIVATE   1

    #define OUT5_DDR        DDRA.5
    #define OUT5_PORT       PORTA.5
    #define OUT5_PIN        PINA.5
    #define OUT5_ACTIVATE   1 

    #define OUT6_DDR        DDRA.6
    #define OUT6_PORT       PORTA.6
    #define OUT6_PIN        PINA.6
    #define OUT6_ACTIVATE   1 

    #define OUT7_DDR        DDRA.7
    #define OUT7_PORT       PORTA.7
    #define OUT7_PIN        PINA.7
    #define OUT7_ACTIVATE   1 
#endif 

#define OUT1                OUT1_PORT
#define OUT1_TURNON         OUT1=OUT1_ACTIVATE
#define OUT1_TURNOFF        OUT1=!OUT1_ACTIVATE

#define OUT2                OUT2_PORT
#define OUT2_TURNON         OUT2=OUT2_ACTIVATE
#define OUT2_TURNOFF        OUT2=!OUT2_ACTIVATE

#define OUT3                OUT3_PORT
#define OUT3_TURNON         OUT3=OUT3_ACTIVATE
#define OUT3_TURNOFF        OUT3=!OUT3_ACTIVATE

#define OUT4                OUT4_PORT
#define OUT4_TURNON         OUT4=OUT4_ACTIVATE
#define OUT4_TURNOFF        OUT4=!OUT4_ACTIVATE

#define OUT5                OUT5_PORT
#define OUT5_TURNON         OUT5=OUT5_ACTIVATE
#define OUT5_TURNOFF        OUT5=!OUT5_ACTIVATE

#define OUT6                OUT6_PORT
#define OUT6_TURNON         OUT6=OUT6_ACTIVATE
#define OUT6_TURNOFF        OUT6=!OUT6_ACTIVATE

#define OUT7                OUT7_PORT
#define OUT7_TURNON         OUT7=OUT7_ACTIVATE
#define OUT7_TURNOFF        OUT7=!OUT7_ACTIVATE

//**********************************    
void Out_Config(void){ 
    #ifdef OUT1_PORT
        OUT1_DDR=1; OUT1=!OUT1_ACTIVATE;
    #endif
    
    #ifdef OUT2_PORT
        OUT2_DDR=1; OUT2=!OUT2_ACTIVATE;
    #endif

    #ifdef OUT3_PORT
        OUT3_DDR=1; OUT3=!OUT3_ACTIVATE;
    #endif

    #ifdef OUT4_PORT
        OUT4_DDR=1; OUT4=!OUT4_ACTIVATE; 
    #endif

    #ifdef OUT5_PORT
        OUT5_DDR=1; OUT5=!OUT5_ACTIVATE;
    #endif 

    #ifdef OUT6_PORT
        OUT6_DDR=1; OUT6=!OUT6_ACTIVATE;
    #endif  

    #ifdef OUT7_PORT
        OUT7_DDR=1; OUT7=!OUT7_ACTIVATE;
    #endif 
}

#pragma used+

#pragma used- 
#endif 

          


