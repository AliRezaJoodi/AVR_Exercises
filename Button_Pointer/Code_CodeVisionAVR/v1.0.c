// GitHub Account: GitHub.com/AliRezaJoodi

#include "_ExtraLibrary\_hardware_v1.0.h"

#include <mega32a.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include <utility.h>
#include <button.h>

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);

void main(void){  
    uint8_t value=100;
    uint8_t value_last=0;

Button_t button1_t = {
    .btn_ddr  = &BUTTON1_DDR,
    .btn_pin  = &BUTTON1_PIN,
    .btn_port = &BUTTON1_PORT,
    .btn_bit  = BUTTON1_BIT,
    .status   = 0,
    .counter  = 0
};

Button_t button2_t = {
    .btn_ddr  = &BUTTON2_DDR,
    .btn_pin  = &BUTTON2_PIN,
    .btn_port = &BUTTON2_PORT,
    .btn_bit  = BUTTON2_BIT,
    .status   = 0,
    .counter  = 0
};

Button_t button3_t = {
    .btn_ddr  = &BUTTON3_DDR,
    .btn_pin  = &BUTTON3_PIN,
    .btn_port = &BUTTON3_PORT,
    .btn_bit  = BUTTON3_BIT,
    .status   = 0,
    .counter  = 0
};

    Button_Config(&button1_t); Button_DisablePullUp(&button1_t);
    Button_Config(&button2_t);
    Button_Config(&button3_t);
        
    LCD_Config();
    LCD_DisplayMainPage(value);
   
    while(1){ 
        if(Button_SingleClick(&button1_t)){
            ++value;
        }
        
        if(Button_AutoRepeat_NonBlocking(&button2_t)){
            ++value;
        }
        
        if(Button_LongPress_NonBlocking(&button3_t)){
            ++value;
        }
        
//        if(Button_SingleClick_NonBlocking(&button2_t)){
//            ++value;
//        }
        
        if(value_last!=value){
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




