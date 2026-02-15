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
#include "utility_bit.h"
#include "button.h"

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);

void main(void){  
    uint8_t value=100;
    uint8_t value_last=0;

    Button_t buttonIncr;
    Button_t buttonDecr;
    Button_t buttonClear;

    buttonIncr.hw.ddr   = &BUTTON1_DDR;
    buttonIncr.hw.port  = &BUTTON1_PORT;
    buttonIncr.hw.pin   = &BUTTON1_PIN;
    buttonIncr.hw.index =  BUTTON1_BIT;
    buttonIncr.config   =  BUTTON_MODE_FLOATING | BUTTON_ACTIVE_LOW;
    buttonIncr.state    =  0;
    buttonIncr.counter  =  0;

    buttonDecr.hw.ddr   = &BUTTON2_DDR;
    buttonDecr.hw.port  = &BUTTON2_PORT;
    buttonDecr.hw.pin   = &BUTTON2_PIN;
    buttonDecr.hw.index =  BUTTON2_BIT;
    buttonDecr.config   =  BUTTON_MODE_PULLUP | BUTTON_ACTIVE_LOW;
    buttonDecr.state    =  0;
    buttonDecr.counter  =  0;

    buttonClear.hw.ddr   = &BUTTON3_DDR;
    buttonClear.hw.port  = &BUTTON3_PORT;
    buttonClear.hw.pin   = &BUTTON3_PIN;
    buttonClear.hw.index =  BUTTON3_BIT;
    buttonClear.config   =  BUTTON_MODE_FLOATING | BUTTON_ACTIVE_HIGH;
    buttonClear.state    =  0;
    buttonClear.counter  =  0;

    Button_Config(&buttonIncr); 
    Button_Config(&buttonDecr);
    Button_Config(&buttonClear);
        
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
            value=0;
        }
        
        if( value_last!=value ){
            value_last=value;
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




