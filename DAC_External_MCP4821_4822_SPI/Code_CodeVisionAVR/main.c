// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <spi.h>

#include "hardware.h"
#include "aj_mcp4822.h"

void SPI_Config(void);

void main(void){
    static const aj_mcp4822_t mcp4822 = {
        .cs = {
            .ddr   = &AJ_MCP4822_CS_DDR,
            .port  = &AJ_MCP4822_CS_PORT,
            .mask  =  AJ_MCP4822_CS_MASK
        },
        .ldac = {
            .ddr   = &AJ_MCP4822_LDAC_DDR,
            .port  = &AJ_MCP4822_LDAC_PORT,
            .mask  =  AJ_MCP4822_LDAC_MASK
        }
    };

    SPI_Config();
    AJ_MCP4822_Init(&mcp4822);


    AJ_MCP4822_WriteCount_ChA_2V048(&mcp4822, 4096/2);
    AJ_MCP4822_WriteCount_ChB_2V048(&mcp4822, 4096/2);

    AJ_MCP4822_Shutdown_ChA(&mcp4822);
    AJ_MCP4822_Shutdown_ChB(&mcp4822);

    AJ_MCP4822_WriteCount_ChA_4V096(&mcp4822, 4096/2);
    AJ_MCP4822_WriteCount_ChB_4V096(&mcp4822, 4096/2);



    while(1){
    }
}

//********************************************************
void SPI_Config(void){
    //DDRB.4=1; PORTB.4=0;    //SS
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
