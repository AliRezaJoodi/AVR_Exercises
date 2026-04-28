#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define BUTTON_HARDWARE
    #define BUTTON_SINGLE_CLICK_LAG     30U         /**< Single Click Lag, Value: 0~65535, Unit: ms */
    #define BUTTON_AUTO_REPEAT_LAG      500U        /**< Auto Repeat Lag, Value: 0~65535 */
    #define BUTTON_LONG_PRESS_LAG       10000U      /**< Long Press Lag, Value: 0~65535 */

#define BUTTON_HARDWARE_EXTRA
    #define BUTTON_DDR                  DDRB
    #define BUTTON_PIN                  PINB
    #define BUTTON_PORT                 PORTB
    #define BUTTON_BIT                  0U
    #define BUTTON_MASK                 (1U << BUTTON_BIT)

#define BUTTON2_DDR         DDRB
#define BUTTON2_PIN         PINB
#define BUTTON2_PORT        PORTB
#define BUTTON2_BIT         1U
#define BUTTON2_MASK        (1U << BUTTON2_BIT)

#define BUTTON3_DDR         DDRB
#define BUTTON3_PIN         PINB
#define BUTTON3_PORT        PORTB
#define BUTTON3_BIT         2U
#define BUTTON3_MASK        (1U << BUTTON3_BIT)


#endif


