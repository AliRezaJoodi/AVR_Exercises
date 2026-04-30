#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define MCP3204_HARDWARE_EXTRA
    #define MCP3204_CS_DDR          DDRB
    #define MCP3204_CS_PORT         PORTB
    #define MCP3204_CS_BIT          4U
    #define MCP3204_CS_MASK         (1U << MCP3204_CS_BIT)

#endif


