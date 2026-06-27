#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS     8U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS    8U      /*!< Supported: 8, 16, 32 */

#define AJ_KEYPAD4X4_HARDWARE
    #define AJ_KEYPAD4X4_R1_DDR        DDRC
    #define AJ_KEYPAD4X4_R1_PIN        PINC
    #define AJ_KEYPAD4X4_R1_PORT       PORTC
    #define AJ_KEYPAD4X4_R1_POS        0U
    #define AJ_KEYPAD4X4_R1_MASK       (1U << AJ_KEYPAD4X4_R1_POS)

    #define AJ_KEYPAD4X4_R2_DDR        DDRC
    #define AJ_KEYPAD4X4_R2_PIN        PINC
    #define AJ_KEYPAD4X4_R2_PORT       PORTC
    #define AJ_KEYPAD4X4_R2_POS        1U
    #define AJ_KEYPAD4X4_R2_MASK       (1U << AJ_KEYPAD4X4_R2_POS)

    #define AJ_KEYPAD4X4_R3_DDR        DDRC
    #define AJ_KEYPAD4X4_R3_PIN        PINC
    #define AJ_KEYPAD4X4_R3_PORT       PORTC
    #define AJ_KEYPAD4X4_R3_POS        2U
    #define AJ_KEYPAD4X4_R3_MASK       (1U << AJ_KEYPAD4X4_R3_POS)

    #define AJ_KEYPAD4X4_R4_DDR        DDRC
    #define AJ_KEYPAD4X4_R4_PIN        PINC
    #define AJ_KEYPAD4X4_R4_PORT       PORTC
    #define AJ_KEYPAD4X4_R4_POS        3U
    #define AJ_KEYPAD4X4_R4_MASK       (1U << AJ_KEYPAD4X4_R4_POS)

    #define AJ_KEYPAD4X4_C1_DDR        DDRC
    #define AJ_KEYPAD4X4_C1_PIN        PINC
    #define AJ_KEYPAD4X4_C1_PORT       PORTC
    #define AJ_KEYPAD4X4_C1_POS        4U
    #define AJ_KEYPAD4X4_C1_MASK       (1U << AJ_KEYPAD4X4_C1_POS)

    #define AJ_KEYPAD4X4_C2_DDR        DDRC
    #define AJ_KEYPAD4X4_C2_PIN        PINC
    #define AJ_KEYPAD4X4_C2_PORT       PORTC
    #define AJ_KEYPAD4X4_C2_POS        5U
    #define AJ_KEYPAD4X4_C2_MASK       (1U << AJ_KEYPAD4X4_C2_POS)

    #define AJ_KEYPAD4X4_C3_DDR        DDRC
    #define AJ_KEYPAD4X4_C3_PIN        PINC
    #define AJ_KEYPAD4X4_C3_PORT       PORTC
    #define AJ_KEYPAD4X4_C3_POS        6U
    #define AJ_KEYPAD4X4_C3_MASK       (1U << AJ_KEYPAD4X4_C3_POS)

    #define AJ_KEYPAD4X4_C4_DDR        DDRC
    #define AJ_KEYPAD4X4_C4_PIN        PINC
    #define AJ_KEYPAD4X4_C4_PORT       PORTC
    #define AJ_KEYPAD4X4_C4_POS        7U
    #define AJ_KEYPAD4X4_C4_MASK       (1U << AJ_KEYPAD4X4_C4_POS)

#endif
