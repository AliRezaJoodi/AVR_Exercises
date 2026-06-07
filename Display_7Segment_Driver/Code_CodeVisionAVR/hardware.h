#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_SEG7_DRIVER_HARDWARE
    #define AJ_SEG7_DIGITS_COUNT       8U
    #define AJ_SEG7_DIGITS_ACTIVATE    1U
    #define AJ_SEG7_SEGMENTS_ACTIVATE  0U

    #define AJ_SEG7_DIGIT0_DDR         DDRB
    #define AJ_SEG7_DIGIT0_PORT        PORTB
    #define AJ_SEG7_DIGIT0_POS         0U
    #define AJ_SEG7_DIGIT0_MASK        (1U << AJ_SEG7_DIGIT0_POS)

    #define AJ_SEG7_DIGIT1_DDR         DDRB
    #define AJ_SEG7_DIGIT1_PORT        PORTB
    #define AJ_SEG7_DIGIT1_POS         1U
    #define AJ_SEG7_DIGIT1_MASK        (1U << AJ_SEG7_DIGIT1_POS)

    #define AJ_SEG7_DIGIT2_DDR         DDRB
    #define AJ_SEG7_DIGIT2_PORT        PORTB
    #define AJ_SEG7_DIGIT2_POS         2U
    #define AJ_SEG7_DIGIT2_MASK        (1U << AJ_SEG7_DIGIT2_POS)

    #define AJ_SEG7_DIGIT3_DDR         DDRB
    #define AJ_SEG7_DIGIT3_PORT        PORTB
    #define AJ_SEG7_DIGIT3_POS         3U
    #define AJ_SEG7_DIGIT3_MASK        (1U << AJ_SEG7_DIGIT3_POS)

    #define AJ_SEG7_DIGIT4_DDR         DDRB
    #define AJ_SEG7_DIGIT4_PORT        PORTB
    #define AJ_SEG7_DIGIT4_POS         4U
    #define AJ_SEG7_DIGIT4_MASK        (1U << AJ_SEG7_DIGIT4_POS)

    #define AJ_SEG7_DIGIT5_DDR         DDRB
    #define AJ_SEG7_DIGIT5_PORT        PORTB
    #define AJ_SEG7_DIGIT5_POS         5U
    #define AJ_SEG7_DIGIT5_MASK        (1U << AJ_SEG7_DIGIT5_POS)

    #define AJ_SEG7_DIGIT6_DDR         DDRB
    #define AJ_SEG7_DIGIT6_PORT        PORTB
    #define AJ_SEG7_DIGIT6_POS         6U
    #define AJ_SEG7_DIGIT6_MASK        (1U << AJ_SEG7_DIGIT6_POS)

    #define AJ_SEG7_DIGIT7_DDR         DDRB
    #define AJ_SEG7_DIGIT7_PORT        PORTB
    #define AJ_SEG7_DIGIT7_POS         7U
    #define AJ_SEG7_DIGIT7_MASK        (1U << AJ_SEG7_DIGIT7_POS)

    #define AJ_SEG7_A_DDR              DDRD
    #define AJ_SEG7_A_PORT             PORTD
    #define AJ_SEG7_A_POS              0U
    #define AJ_SEG7_A_MASK             (1U << AJ_SEG7_A_POS)

    #define AJ_SEG7_B_DDR              DDRD
    #define AJ_SEG7_B_PORT             PORTD
    #define AJ_SEG7_B_POS              1U
    #define AJ_SEG7_B_MASK             (1U << AJ_SEG7_B_POS)

    #define AJ_SEG7_C_DDR              DDRD
    #define AJ_SEG7_C_PORT             PORTD
    #define AJ_SEG7_C_POS              2U
    #define AJ_SEG7_C_MASK             (1U << AJ_SEG7_C_POS)

    #define AJ_SEG7_D_DDR              DDRD
    #define AJ_SEG7_D_PORT             PORTD
    #define AJ_SEG7_D_POS              3U
    #define AJ_SEG7_D_MASK             (1U << AJ_SEG7_D_POS)

    #define AJ_SEG7_E_DDR              DDRD
    #define AJ_SEG7_E_PORT             PORTD
    #define AJ_SEG7_E_POS              4U
    #define AJ_SEG7_E_MASK             (1U << AJ_SEG7_E_POS)

    #define AJ_SEG7_F_DDR              DDRD
    #define AJ_SEG7_F_PORT             PORTD
    #define AJ_SEG7_F_POS              5U
    #define AJ_SEG7_F_MASK             (1U << AJ_SEG7_F_POS)

    #define AJ_SEG7_G_DDR              DDRD
    #define AJ_SEG7_G_PORT             PORTD
    #define AJ_SEG7_G_POS              6U
    #define AJ_SEG7_G_MASK             (1U << AJ_SEG7_G_POS)

    #define AJ_SEG7_DP_DDR             DDRD
    #define AJ_SEG7_DP_PORT            PORTD
    #define AJ_SEG7_DP_POS             7U
    #define AJ_SEG7_DP_MASK            (1U << AJ_SEG7_DP_POS)

#endif
