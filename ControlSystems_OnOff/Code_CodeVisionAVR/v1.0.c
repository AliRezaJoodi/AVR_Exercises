#include <mega32a.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <display_lcd_char.h>
#include <controller_onoff.h>

#ifndef RLY0_DDR
    #define RLY0_DDR DDRC.1
    #define RLY0_PORT PORTC.1
    #define RLY0_PIN PINC.1 
#endif
#define RLY0 RLY0_PORT
#define RLY0_INDEX 0
#define HEATER_RLY RLY0_PORT

#ifndef RLY1_DDR
    #define RLY1_DDR DDRC.2
    #define RLY1_PORT PORTC.2
    #define RLY1_PIN PINC.2 
#endif
#define RLY1 RLY1_PORT
#define RLY1_INDEX 0
#define COOLER_RLY RLY1_PORT

#ifndef ACTIVATE_RLY
    #define ACTIVATE_RLY 1
#endif
#define DEACTIVATE_RLY !ACTIVATE_RLY
#define DEFAULT_RLY DEACTIVATE_RLY

#pragma used+
float in_v=0; 
float in_mv=0; 
float temp=0;
float sp=250; 
float hystersis=10;
#pragma used-
    
void Config_LCD(void);
void Config_IO(void);

#pragma used+
void LCD_DisplayLoadingPage(void); 
void LCD_DisplayMainPage(void);
void LCD_DisplayMainPage2(void);
void LCD_DisplayMainPage3(void);
#pragma used-

void main(void){ 
    LCD_DisplayLoadingPage();    
    ADC_Config_AVCC_10Bit();      
    Config_IO();
    Config_LCD(); 
    Char_Define(char0, 0);
    delay_ms(250); lcd_clear(); 
    
    while(1){
        in_v=ADC_GetVolt(TEMP_CH); 
        temp=in_v*TEMP_GAIN;  
        LCD_DisplayMainPage();
        HEATER_RLY=Controller_OnOff2_Heater(sp,temp,hystersis);
        //COOLER_RLY=Controller_OnOff2_Cooler(sp,temp,hystersis);
    }
}

//******************************************
void LCD_DisplayMainPage(void){
    char txt[16]; 
    sprintf(txt,"Temp=%3.1f",temp); lcd_gotoxy(0,0); lcd_puts(txt); lcd_putchar(0); lcd_putsf("  ");
    sprintf(txt,"%3.0f<%3.0f<%3.0f",sp-(hystersis/2),sp,sp+(hystersis/2)); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("   ");
}

//******************************************
void LCD_DisplayMainPage2(void){
    char txt[16]; 
    sprintf(txt,"Temp=%3.1f",temp); lcd_gotoxy(0,0); lcd_puts(txt); lcd_putchar(0); lcd_putsf("  ");
    sprintf(txt,"Setpoint=%3.1f",sp); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putchar(0); lcd_putsf("  ");
}

//******************************************
void LCD_DisplayMainPage3(void){
    char txt[16]; 
    sprintf(txt,"PV=%2.0f",temp); lcd_gotoxy(0,0); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" ");
    sprintf(txt,"SP=%2.0f",sp); lcd_gotoxy(8,0); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" ");
    lcd_gotoxy(0,1); lcd_putsf("ON/OFF Control"); 
}

//******************************************
void Config_IO(void){
    #define INPUT 0   
    #define OUTPUT !INPUT
    RLY0_DDR=OUTPUT; RLY0_PORT=DEFAULT_RLY; 
    RLY1_DDR=OUTPUT; RLY1_PORT=DEFAULT_RLY;
}

//********************************************************
void Config_LCD(void){
    lcd_init(16);
    lcd_clear();
}

//********************************************************
void LCD_DisplayLoadingPage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
}
