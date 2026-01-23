// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <stdint.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>

#include <utility_byte.h>

void LCD_Config(void);
void LCD_DisplayMainPage(void);

uint16_t number = 589;
uint8_t number_msb;
uint8_t number_lsb;

void main(void){
    LCD_Config(); 
    
    number_msb = GetMsb(number);
    number_lsb = GetLsb(number);
    number = MakeU16(number_msb,number_lsb); 
    
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