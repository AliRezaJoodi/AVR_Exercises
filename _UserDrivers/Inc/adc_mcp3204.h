// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>
#include <utility.h>

#ifndef _MCP3204_INCLUDED
#define _MCP3204_INCLUDED

#ifndef MCP3204_HARDWARE
#define MCP3204_HARDWARE
    #define MCP3204_CS_DDR      DDRB.4
    #define MCP3204_CS_PORT     PORTB.4
    #define MCP3204_CS_PIN      PINB.4 
    
    #define MCP3204_VREF        5000     //mv
#endif
//#define MCP3204_CS              MCP3204_CS_PORT

void MCP3204_Config(void);

#pragma used+
float MCP3204_GetSingleEndedADC(char ch);
float MCP3204_GetDifferentialADC(char ch);
#pragma used-

#pragma library adc_mcp3204.lib

#endif

