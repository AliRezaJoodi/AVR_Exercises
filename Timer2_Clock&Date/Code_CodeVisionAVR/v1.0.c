//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

#include <alcd.h>

//unsigned char second,minute,hour;

#include <timer2.h>
#include "Attachment\RTC_Software.h"

void ConfigLCD(void);
void DisplayClock(void);

void main(void){
    
    ConfigLCD();
    
    Timer2_ConfigForAsyncTimer();
    SetClockWithDefaultValues();
    DisplayClock(); 
           
    while(1){ 
        if(task_t2_ovf){
            task_t2_ovf=0;
            ClockCounter();
            DisplayClock();
        }      
    };
}

//******************************************
void DisplayClock(void){
    char txt[16];
    sprintf(txt,"%02u:%02u:%02u",clock.hour,clock.minute,clock.second);
    lcd_gotoxy(0,0); lcd_puts(txt); lcd_putsf("  ");  
    lcd_gotoxy(0,1); lcd_putsf("Timer2(Async)");  
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}
