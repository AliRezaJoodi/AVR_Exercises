// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS          8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS         8U      /*!< Supported: 8, 16, 32 */

#define AJ_TM1638_CONFIG_PLATFORM
    #define AJ_TM1638_CLK_DDR          DDRC
    #define AJ_TM1638_CLK_PIN          PINC
    #define AJ_TM1638_CLK_PORT         PORTC
    #define AJ_TM1638_CLK_POS          7U
    #define AJ_TM1638_CLK_MASK         (1U << AJ_TM1638_CLK_POS)

    #define AJ_TM1638_DIO_DDR          DDRC
    #define AJ_TM1638_DIO_PIN          PINC
    #define AJ_TM1638_DIO_PORT         PORTC
    #define AJ_TM1638_DIO_POS          6U
    #define AJ_TM1638_DIO_MASK         (1U << AJ_TM1638_DIO_POS)

#define AJ_TM1638_CONFIG_PLATFORM_EXTRA
    #define AJ_TM1638_STB_DDR          DDRA
    #define AJ_TM1638_STB_PORT         PORTA
    #define AJ_TM1638_STB_POS          7U
    #define AJ_TM1638_STB_MASK         (1U << AJ_TM1638_STB_POS)


#endif
