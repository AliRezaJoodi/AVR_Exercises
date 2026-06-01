// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "aj_ctz.h"

void UART_Config(void);

void main(void){
    uint8_t ctz = 10;
    char txt[20];

    UART_Config();
    putsf("Test UART\r");

    ctz = AJ_CTZ_u8(0x80U);
    itoa(ctz, txt); putsf("CTZ(u8)= "); puts(txt); putsf("\r");

    ctz = AJ_CTZ_u16(0x8000U);
    itoa(ctz, txt); putsf("CTZ(u16)= "); puts(txt); putsf("\r");

    ctz = AJ_CTZ_u32(0x80000000UL);
    ltoa(ctz, txt); putsf("CTZ(u32)= "); puts(txt); putsf("\r");

    while(1){
    };
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
