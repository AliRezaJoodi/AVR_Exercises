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
    
#define _MCP3202_CONFIG_CS \
        MCP3202_CS_DDR=1;\ 
        MCP3202_CS_PORT=1;      

#define _MCP3202_SELECT          MCP3202_CS_PORT=0;
#define _MCP3202_DESELECT        MCP3202_CS_PORT=1;
 
void MCP3202_Config(void);

#pragma used+
unsigned int _MCP3202_Communication(char data1, char data2);
float MCP3202_GetSingleEndedADC(char ch);
float MCP3202_GetDifferentialADC(char ch);
#pragma used-

#pragma library adc_mcp3202.lib

#endif

