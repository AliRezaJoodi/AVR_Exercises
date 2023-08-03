// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>

#include <Attachment\DataConverter.h>

void ConfigLCD(void);
void DisplayMainPage(void);

unsigned int number=589;
unsigned char number_msb;
unsigned char number_lsb;

void main(void){
    ConfigLCD(); 

    number_msb=GetMsb(number);
    number_lsb=GetLsb(number);
    number=GetInt(number_msb,number_lsb);
    DisplayMainPage();  

    while(1){  
    }     
}

//**************************************************
void DisplayMainPage(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("Value  MSB   LSB");
    itoa(number,txt); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("  ");  
    itoa(number_msb,txt); lcd_gotoxy(7,1); lcd_puts(txt); lcd_putsf("  "); 
    itoa(number_lsb,txt); lcd_gotoxy(13,1); lcd_puts(txt); lcd_putsf("  ");
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}