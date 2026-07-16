// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "aj_mcp3208.h"
#include "aj_mcp3204.h"

void UART_Config(void);
void SPI_Config(void);

void main(void){
    char txt[20];
    uint16_t raw = 0;

    static const aj_mcp3204_t mcb3204 = {
        .cs = {
            .ddr  = &AJ_MCP3204_CS_DDR,
            .port = &AJ_MCP3204_CS_PORT,
            .mask = AJ_MCP3204_CS_MASK
        }
    };

    static const aj_mcp3208_t mcb3208 = {
        .cs = {
            .ddr  = &AJ_MCP3208_CS_DDR,
            .port = &AJ_MCP3208_CS_PORT,
            .mask = AJ_MCP3208_CS_MASK
        }
    };

    UART_Config();
    SPI_Config();
    AJ_MCP3204_Init(&mcb3204);
    AJ_MCP3208_Init(&mcb3208);

    putsf("Test UART");
    delay_ms(500);

    raw = AJ_MCP3204_ReadRaw(&mcb3204, AJ_MCP3204_CH0);
    putsf("\r"); putsf("MCP3204_CH0(Raw):"); itoa(raw, txt); puts(txt);

    raw = AJ_MCP3204_ReadRaw(&mcb3204, AJ_MCP3204_CH2CH3);
    putsf("\r"); putsf("MCP3204_CH2CH3(Raw):"); itoa(raw, txt); puts(txt);

    raw = AJ_MCP3208_ReadRaw(&mcb3208, AJ_MCP3208_CH5CH4);
    putsf("\r"); putsf("MCP3208_CH5CH4(Raw):"); itoa(raw, txt); puts(txt);

    raw = AJ_MCP3208_ReadRaw(&mcb3208, AJ_MCP3208_CH7CH6);
    putsf("\r"); putsf("MCP3208_CH7CH6(Raw):"); itoa(raw, txt); puts(txt);

    while (1){
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

//********************************************************
void SPI_Config(void){
    DDRB.4=1; PORTB.4=0;    //SS
    DDRB.5=1; PORTB.5=0;    //MOSI
    DDRB.6=0; PORTB.6=0;    //MISO
    DDRB.7=1; PORTB.7=0;    //SCK

// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2000.000 kHz
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First
SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
SPSR=(0<<SPI2X);
}