// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include <utility_bit.h>

void main(void){
    uint8_t value=0;
      
    SET_BIT(DDRA,0); //PORTA.0 is output
    SET_BIT(PORTA,0); delay_ms(500);
    CLEAR_BIT(PORTA,0); delay_ms(500);
    
    SET_BIT(DDRA,1);
    WRITE_BIT(PORTA,1,1);  delay_ms(500);
    WRITE_BIT(PORTA,1,0);  delay_ms(500);
    
    SET_BIT(DDRB,0);
    value=0b00000001; WRITE_BIT(PORTB, 0, GET_BIT(value,0)); delay_ms(500);
    value=0b00000000; WRITE_BIT(PORTB, 0, GET_BIT(value,0)); delay_ms(500);
    
    while(1){
    };
}




