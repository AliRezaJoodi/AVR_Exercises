// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

#include <twi.h>
void ConfigTWI(void); 
#include "Attachment\RTC_DS1307.h"
#include <converter_calendar.h>

#include <alcd.h>   
void ConfigLCD(void);
void DisplayMainPage(void);

void main(void){
    //ACSR=0x80; 
    //SFIOR=0x00; 
    
    ConfigTWI();
    ConfigDS1307();      
    ConfigLCD(); 
    
    //#asm("sei") // Globally enable interrupts
    
    while(1){
        GetDateFromRTC(); 
        //gregorian.year=23; gregorian.month=03; gregorian.day=21; 
        jalaali=ConvertGregorianToJalaali(gregorian);
        //jalaali.year=02; jalaali.month=07; jalaali.day=01;
        gregorian=ConvertJalaaliToGregorian(jalaali); 
        DisplayMainPage();
        delay_ms(250);
    };
}

//**********************************************
void DisplayMainPage(void){
    char txt1[16];  
    char txt2[16];
    
    //sprintf(txt1,"Time: %02u:%02u:%02u",gregorian.hour,gregorian.minute,gregorian.second);
    sprintf(txt1,"G:20%02u/%02u/%02u",gregorian.year,gregorian.month,gregorian.day);
    sprintf(txt2,"J:14%02u/%02u/%02u",jalaali.year,jalaali.month,jalaali.day);  
    
    lcd_clear();
    lcd_gotoxy(0,0); lcd_puts(txt1);  
    lcd_gotoxy(0,1); lcd_puts(txt2); 
    //lcd_gotoxy(0,1); lcd_putsf("Jalaali Calendar");
}

//*********************************************
void ConfigTWI(void){
    // TWI initialization
    // Mode: TWI Master
    // Bit Rate: 100 kHz
    twi_master_init(100);
}

//**********************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}




