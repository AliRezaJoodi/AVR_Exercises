#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#define LED_DDR     DDRB
#define LED_PORT    PORTB
#define LED_PIN     PINB
#define LED_BIT     0U
#define LED_MASK    (1U << LED_BIT)

#define KEY_DDR     DDRA
#define KEY_PORT    PORTA
#define KEY_PIN     PINA
#define KEY_BIT     0U
#define KEY_MASK    (1U << KEY_BIT)

#define OUT_DDR     DDRC
#define OUT_PORT    PORTC
#define OUT_PIN     PINC
#define OUT_BIT     2U
#define OUT_MASK    (0x0FU << OUT_BIT)

#define IN_DDR     DDRB
#define IN_PORT    PORTB
#define IN_PIN     PINB
#define IN_BIT     3U
#define IN_MASK    (0x0FU << IN_BIT)
#endif
