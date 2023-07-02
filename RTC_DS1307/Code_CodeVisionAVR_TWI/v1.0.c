// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

#include <twi.h>
#include "Attachment\RTC_DS1307.h"
    
void ConfigLCD(void);
void DisplayMainPage(void);
void ConfigTWI(void);

void main(void){
    //ACSR=0x80; 
    //SFIOR=0x00; 

    ConfigTWI();
    ConfigDS1307();      
    ConfigLCD(); 
    
    //#asm("sei") // Globally enable interrupts

    //rtc_set_time(12,30,00);
    //rtc_set_date(week_day,day,month,year);
    
    while(1){
        GetTimeAndDateFromRTC();
        DisplayMainPage();
        delay_ms(250);
    };
}

//*********************************************
void ConfigTWI(void){
    // TWI initialization
    // Mode: TWI Master
    // Bit Rate: 100 kHz
    twi_master_init(100);
}

//**********************************************
void DisplayMainPage(void){
    char txt1[16];  
    char txt2[16];
    
    sprintf(txt1,"Time: %02u:%02u:%02u",gregorian.hour,gregorian.minute,gregorian.second);
    sprintf(txt2,"Date: %02u/%02u/%02u",gregorian.day,gregorian.month,gregorian.year);  
    
    lcd_clear();
    lcd_gotoxy(0,0); lcd_puts(txt1);  
    lcd_gotoxy(0,1); lcd_puts(txt2); 
    //lcd_gotoxy(0,1); lcd_putsf("RTC with DS1307");
}

//**********************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}




