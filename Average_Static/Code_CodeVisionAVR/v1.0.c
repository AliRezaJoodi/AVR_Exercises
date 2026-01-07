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

#include <adc.h>
#include <sensor_lm35.h>
#include <average_static.h>
#include <changed_static.h>
#include <display_lcd_char.h>

void LCD_Config(void);
void LCD_DisplayMainPage(float);

void main(void){
    uint16_t input_u16=0;     
    float buf=0;
    
    LCD_Config();
    ADC_Config_AVCC_10Bit();
    Char_Define(char0,0); 
       
    while(1){
          input_u16 = ADC_GetCounts(LM35_CH);
          input_u16 = Average_BlockUpdate_u16(input_u16);
          
          if(Changed_Exact_u16(input_u16)){
            buf = ADC_ConvertCountsToMilliVolt(input_u16);
            buf = LM35_ConvertMilliVoltToTemp_Celsius(buf);
            LCD_DisplayMainPage(buf);
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




