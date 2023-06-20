// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <twi.h>
#include <ds1307_twi.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char day=20;
unsigned char month=01;
unsigned char year=23;
unsigned char week_day=0;
unsigned char hour=10;
unsigned char minute=20;
unsigned char second=30;
    
void ConfigLCD(void);
void DisplayMainPage(void);
void ConfigI2C(void);
void ConfigDS1307(void);

void main(void){
    //ACSR=0x80; 
    //SFIOR=0x00; 

    ConfigI2C();
    ConfigDS1307();      
    ConfigLCD(); 
    
    //#asm("sei") // Globally enable interrupts

    //rtc_set_time(12,30,00);
    //rtc_set_date(week_day,day,month,year);
    
    while(1){
        rtc_get_time(&hour,&minute,&second);
        rtc_get_date(&week_day,&day,&month,&year);
         
        DisplayMainPage();
        delay_ms(250);
    };
}

//**********************************************
void DisplayMainPage(void){
    char txt1[16];  
    char txt2[16];
    
    sprintf(txt1,"Time: %02u:%02u:%02u",hour,minute,second);
    sprintf(txt2,"Date: %02u/%02u/%02u",day,month,year);  
    
    lcd_clear();
    lcd_gotoxy(0,0); lcd_puts(txt1);  
    lcd_gotoxy(0,1); lcd_puts(txt2); 
    //lcd_gotoxy(0,1); lcd_putsf("RTC with DS1307");
}

//*********************************************
void ConfigI2C(void){
    // TWI initialization
    // Mode: TWI Master
    // Bit Rate: 100 kHz
    twi_master_init(100);
}

//*********************************************
void ConfigDS1307(void){
    #define _1HZ                0
    #define _4K096HZ            1
    #define _8K192HZ            2
    #define _32K768HZ           3
    #define _ENABLE             1

    #define OUT_DS1307          0 
    #define SQWE_DS1307         _ENABLE
    #define FREQUENCY_DS1307    _1HZ
    
    rtc_init(FREQUENCY_DS1307,SQWE_DS1307,OUT_DS1307); 
}

//**********************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}



