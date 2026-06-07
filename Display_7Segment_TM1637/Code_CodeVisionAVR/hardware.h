// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_TM1637_HARDWARE_EXTRA
    #define AJ_TM1637_CLK_DDR         DDRC
    #define AJ_TM1637_CLK_PORT        PORTC
    #define AJ_TM1637_CLK_PIN         PINC
    #define AJ_TM1637_CLK_POS         0U
    #define AJ_TM1637_CLK_MASK        (1U << AJ_TM1637_CLK_POS)

    #define AJ_TM1637_DIO_DDR         DDRC
    #define AJ_TM1637_DIO_PORT        PORTC
    #define AJ_TM1637_DIO_PIN         PINC
    #define AJ_TM1637_DIO_POS         1U
    #define AJ_TM1637_DIO_MASK        (1U << AJ_TM1637_DIO_POS)

#define TM1637_CLK2_DDR         DDRD
#define TM1637_CLK2_PORT        PORTD
#define TM1637_CLK2_PIN         PIND
#define TM1637_CLK2_BIT         2U
#define TM1637_CLK2_MASK        (1U << TM1637_CLK2_BIT)

#define TM1637_DIO2_DDR         DDRD
#define TM1637_DIO2_PORT        PORTD
#define TM1637_DIO2_PIN         PIND
#define TM1637_DIO2_BIT         3U
#define TM1637_DIO2_MASK        (1U << TM1637_DIO2_BIT)

#endif
