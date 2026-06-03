#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define TIMEBASE_CONFIG
    #define TIMEBASE_REG8_U8

#define BUZZER_HARDWARE
    #define BUZZER_ACTIVE       1U
    #define BUZZER_COUNT1       75U
    #define BUZZER_COUNT2       180U

    #define BUZZER_DDR          DDRB
    #define BUZZER_PORT         PORTB
    #define BUZZER_BIT          1U
    #define BUZZER_MASK         (1U << BUZZER_BIT)

#endif  /* HARDWARE_INCLUDED */
