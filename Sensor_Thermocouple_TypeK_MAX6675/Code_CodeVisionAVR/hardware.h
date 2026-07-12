#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS          8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS         8U      /*!< Supported: 8, 16, 32 */

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT              1000U   // A value of uint16_t

#define AJ_MAX6675_CONFIG_PLATFORM_EXTRA
    #define AJ_MAX6675_CS_DDR           DDRB
    #define AJ_MAX6675_CS_PORT          PORTB
    #define AJ_MAX6675_CS_POS           4U
    #define AJ_MAX6675_CS_MASK          (1U << AJ_MAX6675_CS_POS)

#endif

