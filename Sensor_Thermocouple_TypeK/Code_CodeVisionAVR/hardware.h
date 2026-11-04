#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define ADC_VREF            5000U
#define ADC_RESOLUTION_BIT  10U

#define TC_CH               0
#define TC_GAIN             90

#endif


