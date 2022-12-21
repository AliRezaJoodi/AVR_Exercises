
/*      Software UART Library       */
/*      Author: Reza Sepas Yar      */
/*      Version: 1.0                */

#include <delay.h>

#define TX2_PIN		PORTD.7 // UART2 TX pin 
#define TX2_DDR   DDRD.7  // UART2 TX Direction Register
 
// TX & RX levels
#define HIGH	1
#define LOW		0  
 	
// UART2 specific 
#define DATA_BIT_LENGTH		104  // ((1/BAUD)*10000000)

// put a character DIRECTLY to the UART2
void putchar2(unsigned char c){
    unsigned char i;

    TX2_PIN = LOW;				   // clear output (start bit) 
	delay_us(DATA_BIT_LENGTH);
	
    for(i=0; i<8; i++){
        TX2_PIN = (c & 0x01);
        delay_us(DATA_BIT_LENGTH);
        c >>= 1;  	   	   // next bit, please ! 
    }
                      	   	     
    TX2_PIN = HIGH;          // stop bit (bit #8)
    delay_us(DATA_BIT_LENGTH); 
}

void puts2(char* str){
    while( *str != '\0' ){
        putchar2((unsigned char) *str++);
    }
}

// UART2 initialization function (we MUST call this function BEFORE using UART2)
void initUART2(void){
    TX2_PIN = 1;  // logic 1 (high level = STOP TX)
    TX2_DDR  = 1; // output
}

 
