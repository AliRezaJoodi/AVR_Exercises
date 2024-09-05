// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>

#ifndef _MCP3208_INCLUDED
#define _MCP3208_INCLUDED

#ifndef _MCP3208_PORTS
#define _MCP3208_PORTS
    #define MCP3208_CS_DDR      DDRB.4
    #define MCP3208_CS_PORT     PORTB.4
    #define MCP3208_CS_PIN      PINB.4 
    
    #define MCP3208_VREF        5000     //mv
#endif
//#define MCP3208_CS              MCP3208_CS_PORT 


#define _MCP3208_CONFIG_CS \
        MCP3208_CS_DDR=1;\ 
        MCP3208_CS_PORT=1;      

#define _MCP3208_SELECT          MCP3208_CS_PORT=0;
#define _MCP3208_DESELECT        MCP3208_CS_PORT=1;

void MCP3208_Config(void);

#pragma used+
unsigned int _MCP3208_Communication(char data1, char data2);
float MCP3208_GetSingleEndedADC(char ch);
float MCP3208_GetDifferentialADC(char ch);
#pragma used-

#pragma library adc_mcp3208.lib

#endif

