// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>
#include <utility.h>

#ifndef _MCP3208_INCLUDED
#define _MCP3208_INCLUDED

#ifndef MCP3208_HARDWARE
#define MCP3208_HARDWARE
    #define MCP3208_CS_DDR      DDRB.4
    #define MCP3208_CS_PORT     PORTB.4
    #define MCP3208_CS_PIN      PINB.4 
    
    #define MCP3208_VREF        5000     //mv
#endif

void MCP3208_Config(void);

#pragma used+
float MCP3208_GetSingleEndedADC(char ch);
float MCP3208_GetDifferentialADC(char ch);
#pragma used-

#pragma library adc_mcp3208.lib

#endif

