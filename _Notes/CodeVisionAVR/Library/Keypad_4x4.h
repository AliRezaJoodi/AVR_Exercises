// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef KEYPAD_DDR
    #define KEYPAD_DDR DDRC
    #define KEYPAD_PORT PORTC
    #define KEYPAD_PIN PINC
#endif

#include <delay.h> 

//********************************************************
unsigned char Get_Port(void){
    unsigned char numer;
    KEYPAD_DDR=0b00001111; KEYPAD_PORT=0b11110000; delay_us(5); numer=KEYPAD_PIN; 
    KEYPAD_DDR=0b11110000; KEYPAD_PORT=0b00001111; delay_us(5); numer=numer|KEYPAD_PIN;
    return numer;
}

//********************************************************
unsigned char Converter_Data(unsigned char key){
    #define Key_Max 16
    unsigned char i=0, number=0; 
    //unsigned char keypad_data[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    //unsigned char keypad_data[16]={215,235,219,187,237,221,189,238,222,190,126,125,123,119,183,231};
    //unsigned char keypad_data[16]={0b11010111,0b11101011,0b11011011,0b10111011,0b11101101,0b11011101,0b10111101,0b11101110,0b11011110,0b10111110,0b01111110,0b01111101,0b01111011,0b01110111,0b10110111,0b11100111};
    char keypad_data[16][2]={
        {238,0},
        {237,1},
        {235,2},
        {231,3},
        {222,4},
        {221,5},
        {219,6},
        {215,7},
        {190,8},
        {189,9},
        {187,10},
        {183,11},
        {126,12},
        {125,13},
        {123,14},
        {119,15},
    };
    
    char keypad_data2[16]={7,4,1,3,8,5,2,0,9,6,3,11,12,13,14,15}; 
     
    if(key!=0xff){ 
        for(i=0; i<Key_Max; i++){    
  	        if(key==keypad_data[i][0])  break;   
  	    }
        number= keypad_data[i][1];
        number= keypad_data2[number];
    }  
    else number= Key_Max;
    
    return number; 
}

//********************************************************
unsigned char Get_Keypad(void){
    unsigned char numer_initial=0;
    unsigned char numer_correct=0;
    
    numer_initial=Get_Port(); 
    numer_correct=Converter_Data(numer_initial);
    
    return numer_correct;
}