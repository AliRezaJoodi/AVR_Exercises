// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <alcd.h>

void ConfigLCD(void);
void DisplayMainPage(char);

#include <timer2.h>

void main(void){
    unsigned char value=0;
    
    ConfigLCD();
    DisplayMainPage(value);
    
    Timer2_ConfigForTimer();
         
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
