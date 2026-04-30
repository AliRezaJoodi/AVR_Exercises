#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define MCP3201_HARDWARE_EXTRA
    #define MCP3201_CS_DDR          DDRB
    #define MCP3201_CS_PORT         PORTB
    #define MCP3201_CS_BIT          4U
    #define MCP3201_CS_MASK         (1U << MCP3201_CS_BIT)

#define MCP3201_CS2_DDR             DDRB
#define MCP3201_CS2_PORT            PORTB
#define MCP3201_CS2_BIT             3U
#define MCP3201_CS2_MASK            (1U << MCP3201_CS2_BIT)

#endif

