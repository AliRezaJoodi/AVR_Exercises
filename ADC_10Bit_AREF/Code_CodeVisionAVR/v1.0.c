// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

#include "Attachment\HardwarePorting_v1.0.h"
#include <ADC.h>

unsigned int input_int=0;
float input_mv=0;
float input_v=0;
    
void LCD_Config(void);
void LCD_DisplayMainPage(void);

void main(void){
   LCD_Config();
   ADC_Config_10Bit_AREF();

    while (1){
        input_int=ADC_GetInt(7);
        input_mv=ADC_GetMilliVolt(7); 
        input_v=ADC_GetVolt(7); 
        LCD_DisplayMainPage();
        delay_ms(250); 
    }   
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[16]; 
    itoa(input_int,txt); lcd_gotoxy(0,0); lcd_putsf("In(0-1023):"); lcd_puts(txt); lcd_putsf(" ");
    ftoa(input_v,3,txt); lcd_gotoxy(0,1); lcd_putsf("In(0-3V3):"); lcd_puts(txt); lcd_putsf(" ");  

}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();
}





