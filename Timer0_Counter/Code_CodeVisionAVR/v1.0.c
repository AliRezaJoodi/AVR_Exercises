// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <alcd.h>

unsigned char value=0;

void ConfigLCD(void);
void DisplayMainPage(char,char);

#include <timer0.h>

void main(void){
    unsigned char old_value=0;
    ConfigLCD();
    DisplayMainPage(TCNT0,value);
     
    Timer0_ConfigForCounter(); 
    Timer0_SetTimerValue(250);
         
    while(1){ 
        if(task_t0_ovf){
            task_t0_ovf=0; 
            ++value;
            //DisplayMainPage(value); 
        }
        if(old_value!=TCNT0){
            old_value=TCNT0;
            DisplayMainPage(TCNT0,value);    
        }      
    };
}

//**********************************
void DisplayMainPage(char x1, char x2){
    char txt[16];
     
    //lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("TCNT0="); itoa(x1,txt); lcd_puts(txt); lcd_putsf("   ");
    lcd_gotoxy(0,1); lcd_putsf("i="); itoa(x2,txt); lcd_puts(txt); lcd_putsf("   ");
    //lcd_gotoxy(0,1); lcd_putsf("Config Timer0");    
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}
