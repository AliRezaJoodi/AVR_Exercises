#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS          8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS         8U      /*!< Supported: 8, 16, 32 */

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT              1000U   // A value of uint16_t

#define AJ_MCP3204_3208_CONFIG
    #define AJ_MCP3204_3208_CHANNELS    8U      /**< 4 or 8 bits resolution. */

#define AJ_MCP3208_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP3208_CS_DDR          DDRB
    #define AJ_MCP3208_CS_PORT         PORTB
    #define AJ_MCP3208_CS_POS          4U
    #define AJ_MCP3208_CS_MASK         (1U << AJ_MCP3208_CS_POS)

#define AJ_MCP3204_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP3204_CS_DDR          DDRB
    #define AJ_MCP3204_CS_PORT         PORTB
    #define AJ_MCP3204_CS_POS          3U
    #define AJ_MCP3204_CS_MASK         (1U << AJ_MCP3204_CS_POS)

#endif
