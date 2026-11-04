#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define AJ_AVERAGE_CONFIG
    #define AJ_AVERAGE_COUNT     128U   // 0 < valid value < 256

#define ADC_CH1        7U
#define ADC_CH2        6U

#endif
