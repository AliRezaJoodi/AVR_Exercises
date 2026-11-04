// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define TM1637_CLK_DDR         DDRC
#define TM1637_CLK_PORT        PORTC
#define TM1637_CLK_PIN         PINC
#define TM1637_CLK_BIT         0

#define TM1637_DIO_DDR         DDRC
#define TM1637_DIO_PORT        PORTC
#define TM1637_DIO_PIN         PINC
#define TM1637_DIO_BIT         1


#endif
