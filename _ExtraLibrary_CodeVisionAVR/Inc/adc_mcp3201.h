// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>
#include <utility.h>

#ifndef _MCP3201_INCLUDED
#define _MCP3201_INCLUDED

#ifndef MCP3201_HARDWARE
#define MCP3201_HARDWARE
    #define MCP3201_CS_DDR      DDRB.4
    #define MCP3201_CS_PORT     PORTB.4
    #define MCP3201_CS_PIN      PINB.4  
    
    #define MCP3201_VREF        5000     //mv
#endif

void MCP3201_Config(void);

#pragma used+
unsigned int _MCP3201_Communication(void);
float MCP3201_GetDifferentialADC(void);
#pragma used-

#pragma library adc_mcp3201.lib

#endif

