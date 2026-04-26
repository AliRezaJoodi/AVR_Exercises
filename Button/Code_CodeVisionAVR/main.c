// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>

#include <mega32a.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include "hardware.h"
#include "drivers/button.h"

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);

void main(void){
    uint8_t value = 100;
    uint8_t value_last = 0;

    Button_t buttonIncr = {
        .hw = {
            .ddr   = &BUTTON_DDR,
            .port  = &BUTTON_PORT,
            .pin   = &BUTTON_PIN,
            .index = BUTTON_BIT
        },
        .config = {
            .pressed = BUTTON_ACTIVE_LOW,
            .pull    = BUTTON_PULL_NONE
        },
        .state   = 0,
        .counter = 0
    };

    Button_t buttonDecr = {
        .hw = {
            .ddr   = &BUTTON2_DDR,
            .port  = &BUTTON2_PORT,
            .pin   = &BUTTON2_PIN,
            .index = BUTTON2_BIT
        },
        .config = {
            .pressed = BUTTON_ACTIVE_LOW,
            .pull    = BUTTON_PULL_UP
        },
        .state   = 0,
        .counter = 0
    };

    Button_t buttonClear = {
        .hw = {
            .ddr   = &BUTTON3_DDR,
            .port  = &BUTTON3_PORT,
            .pin   = &BUTTON3_PIN,
            .index = BUTTON3_BIT
        },
        .config = {
            .pressed = BUTTON_ACTIVE_HIGH,
            .pull    = BUTTON_PULL_NONE
        },
        .state   = 0,
        .counter = 0
    };

    Button_Init(&buttonIncr);
    Button_Init(&buttonDecr);
    Button_Init(&buttonClear);

    LCD_Config();
    LCD_DisplayMainPage(value);

    while(1){
        if( Button_GetAutoRepeat_NonBlocking(&buttonIncr) ){
            ++value;
        }

        if( Button_GetSingleClick(&buttonDecr) ){
            --value;
        }

        if( Button_GetLongPress_NonBlocking(&buttonClear) ){
            value = 0;
        }

        if( value_last != value ){
            value_last = value;
            LCD_DisplayMainPage(value);
        }
    };
}

//********************************************************
void LCD_DisplayMainPage(unsigned char value){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();
}




