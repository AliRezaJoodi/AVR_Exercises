// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <io.h>
#include <spi.h>

#include <delay.h>
#include <utility.h>

#ifndef MCP4822_INCLUDED
    #define MCP4822_INCLUDED

#ifndef _MCP4822_HARDWARE
#define _MCP4822_HARDWARE   
    #define MCP4822_CS_DDR      DDRB.3
    #define MCP4822_CS_PORT     PORTB.3
    #define MCP4822_CS_PIN      PINB.3
    
    #define MCP4822_LDAC_DDR    DDRB.2
    #define MCP4822_LDAC_PORT   PORTB.2
    #define MCP4822_LDAC_PIN    PINB.2            
#endif

#define _MCP4822_CONFIG_CS \
        MCP4822_CS_DDR=1;\ 
        MCP4822_CS_PORT=1; 

#define _MCP4822_SELECT          MCP4822_CS_PORT=0;
#define _MCP4822_DESELECT \        
        MCP4822_CS_PORT=1;\ 
        #asm("nop");            // Minimum Setup Time = 40ns

#define _MCP4822_CONFIG_LDAC \
        MCP4822_LDAC_DDR=1;\ 
        MCP4822_LDAC_PORT=1;

#define _MCP4822_SYNCHRONIZE \    
        MCP4822_LDAC_PORT=0;\
        #asm("nop");\ 
        #asm("nop");\           // Minimum Pulse Width = 100ns 
        MCP4822_LDAC_PORT=1;
                    
void MCP4822_Config(void);

#pragma used+
void _MCP4822_WriteCommand(unsigned int data);
void MCP4822_SetOutput(char ch, float volt);
void MCP4822_ShutDown(char ch);
#pragma used-

#pragma library dac_mcp4822.lib

#endif

