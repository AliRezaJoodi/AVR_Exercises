// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>

void LCD_Config(void);
void LCD_DisplayMainPage(void);

unsigned int number=589;
unsigned char number_msb;
unsigned char number_lsb;

#include <Converter.h>

void main(void){
    LCD_Config(); 
    
    number_msb=Converter_GetMsb(number);
    number_lsb=Converter_GetLsb(number);
    number=Converter_GetInt(number_msb,number_lsb);
    LCD_DisplayMainPage();  

    while(1){  
    }     
}

//**************************************************
void LCD_DisplayMainPage(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("Value  MSB   LSB");
    itoa(number,txt); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("  ");  
    itoa(number_msb,txt); lcd_gotoxy(7,1); lcd_puts(txt); lcd_putsf("  "); 
    itoa(number_lsb,txt); lcd_gotoxy(13,1); lcd_puts(txt); lcd_putsf("  ");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}