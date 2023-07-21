// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <alcd.h>

unsigned char value=0;

void ConfigLCD(void);
void DisplayMainPage(char);

#include "Attachment\Timer2.h"

void main(void){
    
    ConfigLCD();
    DisplayMainPage(value);
    
    #asm("sei")     //Global enable interrupts 
    ConfigTimer2ForTimer();
    //T2_CLOCK_STOP;
    T2_INT_OVF_DISABLE;
    T2_INT_OVF_ENABLE;
         
    while(1){ 
        if(task_t2_ovf){
            task_t2_ovf=0;
            ++value;
            DisplayMainPage(value); 
        }      
    };
}

//**********************************
void DisplayMainPage(char x){
    char txt[16]; 
    //lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("i="); itoa(x,txt); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Config Timer2");    
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); 
    lcd_clear();   
}
