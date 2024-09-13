// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <sensor_lm335.h>
#include <converter_temp.h>
#include <display_lcd_char.h>

void LCD_Config(void);
void LCD_DisplayMainPage(float, float);

float input_mv=0;
float temp_c=0;
float temp_k=0;

void main(void){
    ADC_Config_AVCC_10Bit();
    LCD_Config();
    Char_Define(char0, 0);  
    Char_Define(char1, 1);
    Char_Define(char2, 2);
    
    while (1){
        input_mv = ADC_GetMilliVolt(LM335_CH);
        temp_k = LM335_ConvertMilliVoltToTemp_Kelvin(input_mv);
        temp_c = TempConverter_KtoC(temp_k);
        LCD_DisplayMainPage(temp_k, temp_c);
        delay_ms(300);                                        
    };
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void LCD_DisplayMainPage(float temp_k, float temp_c){
    char buffer[16];
    
    lcd_gotoxy(0,0); 
    lcd_putsf("Temp("); lcd_putchar(1); lcd_putsf("):");
    ftoa(temp_k,1,buffer); lcd_puts(buffer); lcd_putsf(" ");  
    
    lcd_gotoxy(0,1); 
    lcd_putsf("Temp("); lcd_putchar(0); lcd_putsf("):");
    ftoa(temp_c,1,buffer); lcd_puts(buffer); lcd_putsf(" ");    
}

