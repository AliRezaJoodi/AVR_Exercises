// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include <utility.h>

char value;

void main(void){  
    SetBit(DDRA,0); //PORTA.0 is output
    SetBit(PORTA,0); delay_ms(500); ClearBit(PORTA,0); delay_ms(500);
    
    SetBit(DDRA,1);
    WriteBit(PORTA,1,1);  delay_ms(500); WriteBit(PORTA,1,0);  delay_ms(500);
    
    SetBit(DDRB,0);
    value=0b00000001; WriteBit(PORTB,0,GetBit(value,0)); delay_ms(500);
    value=0b00000000; WriteBit(PORTB,0,GetBit(value,0)); delay_ms(500);
    
    while(1){
    };
}




