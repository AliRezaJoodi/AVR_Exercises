//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <alcd.h>

#include <timer0.h>

void ConfigLCD(void);
void DisplayMainPage(char);

void main(void){
    unsigned char value=0;
    
    ConfigLCD();
    DisplayMainPage(value);
     
    Timer0_ConfigForTimer(); 
         
    while(1){ 
        if(task_t0_ovf){
            task_t0_ovf=0; 
            ++value;
            DisplayMainPage(value); 
        }    
    };
}

//**********************************
void DisplayMainPage(char x){
    char txt[16]; 
    //lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("i="); itoa(x,txt); lcd_puts(txt); lcd_putsf("   ");
    lcd_gotoxy(0,1); lcd_putsf("Config Timer0");    
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}
