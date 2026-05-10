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

#define OUTx4_DDR     DDRC
#define OUTx4_PORT    PORTC
#define OUTx4_PIN     PINC
#define OUTx4_BIT     2U
#define OUTx4_MASK    (0x0FU << OUTx4_BIT)

#define INx4_DDR     DDRB
#define INx4_PORT    PORTB
#define INx4_PIN     PINB
#define INx4_BIT     3U
#define INx4_MASK    (0x0FU << INx4_BIT)
#endif
