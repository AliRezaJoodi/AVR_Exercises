// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <spi.h>
#include "hardware.h"
#include "aj_mcp42010.h"
#include "aj_mcp41010.h"

void SPI_Config(void);

void main(void){
    static const aj_mcp42010_t mcp4210 = {
        .cs = {
            .ddr  = &AJ_MCP42010_CS_DDR,
            .port = &AJ_MCP42010_CS_PORT,
            .mask = AJ_MCP42010_CS_MASK
        },
        .shdn = {
            .ddr  = &AJ_MCP42010_SHDN_DDR,
            .port = &AJ_MCP42010_SHDN_PORT,
            .mask = AJ_MCP42010_SHDN_MASK
        },
        .rs = {
            .ddr  = &AJ_MCP42010_RS_DDR,
            .port = &AJ_MCP42010_RS_PORT,
            .mask = AJ_MCP42010_RS_MASK
        }
    };

    static const aj_mcp41010_t mcp4110 = {
        .cs = {
            .ddr  = &AJ_MCP41010_CS_DDR,
            .port = &AJ_MCP41010_CS_PORT,
            .mask = AJ_MCP41010_CS_MASK
        }
    };

    SPI_Config();
    AJ_MCP42010_Init(&mcp4210);
    AJ_MCP41010_Init(&mcp4110);

    AJ_MCP41010_WriteCount_Pot0(&mcp4110, 25);
//    AJ_MCP41010_Shutdown_Pot0(&mcp4110);

    AJ_MCP42010_WriteCount_Pot0(&mcp4210, 50);
    AJ_MCP42010_WriteCount_Pot1(&mcp4210, 150);

//    AJ_MCP41010_Shutdown_Pot0(&mcp4210);
//    AJ_MCP42010_ForceShutdown(&mcp4210);

    while(1){

    }
}

//********************************************************
void SPI_Config(void){
    DDRB.4 = 1; PORTB.4 = 1;    // SS/CS output, inactive High
    DDRB.5 = 1; PORTB.5 = 0;    // MOSI output
    DDRB.6 = 0; PORTB.6 = 0;    // MISO input, pull-up disabled
    DDRB.7 = 1; PORTB.7 = 0;    // SCK output, idle Low for Mode 0

    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 2000.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);
}
