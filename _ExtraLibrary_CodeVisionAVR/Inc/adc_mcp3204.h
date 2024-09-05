// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>

#ifndef _MCP3204_INCLUDED
#define _MCP3204_INCLUDED

#ifndef _MCP3204_HARDWARE
#define _MCP3204_HARDWARE
    #define MCP3204_CS_DDR      DDRB.4
    #define MCP3204_CS_PORT     PORTB.4
    #define MCP3204_CS_PIN      PINB.4 
    
    #define MCP3204_VREF        5000     //mv
#endif
//#define MCP3204_CS              MCP3204_CS_PORT

#define _MCP3204_CONFIG_CS \
        MCP3204_CS_DDR=1;\ 
        MCP3204_CS_PORT=1;      

#define _MCP3204_SELECT          MCP3204_CS_PORT=0;
#define _MCP3204_DESELECT        MCP3204_CS_PORT=1;

void MCP3204_Config(void);

#pragma used+
unsigned int _MCP3204_Communication(char data1, char data2);
float MCP3204_GetSingleEndedADC(char ch);
float MCP3204_GetDifferentialADC(char ch);
#pragma used-

#pragma library adc_mcp3204.lib

#endif

