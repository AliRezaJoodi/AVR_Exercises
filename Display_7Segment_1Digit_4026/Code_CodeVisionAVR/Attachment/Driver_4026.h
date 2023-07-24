#include <delay.h>

#ifndef MR_DDR
    #define MR_DDR DDRB.0 
    #define MR_PORT PORTB.0
    #define MR_PIN PINB.0  
#endif
#define MR MR_PORT

#ifndef ACTIVATE_MR
    #define ACTIVATE_MR 1
#endif
#define DEACTIVATE_MR !ACTIVATE_MR
#define DEFAULT_MR DEACTIVATE_MR

#ifndef CLK_DDR
    #define CLK_DDR DDRB.1
    #define CLK_PORT PORTB.1
    #define CLK_PIN PINB.1
#endif
#define CLK CLK_PORT

#ifndef ACTIVATE_CLK
    #define ACTIVATE_CLK 0
#endif
#define DEACTIVATE_CLK !ACTIVATE_CLK
#define DEFAULT_CLK DEACTIVATE_CLK

//**************************************
void Config_4026(void){
    #define OUTPUT 1   
    MR_DDR=OUTPUT; MR_PORT=DEACTIVATE_MR;
    CLK_DDR=OUTPUT; CLK_PORT=DEACTIVATE_CLK; 
    #undef OUTPUT
}

//**************************************
void Reset_4026(void){
    MR=ACTIVATE_MR; delay_us(10); MR=DEACTIVATE_MR; delay_us(10);
}

//**************************************
void Set_4026(void){
    CLK=ACTIVATE_CLK; delay_us(10); CLK=DEACTIVATE_CLK; delay_us(10);  
}

//**************************************
void Drive_4026(unsigned char value){
    unsigned char i=0;
    Config_4026();
    Reset_4026(); 
    if (value>0){
        for (i=1; i<=value; ++i){Set_4026();}
    } 
}


