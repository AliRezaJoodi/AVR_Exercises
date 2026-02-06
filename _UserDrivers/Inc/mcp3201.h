// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef _MCP3201_INCLUDED
#define _MCP3201_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <io.h>
#include <spi.h>

#include <utility_bit.h>

/**
 * @note Default hardware macros can be overridden by the user.
 */ 
#include "hardware.h"

#ifndef MCP3201_HARDWARE
#define MCP3201_HARDWARE    
    #define MCP3201_VREF        5000U     //mv
     
    #warning "MCP3201_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP3201_HARDWARE_EXTRA
#define MCP3201_HARDWARE_EXTRA
    #define MCP3201_CS1_DDR      DDRB
    #define MCP3201_CS1_PORT     PORTB
    #define MCP3201_CS1_BIT      4U 
         
    #warning "MCP3201_HARDWARE_EXTRA is not defined; default configuration will be used."
#endif

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} MCP3201_Pin_t;

typedef struct {
    MCP3201_Pin_t cs;
} MCP3201_t;


void MCP3201_Config(MCP3201_t *mcp);
uint16_t MCP3201_GetCounts(MCP3201_t *mcp);
float MCP3201_GetMilliVolt(MCP3201_t *mcp);
float MCP3201_ConvertCountsToMilliVolt(uint16_t counts);


#ifdef __cplusplus
}
#endif

#endif

