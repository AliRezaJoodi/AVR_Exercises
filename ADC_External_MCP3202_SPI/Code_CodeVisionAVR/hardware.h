#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define MCP3202_HARDWARE_EXTRA
    #define MCP3202_CS_DDR          DDRB
    #define MCP3202_CS_PORT         PORTB
    #define MCP3202_CS_BIT          4U
    #define MCP3202_CS_MASK         (1U << MCP3202_CS_BIT)

#endif
