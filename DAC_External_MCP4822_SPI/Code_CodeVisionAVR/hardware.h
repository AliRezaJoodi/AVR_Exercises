#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define MCP4822_HARDWARE_EXTRA
    #define MCP4822_CS_DDR          DDRB
    #define MCP4822_CS_PORT         PORTB
    #define MCP4822_CS_BIT          3U
    #define MCP4822_CS_MASK         (1U << MCP4822_CS_BIT)

    #define MCP4822_LDAC_DDR        DDRB
    #define MCP4822_LDAC_PORT       PORTB
    #define MCP4822_LDAC_BIT        2U
    #define MCP4822_LDAC_MASK       (1U << MCP4822_LDAC_BIT)

#endif
