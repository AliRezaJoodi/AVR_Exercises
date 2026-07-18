#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS              8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS             8U      /*!< Supported: 8, 16, 32 */

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT                  1000U   // A value of uint16_t

#define AJ_MCP4821_4822_CONFIG
    #define AJ_MCP4821_4822_CHB_SUPPORTED   1U      /**< 0: Single channel, 1: Dual channel supported. */
    #define AJ_MCP4821_4822_SHDN_USED       1U      /**< 0: Not used, 1: Used. */

#define AJ_MCP4821_4822_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP4821_4822_CS_DDR          DDRB
    #define AJ_MCP4821_4822_CS_PORT         PORTB
    #define AJ_MCP4821_4822_CS_POS          4U
    #define AJ_MCP4821_4822_CS_MASK         (1U << AJ_MCP4821_4822_CS_POS)

    #define AJ_MCP4821_4822_LDAC_DDR        DDRB
    #define AJ_MCP4821_4822_LDAC_PORT       PORTB
    #define AJ_MCP4821_4822_LDAC_POS        3U
    #define AJ_MCP4821_4822_LDAC_MASK       (1U << AJ_MCP4821_4822_LDAC_POS)

#endif
