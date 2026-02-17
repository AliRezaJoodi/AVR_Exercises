// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef DISPLAY7SEGMENT4DIGIT2DISPLAY_DRIVER_HW_INCLOUDED
#define DISPLAY7SEGMENT4DIGIT2DISPLAY_DRIVER_HW_INCLOUDED

#include <io.h>

#define ACTIVATE_DIGIT      1
#define ACTIVATE_SEGMENT    0

#define D1_0_DDR            DDRB.0
#define D1_0_PORT           PORTB.0
#define D1_0_PIN            PINB.0
#define D1_0                D1_0_PORT

#define D1_1_DDR            DDRB.1
#define D1_1_PORT           PORTB.1
#define D1_1_PIN            PINB.1
#define D1_1                D1_1_PORT

#define D1_2_DDR            DDRB.2
#define D1_2_PORT           PORTB.2
#define D1_2_PIN            PINB.2
#define D1_2                D1_2_PORT

#define D1_3_DDR            DDRB.3
#define D1_3_PORT           PORTB.3
#define D1_3_PIN            PINB.3
#define D1_3                D1_3_PORT

#define D2_0_DDR            DDRB.4
#define D2_0_PORT           PORTB.4
#define D2_0_PIN            PINB.4
#define D2_0                D2_0_PORT

#define D2_1_DDR            DDRB.5
#define D2_1_PORT           PORTB.5
#define D2_1_PIN            PINB.5
#define D2_1                D2_1_PORT

#define D2_2_DDR            DDRB.6
#define D2_2_PORT           PORTB.6
#define D2_2_PIN            PINB.6
#define D2_2                D2_2_PORT

#define D2_3_DDR            DDRB.7
#define D2_3_PORT           PORTB.7
#define D2_3_PIN            PINB.7
#define D2_3                D2_3_PORT

#define A_DDR               DDRD.0
#define A_PORT              PORTD.0
#define A_PIN               PIND.0
#define A_SEGMENT           A_PORT

#define B_DDR               DDRD.1
#define B_PORT              PORTD.1
#define B_PIN               PIND.1
#define B_SEGMENT           B_PORT

#define C_DDR               DDRD.2
#define C_PORT              PORTD.2
#define C_PIN               PIND.2
#define C_SEGMENT           C_PORT

#define D_DDR               DDRD.3
#define D_PORT              PORTD.3
#define D_PIN               PIND.3
#define D_SEGMENT           D_PORT

#define E_DDR               DDRD.4
#define E_PORT              PORTD.4
#define E_PIN               PIND.4
#define E_SEGMENT           E_PORT

#define F_DDR               DDRD.5
#define F_PORT              PORTD.5
#define F_PIN               PIND.5
#define F_SEGMENT           F_PORT

#define G_DDR               DDRD.6
#define G_PORT              PORTD.6
#define G_PIN               PIND.6
#define G_SEGMENT           G_PORT

#define DP_DDR              DDRD.7
#define DP_PORT             PORTD.7
#define DP_PIN              PIND.7
#define DP_SEGMENT          DP_PORT

#endif






