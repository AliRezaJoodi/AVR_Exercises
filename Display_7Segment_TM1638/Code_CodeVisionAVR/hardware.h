// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define TM1638_HARDWARE
    #define TM1638_CLK_DDR          DDRC
    #define TM1638_CLK_PIN          PINC
    #define TM1638_CLK_PORT         PORTC
    #define TM1638_CLK_BIT          7U

    #define TM1638_DIO_DDR          DDRC
    #define TM1638_DIO_PIN          PINC
    #define TM1638_DIO_PORT         PORTC
    #define TM1638_DIO_BIT          6U

#define TM1638_HARDWARE_EXTRA
    #define TM1638_STB_DDR          DDRA
    #define TM1638_STB_PORT         PORTA
    #define TM1638_STB_BIT          7U

#endif
