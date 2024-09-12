// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>
#include <delay.h>
#include <utility.h>

#ifndef _MCP4822_INCLUDED
    #define _MCP4822_INCLUDED

#ifndef MCP4822_HARDWARE
#define MCP4822_HARDWARE   
    #define MCP4822_CS_DDR      DDRB.3
    #define MCP4822_CS_PORT     PORTB.3
    #define MCP4822_CS_PIN      PINB.3
    
    #define MCP4822_LDAC_DDR    DDRB.2
    #define MCP4822_LDAC_PORT   PORTB.2
    #define MCP4822_LDAC_PIN    PINB.2            
#endif
                    
void MCP4822_Config(void);

#pragma used+
void MCP4822_SetOutput(char ch, float volt);
void MCP4822_ShutDown(char ch);
#pragma used-

#pragma library dac_mcp4822.lib

#endif

