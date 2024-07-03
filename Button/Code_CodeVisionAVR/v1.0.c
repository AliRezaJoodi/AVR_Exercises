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

#include "Attachment\HardwarePorting_v1.0.h"
#include <Button.h>

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);

void main(void){  
    unsigned char value=100;
    unsigned char old_value=0;
    
    Button_Config();
    LCD_Config(); LCD_DisplayMainPage(value);
   
    while(1){ 
        if(Button1_OneStep()){++value;}
        if(Button2_Continuous()){++value;}   
        if(Button3_OneStep()){value=0;}
        
        if(old_value!=value){LCD_DisplayMainPage(value); old_value=value;}
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




