#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_TIMEBASE_CONFIG
    #define AJ_TIMEBASE_REG8_U8

#define AJ_BUZZER_HARDWARE
    #define AJ_BUZZER_ACTIVE       1U
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       180U

    #define AJ_BUZZER_DDR          DDRB
    #define AJ_BUZZER_PORT         PORTB
    #define AJ_BUZZER_POS          1U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)

#endif  /* HARDWARE_INCLUDED */
