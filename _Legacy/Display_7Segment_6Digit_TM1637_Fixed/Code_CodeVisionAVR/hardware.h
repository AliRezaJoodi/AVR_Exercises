// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define _TM1637_FIXED_HARDWARE     
    #define TM1637_CLK_DDR         DDRC
    #define TM1637_CLK_PIN         PINC
    #define TM1637_CLK_PORT        PORTC
    #define TM1637_CLK_BIT         0

    #define TM1637_DIO_DDR         DDRC
    #define TM1637_DIO_PIN         PINC
    #define TM1637_DIO_PORT        PORTC
    #define TM1637_DIO_BIT         2

    #define TM1637_HALF_BIT_US     1

#define _BUTTON_FIXED_HARDWARE    
    #define PRESSED             0 
    #define BUTTONLAG1          30        //ms 
    #define BUTTONLAG2          1000      //Button Lag
            
    #define BUTTON1_DDR         DDRA.1
    #define BUTTON1_PORT        PORTA.1
    #define BUTTON1_PIN         PINA.1
    
    
#endif
