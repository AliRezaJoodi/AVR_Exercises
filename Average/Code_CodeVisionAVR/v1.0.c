// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <stdint.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#pragma used+
//uint16_t input_int=0;
//float input_mv=0;
//float input_v=0;
//float temp=0;
#pragma used-

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <sensor_lm35.h>
#include <average_static.h>
#include <display_lcd_char.h>

void LCD_Config(void);
void LCD_DisplayMainPage(float);

void main(void){
    uint16_t input_int=0;     
    uint16_t input_int_hys=0;
    float mv=0;  
    float temp=0;
    
    LCD_Config();
    ADC_Config_AVCC_10Bit();
    Char_Define(char0,0); 
    
    while(1){
          input_int = ADC_GetIn(LM35_CH);
          input_int = Average_BlockUpdate_uint16(input_int);
          if(input_int_hys != input_int){
            input_int_hys = input_int;
            mv = ADC_ConvertInToMilliVolt(input_int);
            temp = LM35_ConvertMilliVoltToTemp_Celsius(mv);
            LCD_DisplayMainPage(temp);
          }                                       
    };
}

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();   
}

//********************************************************
void LCD_DisplayMainPage(float temp){
    char txt[16];
     
    lcd_gotoxy(0,0);lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" "); 
    lcd_gotoxy(0,1); lcd_putsf("Average");  
}




