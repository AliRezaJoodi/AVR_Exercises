// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

void Config_IO(void);
void Display_1Digit(unsigned char);

void main(void){
    unsigned char value=0;

    Config_IO();
    
    while (1){
        for(value=0; value<=9; ++value){ 
            Display_1Digit(value); delay_ms(350);
        }
    };
}

//**************************************
void Display_1Digit(unsigned char value){
   PORTB= value;
}

//**************************************
void Config_IO(void){    
    DDRB=0xFF; PORTB=0xFF;
}
