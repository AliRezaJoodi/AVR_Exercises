#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_BITS              8U          /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_CORE_CLOCK_HZ          8000000U    /*!< Core clock (HCLK) in Hz */
    #define AJ_TARGET_TICK_BITS              16U         /*!< Supported: 8, 16, 32 */

#define MCP3201_HARDWARE
    #define MCP3201_CS_DDR      DDRB
    #define MCP3201_CS_PORT     PORTB
    #define MCP3201_CS_PIN      PINB
    #define MCP3201_CS_BIT      4  
        
    #define MCP3201_VREF        5000     //mv       


#endif

