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

unsigned int value=0;

void ConfigLCD(void);
void DisplayMainPage(int,int);

#include "Attachment\Timer1.h"

void main(void){
    char old_value=0;
    
    ConfigLCD();
    DisplayMainPage(0,value);
     
    #asm("sei") // Global enable interrupts 
    ConfigTimer1ForCounter();
    //T1_INT_DISABLE;
    //T1_RESET; 
    //T1_CLOCK_P1024;
    //T1_INT_ENABLE;
    //T1_CLOCK_STOP;
    TCNT1=0;
         
    while(1){ 
        if(task_t1){
            task_t1=0; 
            ++value;
        }
        
        if(old_value!=TCNT1L){
            old_value=TCNT1L;
            DisplayMainPage((TCNT1H*256)+TCNT1L,value);    
        }      
    };
}

//**********************************
void DisplayMainPage(int x1,int x2){
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
