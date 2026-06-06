#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_MCP3208_HARDWARE
    #define AJ_MCP3208_TIMEOUT         1000U

#define AJ_MCP3208_HARDWARE_EXTRA
    #define AJ_MCP3208_CS_DDR          DDRB
    #define AJ_MCP3208_CS_PORT         PORTB
    #define AJ_MCP3208_CS_POS          4U
    #define AJ_MCP3208_CS_MASK         (1U << AJ_MCP3208_CS_POS)

#endif
