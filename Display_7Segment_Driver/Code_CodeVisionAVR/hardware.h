#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define SEG7_DRIVER_HARDWARE
    #define SEG7_DIGITS_COUNT       8U
    #define SEG7_DIGITS_ACTIVATE    1U
    #define SEG7_SEGMENTS_ACTIVATE  0U

    #define SEG7_DIGIT0_DDR         DDRB
    #define SEG7_DIGIT0_PORT        PORTB
    #define SEG7_DIGIT0_BIT         0
    #define SEG7_DIGIT0_MASK        (1U << SEG7_DIGIT0_BIT)

    #define SEG7_DIGIT1_DDR         DDRB
    #define SEG7_DIGIT1_PORT        PORTB
    #define SEG7_DIGIT1_BIT         1
    #define SEG7_DIGIT1_MASK        (1U << SEG7_DIGIT1_BIT)

    #define SEG7_DIGIT2_DDR         DDRB
    #define SEG7_DIGIT2_PORT        PORTB
    #define SEG7_DIGIT2_BIT         2
    #define SEG7_DIGIT2_MASK        (1U << SEG7_DIGIT2_BIT)

    #define SEG7_DIGIT3_DDR         DDRB
    #define SEG7_DIGIT3_PORT        PORTB
    #define SEG7_DIGIT3_BIT         3
    #define SEG7_DIGIT3_MASK        (1U << SEG7_DIGIT3_BIT)

    #define SEG7_DIGIT4_DDR         DDRB
    #define SEG7_DIGIT4_PORT        PORTB
    #define SEG7_DIGIT4_BIT         4
    #define SEG7_DIGIT4_MASK        (1U << SEG7_DIGIT4_BIT)

    #define SEG7_DIGIT5_DDR         DDRB
    #define SEG7_DIGIT5_PORT        PORTB
    #define SEG7_DIGIT5_BIT         5
    #define SEG7_DIGIT5_MASK        (1U << SEG7_DIGIT5_BIT)

    #define SEG7_DIGIT6_DDR         DDRB
    #define SEG7_DIGIT6_PORT        PORTB
    #define SEG7_DIGIT6_BIT         6
    #define SEG7_DIGIT6_MASK        (1U << SEG7_DIGIT6_BIT)

    #define SEG7_DIGIT7_DDR         DDRB
    #define SEG7_DIGIT7_PORT        PORTB
    #define SEG7_DIGIT7_BIT         7
    #define SEG7_DIGIT7_MASK        (1U << SEG7_DIGIT7_BIT)

    #define SEG7_A_DDR              DDRD
    #define SEG7_A_PORT             PORTD
    #define SEG7_A_BIT              0U
    #define SEG7_A_MASK             (1U << SEG7_A_BIT)

    #define SEG7_B_DDR              DDRD
    #define SEG7_B_PORT             PORTD
    #define SEG7_B_BIT              1U
    #define SEG7_B_MASK             (1U << SEG7_B_BIT)

    #define SEG7_C_DDR              DDRD
    #define SEG7_C_PORT             PORTD
    #define SEG7_C_BIT              2U
    #define SEG7_C_MASK             (1U << SEG7_C_BIT)

    #define SEG7_D_DDR              DDRD
    #define SEG7_D_PORT             PORTD
    #define SEG7_D_BIT              3U
    #define SEG7_D_MASK             (1U << SEG7_D_BIT)

    #define SEG7_E_DDR              DDRD
    #define SEG7_E_PORT             PORTD
    #define SEG7_E_BIT              4U
    #define SEG7_E_MASK             (1U << SEG7_E_BIT)

    #define SEG7_F_DDR              DDRD
    #define SEG7_F_PORT             PORTD
    #define SEG7_F_BIT              5U
    #define SEG7_F_MASK             (1U << SEG7_F_BIT)

    #define SEG7_G_DDR              DDRD
    #define SEG7_G_PORT             PORTD
    #define SEG7_G_BIT              6U
    #define SEG7_G_MASK             (1U << SEG7_G_BIT)

    #define SEG7_DP_DDR             DDRD
    #define SEG7_DP_PORT            PORTD
    #define SEG7_DP_BIT             7U
    #define SEG7_DP_MASK            (1U << SEG7_DP_BIT)

#endif
