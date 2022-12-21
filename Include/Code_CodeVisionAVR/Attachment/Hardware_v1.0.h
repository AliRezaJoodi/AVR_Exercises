//******************************* Config Inputs
#define BUTTON1_DDR DDRD.0
#define BUTTON1_PORT PORTD.0
#define BUTTON1_PIN PIND.0
#define BUTTON1 BUTTON1_PIN

#define BUTTON2_DDR DDRD.1
#define BUTTON2_PORT PORTD.1
#define BUTTON2_PIN PIND.1
#define BUTTON2 BUTTON2_PIN

#define PRESS_BUTTON 0
#define DEFAULT_BUTTON !PRESS_BUTTON

//******************************* Config Outputs
#define LED1_DDR DDRC.5
#define LED1_PORT PORTC.5
#define LED1_PIN PINC.5
#define LED1 LED1_PORT

#define ACTIVATE_LED 1
#define DEACTIVATE_LED !ACTIVATE_LED
#define DEFAULT_LED DEACTIVATE_LED


