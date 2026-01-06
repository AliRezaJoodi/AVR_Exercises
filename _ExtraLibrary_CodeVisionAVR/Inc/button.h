// GitHub Account: GitHub.com/AliRezaJoodi
/*
This library only reads the button state.
The user must configure the button pin as input
and enable the required pull-up or pull-down resistor
before using this library.
*/

#ifndef _BUTTON_INCLUDED
#define _BUTTON_INCLUDED

#include <delay.h>
#include <stdint.h>
#include <utility.h> 

#ifndef BUTTON_HARDWARE
#define BUTTON_HARDWARE
    #define BUTTON_PRESSED      0
    #define BUTTON_LAG1         30          //ms   
    #define BUTTON_LAG2         500         //Button Lag: 0~65535
    #define BUTTON_LAG3         10000       //Button Lag: 0~65535
#endif

typedef struct{
    volatile unsigned char *pin_reg;
    uint8_t pin_bit;
    uint8_t last_status;
} Button_SingleClick_t;

typedef struct{
    volatile unsigned char *pin_reg;
    uint8_t pin_bit;

    uint16_t counter;   // auto repeat counter
} Button_AutoRepeat_t;

typedef struct{
    volatile unsigned char *pin_reg;
    uint8_t pin_bit;

    uint16_t counter;   // press duration counter
    uint8_t triggered;  // prevents retrigger while holding
} Button_LongPress_t;

//typedef struct{
//    volatile unsigned char *pin_reg;  
//    uint8_t pin_bit;                  
//
//    uint8_t last_status;              
//    uint16_t last_time;               
//} Button2_t;

#pragma used+
uint8_t Button_SingleClick(Button_SingleClick_t *btn);
uint8_t Button_AutoRepeat_NonBlocking(Button_AutoRepeat_t *btn);
uint8_t Button_LongPress_NonBlocking(Button_LongPress_t *btn);
//uint8_t Button_SingleClick_NonBlocking(Button2_t *btn);
#pragma used-

#pragma library button.lib
#endif
