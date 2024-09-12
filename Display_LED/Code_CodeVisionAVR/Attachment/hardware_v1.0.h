
#define OUTPUT_HARDWARE
    #define OUT1_ACTIVE     1
    #define OUT1_DDR        DDRA.0
    #define OUT1_PORT       PORTA.0
    #define OUT1_PIN        PINA.0 
    
    #define OUT2_ACTIVE     1  
    #define OUT2_DDR        DDRA.1
    #define OUT2_PORT       PORTA.1
    #define OUT2_PIN        PINA.1 

#define LED1                OUT1_PORT
#define LED1_TURNON         OUT1_PORT=OUT1_ACTIVE;
#define LED1_TURNOFF        OUT1_PORT=!OUT1_ACTIVE;
    
#define LED2                OUT2_PORT
#define LED2_TURNON         OUT2_PORT=OUT2_ACTIVE;
#define LED2_TURNOFF        OUT2_PORT=!OUT2_ACTIVE;    
