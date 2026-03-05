// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <spi.h>
#include <stdlib.h>
#include <delay.h>

#include "hardware.h"
#include "mcp4822.h"

void SPI_Config(void);

void main(void){
    float ch0_volt = 1.234;
    float ch1_volt = 3.654;

    SPI_Config();
    MCP4822_Config();

    MCP4822_SetOutput(0, ch0_volt);
    MCP4822_SetOutput(1, ch1_volt);
    //MCP4822_ShutDown(0);

    while(1){
    }
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
