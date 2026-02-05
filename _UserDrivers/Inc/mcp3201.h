// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef _MCP3201_INCLUDED
#define _MCP3201_INCLUDED


#include <stdint.h>
#include <io.h>
#include <spi.h>

#include <utility_bit.h>
#include "hardware.h"

#ifndef MCP3201_HARDWARE
#define MCP3201_HARDWARE
    #define MCP3201_CS_DDR      DDRB
    #define MCP3201_CS_PORT     PORTB
    #define MCP3201_CS_PIN      PINB
    #define MCP3201_CS_BIT      4U 
    
    #define MCP3201_VREF        5000U     //mv
     
    #warning "MCP3201_HARDWARE is not defined; default configuration will be used."
#endif

void MCP3201_Config(void);
uint16_t MCP3201_GetCounts(void);
float MCP3201_GetMilliVolt(void);
float MCP3201_ConvertCountsToMilliVolt(uint16_t counts);


#pragma library mcp3201.lib
#endif

