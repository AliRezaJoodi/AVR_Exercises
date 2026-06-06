#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_MCP4822_HARDWARE
    #define AJ_MCP4822_TIMEOUT         1000U

#define AJ_MCP4822_HARDWARE_EXTRA
    #define AJ_MCP4822_CS_DDR          DDRB
    #define AJ_MCP4822_CS_PORT         PORTB
    #define AJ_MCP4822_CS_POS          3U
    #define AJ_MCP4822_CS_MASK         (1U << AJ_MCP4822_CS_POS)

    #define AJ_MCP4822_LDAC_DDR        DDRB
    #define AJ_MCP4822_LDAC_PORT       PORTB
    #define AJ_MCP4822_LDAC_POS        2U
    #define AJ_MCP4822_LDAC_MASK       (1U << AJ_MCP4822_LDAC_POS)

#endif
