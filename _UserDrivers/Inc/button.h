// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _BUTTON_INCLUDED
#define _BUTTON_INCLUDED


#include <stdint.h>
#include <delay.h>
#include <utility_bit.h> 

/**
 * @note Default hardware macros can be overridden by the user.
 */ 
#include "hardware.h"

#ifndef BUTTON_HARDWARE
#define BUTTON_HARDWARE
    #warning "BUTTON_HARDWARE is not defined; default configuration will be used."
    #define BUTTON_PRESSED              0
    #define BUTTON_SINGLE_CLICK_LAG     30          // Single Click Lag, Value: 0~65535, Unit: ms  
    #define BUTTON_AUTO_REPEAT_LAG      500         // Auto Repeat Lag, Value: 0~65535
    #define BUTTON_LONG_PRESS_LAG       10000       // Long Press Lag, Value: 0~65535
#endif

#ifndef BUTTON_HARDWARE_EXTRA
#define BUTTON_HARDWARE_EXTRA
    #warning "BUTTON_HARDWARE_EXTRA is not defined; default configuration will be used."
    #define BUTTON1_DDR         DDRB
	#define BUTTON1_PIN         PINB
	#define BUTTON1_PORT        PORTB
	#define BUTTON1_BIT         0 
#endif
    
typedef struct{
    volatile uint8_t    *hw_ddr;
    volatile uint8_t    *hw_pin;
    volatile uint8_t    *hw_port;
    uint8_t             hw_bit;
    uint8_t             status;
    uint16_t            counter;
} Button_t;

/*
Example in main code:
Button_t button_incr = {
    .btn_ddr  = &BUTTON1_DDR,
    .hw_pin  = &BUTTON1_PIN,
    .hw_port = &BUTTON1_PORT,
    .btn_bit  = BUTTON1_BIT,
    .status   = 0,
    .counter  = 0
};
*/

void Button_Config(Button_t *btn);
void Button_SetPullUp(Button_t *btn, uint8_t enable);
uint8_t Button_GetSingleClick(Button_t *btn);
uint8_t Button_GetAutoRepeat_NonBlocking(Button_t *btn);
uint8_t Button_GetLongPress_NonBlocking(Button_t *btn);


#pragma library button.lib
#endif
