#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED


#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS     8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS    8U      /*!< Supported: 8, 16, 32 */

#define AJ_BUZZER_CONFIG
    #define AJ_BUZZER_ACTIVE       1U
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       200U

#define AJ_BUZZER_CONFIG_PLATFORM
    #define AJ_BUZZER_DDR          DDRB
    #define AJ_BUZZER_PORT         PORTB
    #define AJ_BUZZER_POS          1U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)


#endif  /* HARDWARE_INCLUDED */
