// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>

#ifndef _MCP3201_INCLUDED
#define _MCP3201_INCLUDED

#ifndef _MCP3201_HARDWARE
#define _MCP3201_HARDWARE
    #define MCP3201_CS_DDR      DDRB.4
    #define MCP3201_CS_PORT     PORTB.4
    #define MCP3201_CS_PIN      PINB.4  
    
    #define MCP3201_VREF        5000     //mv
#endif
//#define MCP3201_CS              MCP3201_CS_PORT

#define _MCP3201_CONFIG_CS \
        MCP3201_CS_DDR=1;\ 
        MCP3201_CS_PORT=1;      

#define _MCP3201_SELECT          MCP3201_CS_PORT=0;
#define _MCP3201_DESELECT        MCP3201_CS_PORT=1;


void MCP3201_Config(void);

#pragma used+
unsigned int _MCP3201_Communication(void);
float MCP3201_GetDifferentialADC(void);

#pragma used-

#pragma library adc_mcp3201.lib

#endif

