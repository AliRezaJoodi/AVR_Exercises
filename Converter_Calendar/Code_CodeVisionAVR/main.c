// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <mega32a.h>

#include "converter_calendar.h"

void UART_Config(void);

void main(void){
    char txt[];

    date_t gregorian;
    date_t jalaali;

    gregorian.year = 26;
    gregorian.month = 03;
    gregorian.day= 10;

//    jalaali.year = 04;
//    jalaali.month = 12;
//    jalaali.day = 19;

    UART_Config();

    ConvertCalendar_GregorianToJalaali(&gregorian, &jalaali);
    ConvertCalendar_JalaaliToGregorian(&jalaali, &gregorian);

    sprintf(txt,"G: 20%02u/%02u/%02u\r", gregorian.year, gregorian.month, gregorian.day); puts(txt);
    sprintf(txt,"J: 14%02u/%02u/%02u\r", jalaali.year, jalaali.month, jalaali.day); puts(txt);

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




