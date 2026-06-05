#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_TIMEBASE_CONFIG
    #define AJ_TIMEBASE_REG8_U8

#define AJ_BUTTON_HARDWARE
    #define AJ_BUTTON_TIME_TRIGGER         30U
    #define AJ_BUTTON_TIME_AUTO_REPEAT     100U

#define AJ_BUTTON_HARDWARE_EXTRA
    #define AJ_BUTTON_DDR                  DDRB
    #define AJ_BUTTON_PIN                  PINB
    #define AJ_BUTTON_PORT                 PORTB
    #define AJ_BUTTON_POS                  0U
    #define AJ_BUTTON_MASK                 (1U << AJ_BUTTON_POS)

#define AJ_BUTTON2_DDR         DDRB
#define AJ_BUTTON2_PIN         PINB
#define AJ_BUTTON2_PORT        PORTB
#define AJ_BUTTON2_POS         1U
#define AJ_BUTTON2_MASK        (1U << AJ_BUTTON2_POS)

#define AJ_BUTTON3_DDR         DDRB
#define AJ_BUTTON3_PIN         PINB
#define AJ_BUTTON3_PORT        PORTB
#define AJ_BUTTON3_POS         2U
#define AJ_BUTTON3_MASK        (1U << AJ_BUTTON3_POS)


#endif  /* AJ_HARDWARE_INCLUDED */


