//GitHub Account:     GitHub.com/AliRezaJoodi

#include <delay.h> 

#ifndef ACTIVATE_LED
    #define ACTIVATE_LED 1
#endif
#define DEACTIVATE_LED !ACTIVATE_LED
#define DEFAULT_LED DEACTIVATE_LED

#ifndef LED0_DDR
    #define LED0_DDR DDRA.0
    #define LED0_PORT PORTA.0
    #define LED0_PIN PINA.0 
#endif
#define LED0 LED0_PORT
#define LED0_INDEX 0

#ifndef LED1_DDR
    #define LED1_DDR DDRA.1
    #define LED1_PORT PORTA.1
    #define LED1_PIN PINA.1 
#endif
#define LED1 LED1_PORT
#define LED1_INDEX 1

#ifndef LED2_DDR
    #define LED2_DDR DDRA.2
    #define LED2_PORT PORTA.2
    #define LED2_PIN PINA.2 
#endif
#define LED2 LED2_PORT
#define LED2_INDEX 2

#ifndef LED3_DDR
    #define LED3_DDR DDRA.3
    #define LED3_PORT PORTA.3
    #define LED3_PIN PINA.3 
#endif
#define LED3 LED3_PORT
#define LED3_INDEX 3

#ifndef LED4_DDR
    #define LED4_DDR DDRA.4
    #define LED4_PORT PORTA.4
    #define LED4_PIN PINA.4 
#endif
#define LED4 LED4_PORT
#define LED4_INDEX 4

#ifndef LED5_DDR
    #define LED5_DDR DDRA.5
    #define LED5_PORT PORTA.5
    #define LED5_PIN PINA.5 
#endif
#define LED5 LED5_PORT
#define LED5_INDEX 5

#ifndef LED6_DDR
    #define LED6_DDR DDRA.6
    #define LED6_PORT PORTA.6
    #define LED6_PIN PINA.6 
#endif
#define LED6 LED6_PORT
#define LED6_INDEX 6

#ifndef LED7_DDR
    #define LED7_DDR DDRA.7
    #define LED7_PORT PORTA.7
    #define LED7_PIN PINA.7 
#endif
#define LED7 LED7_PORT
#define LED7_INDEX 7

//**********************************    
void Config_Leds(void){
    static char status=0;
    if (status==0){ 
        #define INPUT 0   
        #define OUTPUT !INPUT
        LED0_DDR=OUTPUT; LED0_PORT=DEFAULT_LED; 
        LED1_DDR=OUTPUT; LED1_PORT=DEFAULT_LED;
        LED2_DDR=OUTPUT; LED2_PORT=DEFAULT_LED;
        LED3_DDR=OUTPUT; LED3_PORT=DEFAULT_LED;
        LED4_DDR=OUTPUT; LED4_PORT=DEFAULT_LED;
        LED5_DDR=OUTPUT; LED5_PORT=DEFAULT_LED;
        LED6_DDR=OUTPUT; LED6_PORT=DEFAULT_LED; 
        LED7_DDR=OUTPUT; LED7_PORT=DEFAULT_LED; 
    }
    status=1;
}

//**********************************   
void On_Led(unsigned char index){
    Config_Leds();
    switch (index){
	    case 0: LED0_PORT=ACTIVATE_LED; break;
        case 1: LED1_PORT=ACTIVATE_LED; break;
        case 2: LED2_PORT=ACTIVATE_LED; break;
        case 3: LED3_PORT=ACTIVATE_LED; break;
        case 4: LED4_PORT=ACTIVATE_LED; break;
        case 5: LED5_PORT=ACTIVATE_LED; break;
        case 6: LED6_PORT=ACTIVATE_LED; break;
        case 7: LED7_PORT=ACTIVATE_LED; break;
    }         
}

//**********************************   
void Off_Led(unsigned char index){
    Config_Leds();
    switch (index){
	    case 0: LED0_PORT=DEACTIVATE_LED; break;
        case 1: LED1_PORT=DEACTIVATE_LED; break;
        case 2: LED2_PORT=DEACTIVATE_LED; break;
        case 3: LED3_PORT=DEACTIVATE_LED; break;
        case 4: LED4_PORT=DEACTIVATE_LED; break;
        case 5: LED5_PORT=DEACTIVATE_LED; break;
        case 6: LED6_PORT=DEACTIVATE_LED; break;
        case 7: LED7_PORT=DEACTIVATE_LED; break;
    }    
}

//**********************************   
void Set_Led(unsigned char index, char status){
    Config_Leds();
	if (status==0){Off_Led(index);} 
        else {On_Led(index);}      
}

//**********************************   
void On_Leds(void){
    unsigned char i=0;
    for(i=0;i<=7;++i){On_Led(i);}
}

//**********************************   
void Off_Leds(void){
    unsigned char i=0;
    for(i=0;i<=7;++i){Off_Led(i);}
}

//**********************************   
void Set_Leds(unsigned char value){
    #ifndef CHKBIT
        #define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT)
    #endif
    Config_Leds();
    LED0_PORT=CHKBIT(value,LED0_INDEX); 
    LED1_PORT=CHKBIT(value,LED1_INDEX);
    LED2_PORT=CHKBIT(value,LED2_INDEX);
    LED3_PORT=CHKBIT(value,LED3_INDEX);
    LED4_PORT=CHKBIT(value,LED4_INDEX);
    LED5_PORT=CHKBIT(value,LED5_INDEX);
    LED6_PORT=CHKBIT(value,LED6_INDEX);
    LED7_PORT=CHKBIT(value,LED7_INDEX);
}

//**********************************   
void Flasher_Led(unsigned char index, unsigned int t){
    Config_Leds();
    switch (index){
	    case 0: LED0_PORT=ACTIVATE_LED; delay_ms(t); LED0_PORT=DEACTIVATE_LED; break;
        case 1: LED1_PORT=ACTIVATE_LED; delay_ms(t); LED1_PORT=DEACTIVATE_LED; break;
        case 2: LED2_PORT=ACTIVATE_LED; delay_ms(t); LED2_PORT=DEACTIVATE_LED; break;
        case 3: LED3_PORT=ACTIVATE_LED; delay_ms(t); LED3_PORT=DEACTIVATE_LED; break;
        case 4: LED4_PORT=ACTIVATE_LED; delay_ms(t); LED4_PORT=DEACTIVATE_LED; break;
        case 5: LED5_PORT=ACTIVATE_LED; delay_ms(t); LED5_PORT=DEACTIVATE_LED; break;
        case 6: LED6_PORT=ACTIVATE_LED; delay_ms(t); LED6_PORT=DEACTIVATE_LED; break;
        case 7: LED7_PORT=ACTIVATE_LED; delay_ms(t); LED7_PORT=DEACTIVATE_LED; break;
    }        
}

          


