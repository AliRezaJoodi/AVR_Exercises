// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <alcd.h>

unsigned int value=0;

#include <timer1.h>

void ConfigLCD(void);
void DisplayMainPage(unsigned int, unsigned int);



void main(void){
    char old_value=0;
    
    ConfigLCD();
    DisplayMainPage(0,value);
     
    Timer1_ConfigForCounter();
         
    while(1){ 
        if(task_t1_ovf){
            task_t1_ovf=0; 
            ++value;
        }
        
        if(old_value!=TCNT1L){
            old_value=TCNT1L;
            DisplayMainPage(TCNT1,value);  
        }      
    };
}

//**********************************
void DisplayMainPage(unsigned int x1,unsigned int x2){
    char txt[16]; 
    //lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("TCNT1="); itoa(x1,txt); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("i="); itoa(x2,txt); lcd_puts(txt); lcd_putsf("  ");
    //lcd_gotoxy(0,1); lcd_putsf("Config Timer1");    
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}
