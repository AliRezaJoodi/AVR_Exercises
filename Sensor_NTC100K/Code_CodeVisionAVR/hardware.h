#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED
    

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

    #define ADC_VREF_MV             5000
    #define ADC_RESOLUTION_BITS     10

    #define NTC100K_RESISTOR        100000UL    //ohm
    #define NTC100K_CH              0

#endif


