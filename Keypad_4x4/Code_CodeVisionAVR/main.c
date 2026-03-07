// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include "hardware.h"
#include "keypad4x4.h"

void LCD_Config(void);
void LCD_DisplayloadingPage(void);
void LCD_DisplayMainPage(char);

unsigned char numer;

void main(void){
    unsigned char numer_old = 0;

    LCD_Config();
    LCD_DisplayloadingPage(); delay_ms(250); lcd_clear();

    while(1){
        numer = Keypad4x4_GetInitialNumber();
        numer = Keypad4x4_ConvertNumber(numer);
//        numer=Keypad4x4_GetNumber();

        if(numer_old != numer){
            numer_old = numer;
            LCD_DisplayMainPage(numer);
  	    }
    }
}


//*******************************************************
void LCD_DisplayMainPage(unsigned char x2){
    char txt[16];

    lcd_clear();
    lcd_gotoxy(0,0); itoa(x2, txt); lcd_puts(txt); lcd_putsf("  ");
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






