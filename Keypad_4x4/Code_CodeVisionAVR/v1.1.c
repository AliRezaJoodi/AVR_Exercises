// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include "Attachment\hardware_v1.0.h"
#include <keypad4x4.h>

void LCD_Config(void);
void LCD_DisplayloadingPage(void);
void LCD_DisplayMainPage(char, char);

unsigned char numer_initial, numer;   

void main(void){ 
    unsigned char numer_old=0;
    
    LCD_Config();
    LCD_DisplayloadingPage(); delay_ms(250); lcd_clear(); 
    LCD_DisplayMainPage(255, 16);
   
    while(1){
        numer_initial=_Keypad4x4_GetInitialNumber(); 
        //numer=_Keypad4x4_ConvertNumber(numer_initial);
        numer=Keypad4x4_GetNumber();
        
        if(numer<16 && numer_old!=numer){ 
            numer_old= numer;
            LCD_DisplayMainPage(numer_initial, numer);
  	    }
    }
}


//*******************************************************
void LCD_DisplayMainPage(unsigned char x1, unsigned char x2){
    char buffer[16]; 
    lcd_clear();
    
    lcd_gotoxy(0,0); itoa(x1,buffer); lcd_puts(buffer); lcd_putsf("  ");
    lcd_gotoxy(4,0); lcd_putsf("=>"); 
    lcd_gotoxy(7,0); itoa(x2,buffer); lcd_puts(buffer); lcd_putsf("  ");
        
    lcd_gotoxy(0,1); lcd_putsf("4x4Keypad Driver"); 
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






