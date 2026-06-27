// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS     8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS    8U      /*!< Supported: 8, 16, 32 */

#define AJ_GPIO_CONFIG
    #define AJ_MCU_SUPPORT_PORTA    1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCU_SUPPORT_PORTB    1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCU_SUPPORT_PORTC    1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCU_SUPPORT_PORTD    0U      /**< 0: Not used, 1: Used. */
    #define AJ_MCU_SUPPORT_PORTE    0U      /**< 0: Not used, 1: Used. */
    #define AJ_MCU_SUPPORT_PORTF    0U      /**< 0: Not used, 1: Used. */

#endif  /* HARDWARE_INCLUDED */
