#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS                  8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS                 8U      /*!< Supported: 8, 16, 32 */

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT                      1000U   // A value of uint16_t

#define AJ_MCP41XXX_42XXX_CONFIG
    #define AJ_MCP41XXX_42XXX_POT1_SUPPORTED    1U      /**< 0: Single channel, 1: Dual channel supported. */
    #define AJ_MCP41XXX_42XXX_SHDN_USED         1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCP41XXX_42XXX_RS_USED           1U      /**< 0: Not used, 1: Used. */

#define AJ_MCP41010_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP41010_CS_DDR            DDRB
    #define AJ_MCP41010_CS_PORT           PORTB
    #define AJ_MCP41010_CS_POS            1U
    #define AJ_MCP41010_CS_MASK           (1U << AJ_MCP41010_CS_POS)

#define AJ_MCP42010_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP42010_CS_DDR            DDRB
    #define AJ_MCP42010_CS_PORT           PORTB
    #define AJ_MCP42010_CS_POS            4U
    #define AJ_MCP42010_CS_MASK           (1U << AJ_MCP42010_CS_POS)

    #define AJ_MCP42010_SHDN_DDR          DDRB
    #define AJ_MCP42010_SHDN_PORT         PORTB
    #define AJ_MCP42010_SHDN_POS          3U
    #define AJ_MCP42010_SHDN_MASK         (1U << AJ_MCP42010_SHDN_POS)

    #define AJ_MCP42010_RS_DDR            DDRB
    #define AJ_MCP42010_RS_PORT           PORTB
    #define AJ_MCP42010_RS_POS            2U
    #define AJ_MCP42010_RS_MASK           (1U << AJ_MCP42010_RS_POS)


#endif
