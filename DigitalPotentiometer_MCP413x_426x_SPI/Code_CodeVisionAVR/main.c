// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <spi.h>
#include "hardware.h"
#include "aj_mcp4251.h"

void SPI_Config(void);

void main(void){
    static const aj_mcp4251_t mcp = {
        .cs = {
            .ddr   = &AJ_MCP413X_426X_CS_DDR,
            .port  = &AJ_MCP413X_426X_CS_PORT,
            .mask = AJ_MCP413X_426X_CS_MASK
        },
        .shdn = {
            .ddr   = &AJ_MCP413X_426X_SHDN_DDR,
            .port  = &AJ_MCP413X_426X_SHDN_PORT,
            .mask = AJ_MCP413X_426X_SHDN_MASK
        }
    };

    SPI_Config();
    AJ_MCP4251_Init(&mcp);

//    AJ_MCP4251_ForceShutdown(&mcp);
//    AJ_MCP4251_ReleaseShutdown(&mcp);

    AJ_MCP4251_WriteCount_Pot0(&mcp, 128U);
    AJ_MCP4251_WriteCount_Pot1(&mcp, 128U);

//    AJ_MCP4251_DisableTerminalControl(&mcp, AJ_MCP4251_TCON_P0HW);
//    AJ_MCP4251_DisableTerminalControl(&mcp, AJ_MCP4251_TCON_P1HW);
//    AJ_MCP4251_EnableTerminalControl(&mcp, AJ_MCP4251_TCON_P0HW);

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
