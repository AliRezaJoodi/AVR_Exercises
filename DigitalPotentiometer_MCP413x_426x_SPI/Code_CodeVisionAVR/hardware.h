#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS              8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS             8U      /*!< Supported: 8, 16, 32 */

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT                  1000U   // A value of uint16_t

#define AJ_MCP413X_426X_CONFIG
    #define AJ_MCP413X_426X_BITS            8U      /**< 7 or 8 bits resolution. */
    #define AJ_MCP413X_426X_P1_SUPPORTED    1U      /**< 0: Single channel, 1: Dual channel supported. */
    #define AJ_MCP413X_426X_P0A_SUPPORTED   1U      /**< 0: P0A not present/used, 1: Supported. */
    #define AJ_MCP413X_426X_P1A_SUPPORTED   1U      /**< 0: P1A not present/used, 1: Supported. */
    #define AJ_MCP413X_426X_SHDN_USED       1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCP413X_426X_WP_USED         0U      /**< 0: Not used, 1: Used. */

#define AJ_MCP4251_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP4251_CS_DDR          DDRB
    #define AJ_MCP4251_CS_PORT         PORTB
    #define AJ_MCP4251_CS_POS          4U
    #define AJ_MCP4251_CS_MASK         (1U << AJ_MCP4251_CS_POS)

    #define AJ_MCP4251_SHDN_DDR        DDRB
    #define AJ_MCP4251_SHDN_PORT       PORTB
    #define AJ_MCP4251_SHDN_POS        3U
    #define AJ_MCP4251_SHDN_MASK       (1U << AJ_MCP4251_SHDN_POS)


#endif
