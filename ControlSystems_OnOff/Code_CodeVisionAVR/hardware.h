#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define TEMP_CH         0U

#define RLY_DDR         DDRC
#define RLY_PIN         PINC
#define RLY_PORT        PORTC
#define RLY_POS         1U

#define RLY_ACTIVATE    1U

#endif  /* HARDWARE_INCLUDED */
