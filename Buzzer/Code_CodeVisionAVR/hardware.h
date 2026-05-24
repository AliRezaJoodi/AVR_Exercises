#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

/*
 * Choose ONLY ONE configuration below:
 * - TIMEBASE_REG8_U8    (8-bit registers, 8-bit counter)
 * - TIMEBASE_REG8_U32   (8-bit registers, 32-bit counter)
 * - TIMEBASE_REG32_U32  (32-bit registers, 32-bit counter)
 */
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
