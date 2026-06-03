#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define TIMEBASE_CONFIG
    #define TIMEBASE_REG8_U8

#define BUTTON_HARDWARE
    #define BUTTON_TIME_TRIGGER         30U
    #define BUTTON_TIME_AUTO_REPEAT     100U

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


#endif  /* HARDWARE_INCLUDED */


