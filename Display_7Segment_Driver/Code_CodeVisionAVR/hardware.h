#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define SEG7_DRIVER_CONFIG
    #define SEG7_DIGITS_COUNT       8
    #define SEG7_DIGITS_ACTIVATE    1
    #define SEG7_SEGMENTS_ACTIVATE  0

#define SEG7_DRIVER_HARDWARE
    #define SEG7_DIGIT0_DDR          DDRB
    #define SEG7_DIGIT0_PORT         PORTB
    #define SEG7_DIGIT0_BIT          0

    #define SEG7_DIGIT1_DDR          DDRB
    #define SEG7_DIGIT1_PORT         PORTB
    #define SEG7_DIGIT1_BIT          1

    #define SEG7_DIGIT2_DDR          DDRB
    #define SEG7_DIGIT2_PORT         PORTB
    #define SEG7_DIGIT2_BIT          2

    #define SEG7_DIGIT3_DDR          DDRB
    #define SEG7_DIGIT3_PORT         PORTB
    #define SEG7_DIGIT3_BIT          3

    #define SEG7_DIGIT4_DDR          DDRB
    #define SEG7_DIGIT4_PORT         PORTB
    #define SEG7_DIGIT4_BIT          4

    #define SEG7_DIGIT5_DDR          DDRB
    #define SEG7_DIGIT5_PORT         PORTB
    #define SEG7_DIGIT5_BIT          5

    #define SEG7_DIGIT6_DDR          DDRB
    #define SEG7_DIGIT6_PORT         PORTB
    #define SEG7_DIGIT6_BIT          6

    #define SEG7_DIGIT7_DDR          DDRB
    #define SEG7_DIGIT7_PORT         PORTB
    #define SEG7_DIGIT7_BIT          7

    #define SEG7_A_DDR               DDRD
    #define SEG7_A_PORT              PORTD
    #define SEG7_A_BIT               0

    #define SEG7_B_DDR               DDRD
    #define SEG7_B_PORT              PORTD
    #define SEG7_B_BIT               1

    #define SEG7_C_DDR               DDRD
    #define SEG7_C_PORT              PORTD
    #define SEG7_C_BIT               2

    #define SEG7_D_DDR               DDRD
    #define SEG7_D_PORT              PORTD
    #define SEG7_D_BIT               3

    #define SEG7_E_DDR               DDRD
    #define SEG7_E_PORT              PORTD
    #define SEG7_E_BIT               4

    #define SEG7_F_DDR               DDRD
    #define SEG7_F_PORT              PORTD
    #define SEG7_F_BIT               5

    #define SEG7_G_DDR               DDRD
    #define SEG7_G_PORT              PORTD
    #define SEG7_G_BIT               6

    #define SEG7_DP_DDR              DDRD
    #define SEG7_DP_PORT             PORTD
    #define SEG7_DP_BIT              7

#endif
