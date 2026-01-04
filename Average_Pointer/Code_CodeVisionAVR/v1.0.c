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

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <sensor_lm35.h>
#include <average_pointer.h>
#include <changed_pointer.h>
#include <display_lcd_char.h>

void LCD_Config(void);
void LCD_DisplayMainPage(float temp, uint8_t line);

void main(void){
    uint16_t temp1_u16=0; 
    uint16_t temp1_u16_last=0;
    AverageBlock_u16_t temp1_u16_t = {0};
    //AverageMoving_u16_t temp1_u16_t = {0};

    uint16_t temp2_u16=0;
    uint16_t temp2_u16_last=0;
    AverageBlock_u16_t temp2_u16_t = {0};
    
    float buf=0;
    
    LCD_Config();
    ADC_Config_AVCC_10Bit();
    Char_Define(char0,0); 
      
    while(1){
          temp1_u16 = ADC_GetCounts(LM35_CH);
          temp1_u16 = Average_BlockUpdate_u16(temp1_u16, &temp1_u16_t);
          //temp1_u16 = Average_MovingWithCircularBuffer_u16(temp1_u16, &temp1_u16_t);

          if( Changed_Exact_u16(temp1_u16, &temp1_u16_last) ){
            buf = ADC_ConvertCountsToMilliVolt(temp1_u16);
            buf = LM35_ConvertMilliVoltToTemp_Celsius(buf);
            LCD_DisplayMainPage(buf, 1);
          }
          
          temp2_u16 = ADC_GetCounts(LM35_CH2);
          temp2_u16 = Average_BlockUpdate_u16(temp2_u16, &temp2_u16_t);

          if( Changed_Exact_u16(temp2_u16, &temp2_u16_last) ){
            buf = ADC_ConvertCountsToMilliVolt(temp2_u16);
            buf = LM35_ConvertMilliVoltToTemp_Celsius(buf);
            LCD_DisplayMainPage(buf, 2);
          }                                      
    };
}

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();   
}

//********************************************************
void LCD_DisplayMainPage(float temp, uint8_t line){
    char txt[16];
    switch (line){
        case 1:
            lcd_gotoxy(0,0);lcd_putsf("Temp1:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf("   "); 
        break;
        case 2:
            lcd_gotoxy(0,1);lcd_putsf("Temp2:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf("   "); 
        break;
            default:
        break;
    }
}




