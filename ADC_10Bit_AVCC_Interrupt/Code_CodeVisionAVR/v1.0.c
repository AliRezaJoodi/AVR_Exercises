// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <alcd.h>

//float input_mv=0;
float input_v=0;

void ConfigLCD(void);
void DisplayMainPage(void);

#include <Attachment\ADC.h>
#include <Attachment\Timer0.h>

void main(void){
    ConfigLCD();
    ConfigADC_Interrupt(SINGLE7);
    ConfigTimer0ForTimer();
     
    EnableGlobalInterrupt(1);
    
    while(1){
        if(task_adc){
            task_adc=0;
            input_v=input_int; input_v=input_v*ADC_GAIN;
            DisplayMainPage();
        }                                         
    };
}

//********************************************************
void DisplayMainPage(void){
    char txt[16];
    
    lcd_gotoxy(0,0); 
    lcd_putsf("In(0-1023):");
    itoa(input_int,txt); lcd_puts(txt); lcd_putsf("  ");
    
    lcd_gotoxy(0,1); 
    lcd_putsf("In(0-5V):");
    ftoa(input_v,3,txt); lcd_puts(txt); lcd_putsf("  ");   
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}



