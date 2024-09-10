// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <stdio.h>
#include <delay.h>
#include <alcd.h>

#include "Attachment\hardware_v1.0.h"
#include <display_lcd_char.h>
#include <adc.h>
#include <sensor_thermocouple_k.h>

float tc_mv=0;
int tc_temp;

void Config_LCD(void);

#pragma used+
void Display_Temp(float,int);
void Test(void);
#pragma used-

void main(void){
    Config_LCD();
    Char_Define(char0, 0);
    ADC_Config_AVCC_10Bit();
    
    //Test();
     
    while (1){   
        tc_mv=ADC_GetMilliVolt(TC_CH); 
        tc_temp=TC_ConvertMilliVoltToTemp(tc_mv);
        Display_Temp(tc_mv,tc_temp);       
        delay_ms(250);
    }
}

//******************************************
void Test(void){
    tc_mv=TC_ConvertTempToMilliVolt(1000);
    //tc_mv = -6.404; 
    //tc_temp=TC_ConvertMilliVoltToTemp(tc_mv);
    Display_Temp(tc_mv,tc_temp); 
    while(1){}
}

//******************************************
void Display_Temp(float in_mv,int temp){
    char txt[16];
    lcd_clear();
    //lcd_gotoxy(0,1); lcd_putsf("Type K TC"); 
    sprintf(txt,"TC:%4.3fmV",in_mv); lcd_gotoxy(0,0); lcd_puts(txt); //lcd_putsf("  ");
    if(-270<=temp && temp<=1372){    
        //sprintf(txt,"%4.3fmV  %4d",in_mv, tc_temp); lcd_gotoxy(0,0); lcd_puts(txt); lcd_putchar(0); //lcd_putsf("  ");
        sprintf(txt,"TC:%4d",tc_temp); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putchar(0); //lcd_putsf("  ");  
    }
    else{lcd_gotoxy(0,1); lcd_putsf("TC:Null"); lcd_putsf("    ");};  
}

//********************************************************
void Config_LCD(void){
    lcd_init(16);
    lcd_clear();
}



   
