// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumberic LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include "hardware.h"
#include "keypad4x4.h"

void LCD_Config(void);
void LCD_DisplayloadingPage(void);
void LCD_DisplayMainPage(char);

uint8_t number;

void main(void){
    uint8_t number_last = 0;

    LCD_Config();
    LCD_DisplayloadingPage(); delay_ms(250); lcd_clear();

    while(1){
        number = Keypad4x4_GetNumber();

        if(number_last != number){
            number_last = number;
            LCD_DisplayMainPage(number);
  	    }
    }
}

//*******************************************************
void LCD_DisplayMainPage(uint8_t number){
    char txt[16];

    lcd_clear();
    lcd_gotoxy(0,0); itoa(number, txt); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("4x4 Keypad");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();
}

//********************************************************
void LCD_DisplayloadingPage(void){
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("4x4Keypad Driver");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
}






