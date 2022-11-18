#include <delay.h>

#ifndef DATA_DDR
    #define DATA_DDR DDRB.2
    #define DATA_PORT PORTB.2
    #define DATA_PIN PINB.2  
#endif
#define DATA DATA_PORT

#ifndef ACTIVATE_DATA
    #define ACTIVATE_DATA 1
#endif
#define DEACTIVATE_DATA !ACTIVATE_DATA
#define DEFAULT_DATA DEACTIVATE_DATA

#ifndef CLK_DDR
    #define CLK_DDR DDRB.1
    #define CLK_PORT PORTB.1
    #define CLK_PIN PINB.1
#endif
#define CLK CLK_PORT

#ifndef ACTIVATE_CLK
    #define ACTIVATE_CLK 1
#endif
#define DEACTIVATE_CLK !ACTIVATE_CLK
#define DEFAULT_CLK DEACTIVATE_CLK

#ifndef CLEAR_DDR
    #define CLEAR_DDR DDRB.0
    #define CLEAR_PORT PORTB.0
    #define CLEAR_PIN PINB.0
#endif
#define CLEAR CLEAR_PORT

#ifndef ACTIVATE_CLEAR
    #define ACTIVATE_CLEAR 0
#endif
#define DEACTIVATE_CLEAR !ACTIVATE_CLEAR
#define DEFAULT_CLEAR DEACTIVATE_CLEAR

//**************************************
void Config_74164(void){
    #define OUTPUT 1   
    CLEAR_DDR=OUTPUT; CLEAR_PORT=DEFAULT_CLEAR;
    CLK_DDR=OUTPUT; CLK_PORT=DEFAULT_CLK; 
    DATA_DDR=OUTPUT; DATA_PORT=DEFAULT_DATA; 
    #undef OUTPUT
}

//**************************************
void Reset_74164(void){
    CLEAR=ACTIVATE_CLEAR; delay_us(10); CLEAR=DEACTIVATE_CLEAR; delay_us(10); 
}

//**************************************
void Set_74164(void){
    CLK=ACTIVATE_CLK; delay_us(10); CLK=DEACTIVATE_CLK; delay_us(10); 
}

//**************************************
unsigned char Convert_7Segment(unsigned char digit){
    unsigned char out=0;
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    //A , B , C , D , E , F,
    // - , Dp
    unsigned char data_7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000}; 
    
    out=data_7segment[digit]; 
    return out; 
}

//**************************************
unsigned char Invert_7Segment(unsigned char x){
    return x ^ 0b11111111; 
}

//**************************************
void Drive_74164(unsigned char value){
    #ifndef CHKBIT(ADDRESS,BIT)
        #define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT) 
    #endif 
    unsigned char i=0;
    
    Config_74164();
    Reset_74164();
    value=Convert_7Segment(value);
    value=Invert_7Segment(value);
     
    for (i=0; i<=7; ++i){
        DATA=CHKBIT(value,7-i);
        Set_74164();    
    }
}


