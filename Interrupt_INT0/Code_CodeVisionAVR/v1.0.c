// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <alcd.h>

unsigned char value=0;

#include <intrupt_exti.h>

void ConfigLCD(void);
void DisplayMainPage(void);


void main(void){
    ConfigLCD();
    DisplayMainPage();
    
    INT0_Config(RISING_EDGE); 
         
    while(1){
        if(task_int0){
            task_int0=0;
            value=0;
            DisplayMainPage();
        }
        
        ++value;
        DisplayMainPage();
        delay_ms(250);
    };
}

//**********************************
void DisplayMainPage(void){
    char txt[16];
     
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Value="); itoa(value,txt); lcd_puts(txt); lcd_putsf("   ");
    lcd_gotoxy(0,1); lcd_putsf("External INT0");    
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}
