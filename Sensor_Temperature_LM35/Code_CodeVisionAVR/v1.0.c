// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <alcd.h>

#pragma used+

float input_mv=0;
float input_v=0;
float temp=0;
#pragma used-

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <sensor_lm35.h>
#include <display_lcd_char.h>

void LCD_Config(void);

#pragma used+
void LCD_DisplayMainPage(float,float);
void LCD_DisplayMainPage2(float);
#pragma used-

void main(void){
    LCD_Config();
    Char_Define(char0, 0);
    ADC_Config_AVCC_10Bit();

    while(1){ 
        input_mv=ADC_GetMilliVolt(LM35_CH); 
        temp=LM35_ConvertMilliVoltToTemp(input_mv);
        LCD_DisplayMainPage(input_mv, temp);
        delay_ms(250);                                       
    };
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void LCD_DisplayMainPage(float mv,float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Input:"); ftoa(mv,1,txt); lcd_puts(txt); lcd_putsf("mV  ");
    lcd_gotoxy(0,1); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" ");   
}

//********************************************************
void LCD_DisplayMainPage2(float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" "); 
    lcd_gotoxy(0,1); lcd_putsf("LM35 Sensor");  
}



