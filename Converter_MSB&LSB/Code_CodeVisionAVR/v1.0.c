// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>
#include <stdlib.h>

#include <Attachment\Converter_MsbLsb.h>

void Config_LCD(void);
void Display_MainPage(void);

unsigned int number=589;
unsigned char number_msb;
unsigned char number_lsb;

void main(void){
    Config_LCD(); 
    
    number_msb=Get_Msb(number);
    number_lsb=Get_Lsb(number);
    Convert_IntToMsbLsb(number,&number_msb,&number_lsb); 
    number=Convert_MsbLsbToInt(number_msb,number_lsb);
    Display_MainPage(); 
    
    delay_ms(1000); lcd_clear(); delay_ms(500);
    
    number_msb=GET_MSB(number); 
    number_lsb=GET_LSB(number); 
    number=GET_INT(number_msb,number_lsb);
    Display_MainPage();  
        
    while(1){ 
    }     
}

//**************************************************
void Display_MainPage(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("Value  MSB   LSB");
    itoa(number,txt); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("  ");  
    itoa(number_msb,txt); lcd_gotoxy(7,1); lcd_puts(txt); lcd_putsf("  "); 
    itoa(number_lsb,txt); lcd_gotoxy(13,1); lcd_puts(txt); lcd_putsf("  ");
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}