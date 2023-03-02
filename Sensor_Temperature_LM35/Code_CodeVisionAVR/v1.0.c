// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#pragma used+
unsigned int input_int=0;
float input_mv=0;
float input_v=0;
float temp=0;
#pragma used-

#include <Attachment\ADC.h>
#include <Attachment\LM35.h>
#include <Attachment\Character.h>

void Config_LCD(void);
void Display_temp(float,float);
void Display2_temp(float);

void main(void){
    Config_LCD();
    Config_ADC();
    define_char(CHAR1,0); 
    
    while(1){ 
        input_mv=GetMilliVolt_ADC(CH_LM35); 
        temp=Convert_mVtoTemp_LM35(input_mv);
        Display_temp(input_mv,temp);
        delay_ms(300);                                        
    };
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Display_temp(float mv,float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Input:"); ftoa(mv,1,txt); lcd_puts(txt); lcd_putsf(" mV"); lcd_putsf(" ");
    lcd_gotoxy(0,1); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" ");   
}

//********************************************************
void Display2_temp(float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" "); 
    lcd_gotoxy(0,1); lcd_putsf("LM35 Sensor:");  
}



