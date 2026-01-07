// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _BUTTON_INCLUDED
#define _BUTTON_INCLUDED

#include <delay.h>
#include <stdint.h>
#include <utility.h> 

#define BUTTON_PRESSED      0
#define BUTTON_LAG1         30          // SingleClick  Lag, Value: 0~65535, Unit: ms  
#define BUTTON_LAG2         500         // Auto Repeat Lag, Value: 0~65535
#define BUTTON_LAG3         10000       // Long Press Lag, Value: 0~65535

typedef struct{
    volatile unsigned char  *btn_ddr;
    volatile unsigned char  *btn_pin;
    volatile unsigned char  *btn_port;
    uint8_t                 btn_bit;
    uint8_t                 status;
    uint16_t                counter;
} Button_t;

void    Button_Config                   (Button_t *btn);

#pragma used+
void    Button_DisablePullUp            (Button_t *btn);
uint8_t Button_SingleClick              (Button_t *btn);
uint8_t Button_AutoRepeat_NonBlocking   (Button_t *btn);
uint8_t Button_LongPress_NonBlocking    (Button_t *btn);
#pragma used-

#pragma library button.lib
#endif
