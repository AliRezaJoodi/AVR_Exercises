#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS          8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS         8U      /*!< Supported: 8, 16, 32 */

#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT              1000U   // A value of uint16_t

#define AJ_MAX6675_CONFIG_PLATFORM_EXTRA
    #define AJ_MAX6675_CS1_DDR          DDRB
    #define AJ_MAX6675_CS1_PORT         PORTB
    #define AJ_MAX6675_CS1_POS          1U
    #define AJ_MAX6675_CS1_MASK         (1U << AJ_MAX6675_CS1_POS)

#define AJ_MAX6675_CS2_DDR          DDRC
#define AJ_MAX6675_CS2_PORT         PORTC
#define AJ_MAX6675_CS2_POS          2U
#define AJ_MAX6675_CS2_MASK         (1U << AJ_MAX6675_CS2_POS)


#endif

