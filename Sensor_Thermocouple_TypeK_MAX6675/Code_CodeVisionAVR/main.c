// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "aj_max6675.h"

void UART_Config(void);
void SPI_Config(void);

void main(void){
    char txt[20];
    char txt2[20];
    uint16_t raw1, raw1_last = 0;
    float temperature1;

    uint16_t raw2, raw2_last = 0;
    float temperature2;

    static const aj_max6675_t tc1 = {
        .cs = {
            .ddr  = &AJ_MAX6675_CS1_DDR,
            .port = &AJ_MAX6675_CS1_PORT,
            .mask = AJ_MAX6675_CS1_MASK
        }
    };

    static const aj_max6675_t max2 = {
        .cs = {
            .ddr  = &AJ_MAX6675_CS2_DDR,
            .port = &AJ_MAX6675_CS2_PORT,
            .mask = AJ_MAX6675_CS2_MASK
        }
    };

    UART_Config();
    SPI_Config();
    AJ_MAX6675_Init(&tc1);
    AJ_MAX6675_Init(&max2);

    putsf("Test UART");
    delay_ms(500);
    DDRA = 0xFF;

    while (1){
        raw1 = AJ_MAX6675_ReadRaw(&tc1);
        PORTA = raw1;

        if(raw1 != raw1_last){
            raw1_last = raw1;
            temperature1 = raw1 * 0.25;
//            putsf("\r"); putsf("TC1(Raw):"); itoa(raw, txt); puts(txt);
            putsf("\r"); putsf("TC1(^C):"); ftoa(temperature1, 2, txt); puts(txt);
            delay_ms(100);
        }
        delay_ms(100);

        raw2 = AJ_MAX6675_ReadRaw(&max2);
        if(raw2 != raw2_last){
            raw2_last = raw2;
            temperature2 = raw2 * 0.25;
//            putsf("\r"); putsf("TC2(Raw):"); itoa(raw, txt); puts(txt);
            putsf("\r"); putsf("TC2(^C):"); ftoa(temperature2, 2, txt2); puts(txt2);
            delay_ms(100);
        }
        delay_ms(100);
    }
}

//********************************************************
void UART_Config(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: Off
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
    UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
    UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
    UBRRH=0x00;
    UBRRL=0x47;
}

//********************************************************  Mode1
void SPI_Config(void){
    DDRB.4 = 1; PORTB.4 = 1;    // SS/CS output, inactive High
    DDRB.5 = 1; PORTB.5 = 0;    // MOSI output
    DDRB.6 = 0; PORTB.6 = 0;    // MISO input, pull-up disabled
    DDRB.7 = 1; PORTB.7 = 0;    // SCK output, idle Low for Mode 0

    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 125.000 kHz
    // SPI Clock Phase: Cycle Half
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR = (0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (1<<CPHA) | (1<<SPR1) | (0<<SPR0);
    SPSR = (0<<SPI2X);
}