// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>

#include <mega32a.h>
#include <delay.h>

#include "hardware.h"

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include <utility_bit.h>
#include <button.h>

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);

void main(void){  
    uint8_t value=100;
    uint8_t value_last=0;

Button_t button_incr = {
    .hw_ddr  = &BUTTON1_DDR,
    .hw_pin  = &BUTTON1_PIN,
    .hw_port = &BUTTON1_PORT,
    .hw_bit  = BUTTON1_BIT,
    .config  = BUTTON_MODE_PULLUP | BUTTON_ACTIVE_LOW,       
    .state   = 0,
    .counter = 0
};

Button_t button_decr = {
    .hw_ddr  = &BUTTON2_DDR,
    .hw_pin  = &BUTTON2_PIN,
    .hw_port = &BUTTON2_PORT,
    .hw_bit  = BUTTON2_BIT,
    .config  = BUTTON_MODE_FLOATING | BUTTON_ACTIVE_LOW, 
    .state   = 0,
    .counter  = 0
};

Button_t button_clear = {
    .hw_ddr  = &BUTTON3_DDR,
    .hw_pin  = &BUTTON3_PIN,
    .hw_port = &BUTTON3_PORT,
    .hw_bit  = BUTTON3_BIT,
    .config  = BUTTON_MODE_FLOATING | BUTTON_ACTIVE_LOW, 
    .state   = 0,
    .counter = 0
};

    Button_Config(&button_incr); 
    //Button_SetPullUp(&button_incr, 1);
    Button_Config(&button_decr);
    Button_Config(&button_clear);
        
    LCD_Config();
    LCD_DisplayMainPage(value);
   
    while(1){ 
        if( Button_GetAutoRepeat_NonBlocking(&button_incr) ){
            ++value;
        }
        
        if( Button_GetSingleClick(&button_decr) ){
            --value;
        }
        
        if( Button_GetLongPress_NonBlocking(&button_clear) ){
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




