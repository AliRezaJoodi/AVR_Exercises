// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <spi.h>
#include "hardware.h"
#include "aj_mcp42xxx.h"

void SPI_Config(void);

void main(void){
    static const aj_mcp42xxx_t mcp = {
        .cs = {
            .ddr   = &AJ_MCP42XXX_CS_DDR,
            .port  = &AJ_MCP42XXX_CS_PORT,
            .mask = AJ_MCP42XXX_CS_MASK
        },
        .shdn = {
            .ddr   = &AJ_MCP42XXX_SHDN_DDR,
            .port  = &AJ_MCP42XXX_SHDN_PORT,
            .mask = AJ_MCP42XXX_SHDN_MASK
        },
        .rs = {
            .ddr   = &AJ_MCP42XXX_RS_DDR,
            .port  = &AJ_MCP42XXX_RS_PORT,
            .mask = AJ_MCP42XXX_RS_MASK
        }
    };

    SPI_Config();
    AJ_MCP42xxx_Init(&mcp);

    AJ_MCP42xxx_ForceShutdown(&mcp);
    AJ_MCP42xxx_ReleaseShutdown(&mcp);

    AJ_MCP42xxx_HardwareReset(&mcp);

    AJ_MCP42xxx_ShutdownPot0(&mcp);
    AJ_MCP42xxx_WritePot0(&mcp, 25U);

    AJ_MCP42xxx_ShutdownPot1(&mcp);
    AJ_MCP42xxx_WritePot1(&mcp, 25U);

    AJ_MCP42xxx_ShutdownAll(&mcp);
    AJ_MCP42xxx_WriteAll(&mcp, 25U);

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
