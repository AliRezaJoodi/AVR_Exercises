#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define QEI_HARDWARE
    #define QEI_PULL_UP             0U  /**< Disable */
    #define QEI_AB_CLOSED           0U  /**< Enable */
    #define QEI_Z                   1U

#define QEI_HARDWARE_EXTRA
    #define QEI_A_DDR               DDRD
    #define QEI_A_PIN               PIND
    #define QEI_A_PORT              PORTD
    #define QEI_A_BIT               2U
    #define QEI_A_MASK              (1U << QEI_A_BIT)

    #define QEI_B_DDR               DDRD
    #define QEI_B_PIN               PIND
    #define QEI_B_PORT              PORTD
    #define QEI_B_BIT               3U
    #define QEI_B_MASK              (1U << QEI_B_BIT)

#endif


