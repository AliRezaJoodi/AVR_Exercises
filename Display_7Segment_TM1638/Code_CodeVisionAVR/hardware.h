// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_TM1638_HARDWARE
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

#define AJ_TM1638_HARDWARE_EXTRA
    #define AJ_TM1638_STB_DDR          DDRA
    #define AJ_TM1638_STB_PORT         PORTA
    #define AJ_TM1638_STB_POS          7U
    #define AJ_TM1638_STB_MASK         (1U << AJ_TM1638_STB_POS)

#endif
