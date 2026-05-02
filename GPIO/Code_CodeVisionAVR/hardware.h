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

#endif
