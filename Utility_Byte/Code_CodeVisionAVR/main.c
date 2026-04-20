// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "utils/byte.h"

void UART_Config(void);
void UART_Display(uint16_t data);

void main(void){
    uint16_t number = 0, number2 = 0;
    uint8_t msb = 0, lsb = 0;

    UART_Config();

    number = 589;
    msb = GetMsb(number);
    lsb = GetLsb(number);
    number = MakeU16(msb, lsb);
    putsf("MSB= "); UART_Display(msb);
    putsf("LSB= "); UART_Display(lsb);
    putsf("Number (u16)= "); UART_Display(number);

    number2 = SwapU16(number);  //589 -> 19714
    putsf("Number After Swap(u16)= "); UART_Display(number2);

    while(1){
    }
}

//********************************************************
void UART_Display(uint16_t data){
    char txt[20];

    itoa(data, txt);
    puts(txt);
    putsf("\r");
}

//********************************************************
void UART_Config(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
    UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
    UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
    UBRRH=0x00;
    UBRRL=0x47;
}
