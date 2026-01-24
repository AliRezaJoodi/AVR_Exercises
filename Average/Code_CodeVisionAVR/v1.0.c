// GitHub Account:  GitHub.com/AliRezaJoodi

#include "_ExtraLibrary/_hardware.h"

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <stdint.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include <utility.h>
#include <adc.h>
#include <sensor_lm35.h>
#include <average.h>
#include <changed.h>
#include <display_lcd_char.h>

#define TASK_TEMP1          0
#define TASK_TEMP2          1
//#define TASK_LCD1           2
//#define TASK_LCD2           3

void LCD_Config(void);
void LCD_DisplayMainPage(float temp, uint8_t line);

void main(void){
    float temp1 = 0;
    uint16_t temp1_u16=0; 
    uint16_t temp1_u16_last=0;
    AverageBlock_u16_t temp1_u16_t = {0};
    //AverageMoving_u16_t temp1_u16_t = {0};

    float temp2 = 0;
    uint16_t temp2_u16=0;
    uint16_t temp2_u16_last=0;
    AverageBlock_u16_t temp2_u16_t = {0};
    
    float buf_f32=0; 
    uint8_t tasks=0;
    
    LCD_Config();
    ADC_Config_AVCC_10Bit();
    Char_Define(char0,0); 
      
    while(1){
          temp1_u16 = ADC_GetCounts(LM35_CH1);
          temp1_u16 = Average_BlockUpdate_u16(temp1_u16, &temp1_u16_t);
          //temp1_u16 = Average_MovingWithCircularbuf_f32fer_u16(temp1_u16, &temp1_u16_t);
          if( Changed_Exact_u16(temp1_u16, &temp1_u16_last) ){
            buf_f32 = ADC_ConvertCountsToMilliVolt(temp1_u16);
            temp1 = LM35_ConvertMilliVoltToTemp(buf_f32);
            SetBit(tasks, TASK_TEMP1)
          }
          
          temp2_u16 = ADC_GetCounts(LM35_CH2);
          temp2_u16 = Average_BlockUpdate_u16(temp2_u16, &temp2_u16_t);
          if( Changed_Exact_u16(temp2_u16, &temp2_u16_last) ){
            buf_f32 = ADC_ConvertCountsToMilliVolt(temp2_u16);
            temp2 = LM35_ConvertMilliVoltToTemp(buf_f32);
            SetBit(tasks, TASK_TEMP2)
          }
          
          if(GetBit(tasks, TASK_TEMP1)){
            ClearBit(tasks, TASK_TEMP1);
            LCD_DisplayMainPage(temp1, 1);
          }
          
          if(GetBit(tasks, TASK_TEMP2)){
            ClearBit(tasks, TASK_TEMP2);
            LCD_DisplayMainPage(temp2, 2);
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
            lcd_gotoxy(0,0);
            lcd_putsf("Temp1:");
            ftoa(temp,1,txt);
            lcd_puts(txt);
            lcd_putchar(0);
            lcd_putsf("   "); 
            break;
        case 2:
            lcd_gotoxy(0,1);
            lcd_putsf("Temp2:");
            ftoa(temp,1,txt);
            lcd_puts(txt);
            lcd_putchar(0);
            lcd_putsf("   "); 
            break;
        default:
            break;
    }
}




