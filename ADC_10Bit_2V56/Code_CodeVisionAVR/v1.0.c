// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

//float input_mv=0;
float input_v=0;

void LCD_Config(void);
void LCD_DisplayMainPage(void);

#include "Attachment\HardwarePorting_v1.0.h"
#include <ADC.h>

void main(void){
    LCD_Config();
    ADC_Config_2V56_10Bit();
  
    while (1){
        input_int=ADC_GetInt(7);
        input_v=ADC_GetVolt(7); 
        LCD_DisplayMainPage();
        delay_ms(250);                                        
    };
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[16];
    
    lcd_gotoxy(0,0); 
    lcd_putsf("In(0-1023):");
    itoa(input_int,txt); lcd_puts(txt); lcd_putsf(" ");
    
    lcd_gotoxy(0,1); 
    lcd_putsf("In(0-2V56):");
    ftoa(input_v,3,txt); lcd_puts(txt); lcd_putsf(" ");   
}


