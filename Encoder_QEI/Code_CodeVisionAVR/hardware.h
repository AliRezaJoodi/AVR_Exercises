#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_8BIT

#define AJ_QEI_HARDWARE
    #define AJ_QEI_PULL_UP             0U  /**< Disable */
    #define AJ_QEI_AB_CLOSED           0U  /**< Enable */
    #define AJ_QEI_Z                   1U

#define AJ_QEI_HARDWARE_EXTRA
    #define AJ_QEI_A_DDR               DDRD
    #define AJ_QEI_A_PIN               PIND
    #define AJ_QEI_A_PORT              PORTD
    #define AJ_QEI_A_POS               2U
    #define AJ_QEI_A_MASK              (1U << AJ_QEI_A_POS)

    #define AJ_QEI_B_DDR               DDRD
    #define AJ_QEI_B_PIN               PIND
    #define AJ_QEI_B_PORT              PORTD
    #define AJ_QEI_B_POS               3U
    #define AJ_QEI_B_MASK              (1U << AJ_QEI_B_POS)

#define AJ_QEI_HARDWARE_EXTRA2
    #define AJ_QEI_Z_DDR               DDRB
    #define AJ_QEI_Z_PIN               PINB
    #define AJ_QEI_Z_PORT              PORTB
    #define AJ_QEI_Z_POS               2U
    #define AJ_QEI_Z_MASK              (1U << AJ_QEI_Z_POS)

#endif


