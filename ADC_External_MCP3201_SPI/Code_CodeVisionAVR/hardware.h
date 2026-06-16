#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT              1000U   // A value of uint16_t
    #define AJ_SPI_ERROR                0xFFU   // A value of uint8_t

#define AJ_MCP3201_HARDWARE_EXTRA
    #define AJ_MCP3201_CS_DDR          DDRB
    #define AJ_MCP3201_CS_PORT         PORTB
    #define AJ_MCP3201_CS_POS          4U
    #define AJ_MCP3201_CS_MASK         (1U << AJ_MCP3201_CS_POS)

#define AJ_MCP3201_CS2_DDR             DDRB
#define AJ_MCP3201_CS2_PORT            PORTB
#define AJ_MCP3201_CS2_POS             3U
#define AJ_MCP3201_CS2_MASK            (1U << AJ_MCP3201_CS2_POS)

#endif

