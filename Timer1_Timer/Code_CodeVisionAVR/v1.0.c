//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <alcd.h>

//#define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
//#define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
//#define TOGGLEBIT(ADDRESS,BIT)      (ADDRESS^=(1<<BIT))
//#define EQUBIT(ADDRESS,BIT,value)   {if (value) SETBIT(ADDRESS,BIT); else CLRBIT(ADDRESS,BIT);}
//#define CHKBIT(ADDRESS,BIT)         ((ADDRESS &(1<<BIT))>>BIT)

unsigned char value=0;

void ConfigLCD(void);
void DisplayMainPage(char);

#include "Attachment\Timer1.h"

void main(void){
    
    ConfigLCD();
    DisplayMainPage(value);
     
    #asm("sei") // Global enable interrupts 
    ConfigTimer1ForTimer(); 
    SetPerscalerFromTimer1(PERSCALER_8);
    DisableOverflowInterruptFromTimer1();
    ResetTimer1();
    EnableOverflowInterruptFromTimer1();
    //DisableClockSourceFromTimer1();
         
    while(1){
        if(task_t1){
            task_t1=0; 
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
    lcd_gotoxy(0,1); lcd_putsf("Config Timer1");    
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}
