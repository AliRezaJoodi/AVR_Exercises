// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

#include "Attachment\Button.h"

void LCD_Display_MainPage(unsigned char);

void main(void){  
    unsigned char value=100;
    unsigned char old_value=0;
    
    Button_Config();
    LCD_Config(); LCD_Display_MainPage(value);
   
    while(1){ 
        if(Button_UpButton_OneStep()){++value;}
        if(Button_UpButton_Continuous()){++value;}   
        if(Button_ResetButton_OneStep()){value=0;}
        
        if(old_value!=value){LCD_Display_MainPage(value); old_value=value;}
    };
}

//********************************************************
void LCD_Display_MainPage(unsigned char value){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}




