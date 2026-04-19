// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "crc8.h"

void UART_Config(void);
void UART_Display(uint8_t data);

void main(void){
    uint8_t data[3] = {123, 25, 109};
    uint8_t crc8 = 0;

    UART_Config();

    putsf("data1="); UART_Display(data[0]);
    putsf("data2="); UART_Display(data[1]);
    putsf("data3="); UART_Display(data[2]);
    putsf("\r");

    crc8 = 0;
    crc8 = CRC8_ATM(crc8, data[0]);
    crc8 = CRC8_ATM(crc8, data[1]);
    crc8 = CRC8_ATM(crc8, data[2]);
    putsf("CRC8_ATM= "); UART_Display(crc8);

    crc8 = 0;
    crc8 = CRC8_Maxim(crc8, data[0]);
    crc8 = CRC8_Maxim(crc8, data[1]);
    crc8 = CRC8_Maxim(crc8, data[2]);
    putsf("CRC8_Maxim= "); UART_Display(crc8);

    crc8 = 0;
    crc8 = CRC8_J1850(crc8, data[0]);
    crc8 = CRC8_J1850(crc8, data[1]);
    crc8 = CRC8_J1850(crc8, data[2]);
    putsf("CRC8_J1850= "); UART_Display(crc8);

    while(1){
    };
}

//********************************************************
void UART_Display(uint8_t data){
    char txt[20];

//    putsf("data:");
    itoa(data, txt);
    puts(txt);

//    putsf("  Out:");
//    itoa(mv, txt);
//    puts(txt);

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




