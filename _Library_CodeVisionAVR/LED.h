// GitHub Account: GitHub.com/AliRezaJoodi

#include <delay.h> 

#ifndef INCLUDED_LEDS
    #define INCLUDED_LEDS
    
    //#define TURN_OFF_LEDS
    #ifndef TURN_OFF_LEDS
        #define TURN_ON_LEDS
    #endif

    #define ACTIVATE_LED    1
    
    #define LED0_DDR        DDRA.0
    #define LED0_PORT       PORTA.0
    #define LED0_PIN        PINA.0 
    #define LED0            LED0_PORT
    #define LED0_INDEX      0

    #define LED1_DDR        DDRA.1
    #define LED1_PORT       PORTA.1
    #define LED1_PIN        PINA.1 
    #define LED1            LED1_PORT
    #define LED1_INDEX      1

    #define LED2_DDR        DDRA.2
    #define LED2_PORT       PORTA.2
    #define LED2_PIN        PINA.2 
    #define LED2            LED2_PORT
    #define LED2_INDEX      2

    #define LED3_DDR        DDRA.3
    #define LED3_PORT       PORTA.3
    #define LED3_PIN        PINA.3 
    #define LED3            LED3_PORT
    #define LED3_INDEX      3

    #define LED4_DDR        DDRA.4
    #define LED4_PORT       PORTA.4
    #define LED4_PIN        PINA.4 
    #define LED4            LED4_PORT
    #define LED4_INDEX      4

    #define LED5_DDR        DDRA.5
    #define LED5_PORT       PORTA.5
    #define LED5_PIN        PINA.5 
    #define LED5            LED5_PORT
    #define LED5_INDEX      5

    #define LED6_DDR        DDRA.6
    #define LED6_PORT       PORTA.6
    #define LED6_PIN        PINA.6 
    #define LED6            LED6_PORT
    #define LED6_INDEX      6

    #define LED7_DDR        DDRA.7
    #define LED7_PORT       PORTA.7
    #define LED7_PIN        PINA.7 
    #define LED7            LED7_PORT
    #define LED7_INDEX      7

//**********************************    
void ConfigLeds(void){ 
    #ifdef TURN_ON_LEDS
        #ifndef OUTPUT
            #define OUTPUT 1
        #endif
    
        LED0_DDR=OUTPUT; LED0=!ACTIVATE_LED; 
        LED1_DDR=OUTPUT; LED1=!ACTIVATE_LED;
        LED2_DDR=OUTPUT; LED2=!ACTIVATE_LED;
        LED3_DDR=OUTPUT; LED3=!ACTIVATE_LED;
        LED4_DDR=OUTPUT; LED4=!ACTIVATE_LED;
        LED5_DDR=OUTPUT; LED5=!ACTIVATE_LED;
        LED6_DDR=OUTPUT; LED6=!ACTIVATE_LED; 
        LED7_DDR=OUTPUT; LED7=!ACTIVATE_LED; 
    #endif
}

#pragma used+

//**********************************   
void TurnOnOneLed(unsigned char index){
    #ifdef TURN_ON_LEDS
        switch (index){
	        case 0: LED0=ACTIVATE_LED; break;
            case 1: LED1=ACTIVATE_LED; break;
            case 2: LED2=ACTIVATE_LED; break;
            case 3: LED3=ACTIVATE_LED; break;
            case 4: LED4=ACTIVATE_LED; break;
            case 5: LED5=ACTIVATE_LED; break;
            case 6: LED6=ACTIVATE_LED; break;
            case 7: LED7=ACTIVATE_LED; break;
        } 
    #endif
}

//**********************************   
void TurnOffOneLed(unsigned char index){ 
    #ifdef TURN_ON_LEDS
        ConfigLeds();
        switch (index){
	        case 0: LED0=!ACTIVATE_LED; break;
            case 1: LED1=!ACTIVATE_LED; break;
            case 2: LED2=!ACTIVATE_LED; break;
            case 3: LED3=!ACTIVATE_LED; break;
            case 4: LED4=!ACTIVATE_LED; break;
            case 5: LED5=!ACTIVATE_LED; break;
            case 6: LED6=!ACTIVATE_LED; break;
            case 7: LED7=!ACTIVATE_LED; break;
        }
    #endif    
}

//**********************************   
void SetOneLed(unsigned char index, char status){ 
    #ifdef TURN_ON_LEDS
	    if(status){TurnOnOneLed(index);} 
            else{TurnOffOneLed(index);}
    #endif       
}

//**********************************   
void TurnOnAllLeds(void){ 
    #ifdef TURN_ON_LEDS
        LED0=ACTIVATE_LED;
        LED1=ACTIVATE_LED;
        LED2=ACTIVATE_LED;
        LED3=ACTIVATE_LED;
        LED4=ACTIVATE_LED;
        LED5=ACTIVATE_LED;
        LED6=ACTIVATE_LED;
        LED7=ACTIVATE_LED;
    #endif 
}

//**********************************   
void TurnOffAllLeds(void){
    #ifdef TURN_ON_LEDS
        LED0=!ACTIVATE_LED;
        LED1=!ACTIVATE_LED;
        LED2=!ACTIVATE_LED;
        LED3=!ACTIVATE_LED;
        LED4=!ACTIVATE_LED;
        LED5=!ACTIVATE_LED;
        LED6=!ACTIVATE_LED;
        LED7=!ACTIVATE_LED; 
    #endif 
}

//**********************************   
void SetAllLeds(unsigned char value){
    #ifdef TURN_ON_LEDS
        #ifndef CHKBIT
            #define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT)
        #endif
        LED0=CHKBIT(value,LED0_INDEX); 
        LED1=CHKBIT(value,LED1_INDEX);
        LED2=CHKBIT(value,LED2_INDEX);
        LED3=CHKBIT(value,LED3_INDEX);
        LED4=CHKBIT(value,LED4_INDEX);
        LED5=CHKBIT(value,LED5_INDEX);
        LED6=CHKBIT(value,LED6_INDEX);
        LED7=CHKBIT(value,LED7_INDEX);
    #endif 
}

//**********************************   
void BlinkOnLED(unsigned char index, unsigned int t){ 
    #ifdef TURN_ON_LEDS
        switch (index){
	        case 0: LED0=ACTIVATE_LED; delay_ms(t); LED0=!ACTIVATE_LED; break;
            case 1: LED1=ACTIVATE_LED; delay_ms(t); LED1=!ACTIVATE_LED; break;
            case 2: LED2=ACTIVATE_LED; delay_ms(t); LED2=!ACTIVATE_LED; break;
            case 3: LED3=ACTIVATE_LED; delay_ms(t); LED3=!ACTIVATE_LED; break;
            case 4: LED4=ACTIVATE_LED; delay_ms(t); LED4=!ACTIVATE_LED; break;
            case 5: LED5=ACTIVATE_LED; delay_ms(t); LED5=!ACTIVATE_LED; break;
            case 6: LED6=ACTIVATE_LED; delay_ms(t); LED6=!ACTIVATE_LED; break;
            case 7: LED7=ACTIVATE_LED; delay_ms(t); LED7=!ACTIVATE_LED; break;
        }
    #endif         
}

#pragma used-
  
#endif
          


