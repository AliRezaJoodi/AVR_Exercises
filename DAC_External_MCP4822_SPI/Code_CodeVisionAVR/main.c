// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <spi.h>

#include "hardware.h"
#include "drivers/mcp4822.h"

void SPI_Config(void);

void main(void){
    static const MCP4822_t dac1 = {
        .cs = {
            .ddr   = &MCP4822_CS_DDR,
            .port  = &MCP4822_CS_PORT,
            //.index =  MCP4822_CS_BIT,
            .mask  =  MCP4822_CS_MASK
        },
        .ldac = {
            .ddr   = &MCP4822_LDAC_DDR,
            .port  = &MCP4822_LDAC_PORT,
            //.index =  MCP4822_LDAC_BIT,
            .mask  =  MCP4822_LDAC_MASK
        }
    };

//    MCP4822_t dac1;
//
//    dac1.cs.ddr     = &MCP4822_CS_DDR;
//    dac1.cs.port    = &MCP4822_CS_PORT;
//    dac1.cs.index   =  MCP4822_CS_BIT;
//    dac1.ldac.ddr   = &MCP4822_LDAC_DDR;
//    dac1.ldac.port  = &MCP4822_LDAC_PORT;
//    dac1.ldac.index =  MCP4822_LDAC_BIT;

    SPI_Config();
    MCP4822_Init(&dac1);

//    MCP4822_SetOutput(&dac1, MCP4822_OUTPUT_A, MCP4822_GAIN_1X, 1000U);
//    MCP4822_SetOutputA(&dac1, MCP4822_GAIN_1X, 1000U);
    MCP4822_SetOutputA_1xGain(&dac1, 4095U);
//    MCP4822_SetOutputA_2xGain(&dac1, 1000U);

//    MCP4822_DisableOutput(&dac1, MCP4822_OUTPUT_A);
//    MCP4822_DisableOutputA(&dac1);


//    MCP4822_SetOutput(&dac1, MCP4822_OUTPUT_B, MCP4822_GAIN_2X, 1000U);
//    MCP4822_SetOutputB(&dac1, MCP4822_GAIN_1X, 1000U);
//    MCP4822_SetOutputB_1xGain(&dac1, 1000U);
    MCP4822_SetOutputB_2xGain(&dac1, 4095U);

    delay_ms(2000);
//    MCP4822_DisableOutput(&dac1, MCP4822_OUTPUT_B);
    MCP4822_DisableOutputB(&dac1);

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
