// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

void Config_IO(void);
void Display_1Digit(unsigned char);

void main(void){
    unsigned char value=0;

    Config_IO();
    
    while (1){
        for(value=0; value<=17; ++value){ 
            Display_1Digit(value); delay_ms(350);
        }
    };
}

//**************************************
void Display_1Digit(unsigned char value){
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    //A , B , C , D , E , F,
    // - , Dp
    unsigned char data_7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000}; 
    
   PORTD=data_7segment[value]; 
   PORTB= data_7segment[value] ^ 0b11111111;
}

//**************************************
void Config_IO(void){    
    DDRD=0xFF; PORTD=0xFF;
    DDRB=0xFF; PORTB=0xFF;
}
