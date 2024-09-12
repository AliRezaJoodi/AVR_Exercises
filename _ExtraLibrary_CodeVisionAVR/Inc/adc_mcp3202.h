// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>
#include <utility.h>

#ifndef _MCP3202_INCLUDED
#define _MCP3202_INCLUDED

#ifndef MCP3202_HARDWARE
#define MCP3202_HARDWARE
    #define MCP3202_CS_DDR      DDRB.4
    #define MCP3202_CS_PORT     PORTB.4
    #define MCP3202_CS_PIN      PINB.4  
    
    #define MCP3202_VREF        5000     //mv
#endif
 
void MCP3202_Config(void);

#pragma used+
float MCP3202_GetSingleEndedADC(char ch);
float MCP3202_GetDifferentialADC(char ch);
#pragma used-

#pragma library adc_mcp3202.lib

#endif

