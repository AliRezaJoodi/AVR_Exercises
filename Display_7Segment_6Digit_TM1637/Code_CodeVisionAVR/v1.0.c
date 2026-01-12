// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
//#include <stdlib.h>
#include <stdint.h>

#include <tm1637.h>

void main(void){
    uint8_t ak2=0;
    uint8_t k=0;
     
    TM1637_Config();
    delay_ms(50);

    TM1637_Start();
    TM1637_WriteByte(0b10001111);  //Display and control command setting
    TM1637_Stop();

    TM1637_Start();
    TM1637_WriteByte(0b01000000);  // Data command setting
    TM1637_Stop();

    TM1637_Start();
    TM1637_WriteByte(0b11000000);  // Address command setting
    TM1637_WriteByte(0b00111111);  //0
    TM1637_WriteByte(0b00000110);  //1
    TM1637_WriteByte(0b01011011);  //2
    TM1637_WriteByte(0b01001111);  //3
    TM1637_WriteByte(0b01100110);  //4
    TM1637_WriteByte(0b01101101);  //5
    TM1637_Stop();
    
    while(1){          
        delay_ms(500);                               
    };
}
