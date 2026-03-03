// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define TM1637_HARDWARE_EXTRA
    #define TM1637_CLK_DDR         DDRC
    #define TM1637_CLK_PORT        PORTC
    #define TM1637_CLK_PIN         PINC
    #define TM1637_CLK_BIT         0

    #define TM1637_DIO_DDR         DDRC
    #define TM1637_DIO_PORT        PORTC
    #define TM1637_DIO_PIN         PINC
    #define TM1637_DIO_BIT         1

#define TM1637_CLK2_DDR         DDRD
#define TM1637_CLK2_PORT        PORTD
#define TM1637_CLK2_PIN         PIND
#define TM1637_CLK2_BIT         2

#define TM1637_DIO2_DDR         DDRD
#define TM1637_DIO2_PORT        PORTD
#define TM1637_DIO2_PIN         PIND
#define TM1637_DIO2_BIT         3

#endif
