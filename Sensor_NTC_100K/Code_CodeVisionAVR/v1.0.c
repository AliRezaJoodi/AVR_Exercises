// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <mega32_bits.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

float input_v=0;
float ohm=0;
float temp=0;

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <sensor_thermistor.h>
#include <sensor_thermistor_ntc100k.h>

void LCD_Config(void);

#pragma used+
void LCD_DisplayMainPage(void);
#pragma used+

void main(void){
    LCD_Config();
    ADC_Config_AVCC_10Bit();
    
    while(1){
        input_v=ADC_GetVolt(THERMISTOR_CH);
        ohm=Thermistor_ConvertVoltToOhm_PullUp(input_v);
        ///ohm=201.1;
        temp=NTC100K_ConvertOhmToTemp(ohm);
        LCD_DisplayMainPage();
        delay_ms(250);                                        
    };
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[16];
        
    ///lcd_gotoxy(0,0); 
    ///lcd_putsf("In(V):");
    ///ftoa(input_v,3,txt); lcd_puts(txt); lcd_putsf("  ");
    
    lcd_gotoxy(0,0); 
    lcd_putsf("Ohm:");
    ftoa(ohm,1,txt); lcd_puts(txt); lcd_putsf("  "); 
    
    lcd_gotoxy(0,1); 
    lcd_putsf("Temp(C):");
    ftoa(temp,0,txt); lcd_puts(txt); lcd_putsf("  ");  
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}


