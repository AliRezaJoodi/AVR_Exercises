// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define TM1638_STB_DDR         DDRA
#define TM1638_STB_PIN         PINA
#define TM1638_STB_PORT        PORTA
#define TM1638_STB_BIT         7

#define TM1638_CLK_DDR         DDRC
#define TM1638_CLK_PIN         PINC
#define TM1638_CLK_PORT        PORTC
#define TM1638_CLK_BIT         7

#define TM1638_DIO_DDR         DDRC
#define TM1638_DIO_PIN         PINC
#define TM1638_DIO_PORT        PORTC
#define TM1638_DIO_BIT         6 


#endif
