// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
//#include <stdlib.h>

#include <i2c.h>
#include "Attachment\RTC_DS1307.h"
char task_1s=0;

void ConfigINT2(void);     
void ConfigLCD(void);
void DisplayMainPage(void);
void ConfigI2C(void);

// External Interrupt 2 service routine
interrupt [EXT_INT2] void ext_int2_isr(void){
    task_1s=1;
}

void main(void){
    //ACSR=0x80; 
    //SFIOR=0x00; 

    ConfigI2C();
    ConfigDS1307();      
    ConfigLCD(); 
    ConfigINT2();
    //#asm("sei") // Globally enable interrupts
    
    //rtc_set_time(12,30,00);
    //rtc_set_date(week_day,day,month,year);
    //DisableOscillatorOfDS1307();
    //EnableOscillatorOfDS1307(); 
    //SetHourFormatTo24();
    //DisableSquareWaveOfDS1307();
    //EnableSquareWaveOfDS1307();
    
    while(1){
        if(task_1s){
            task_1s=0;
            GetClockFromDS1307(); 
            GetCalendarFromDS1307();
            DisplayMainPage();
        }
    };
}

//*********************************************
void ConfigINT2(void){
    DDRB.2=0; PORTB.2=1;
      
// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: On
// INT2 Mode: Falling Edge
GICR|=(0<<INT1) | (0<<INT0) | (1<<INT2);
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(0<<INTF1) | (0<<INTF0) | (1<<INTF2);

    #asm("sei") // Globally enable interrupts
}

//*********************************************
void ConfigI2C(void){
    i2c_init(); // I2C Bus initialization
}

//**********************************************
void DisplayMainPage(void){
    char txt[16];  
    lcd_clear();
    sprintf(txt,"Time:%02u:%02u:%02u",gregorian.hour,gregorian.minute,gregorian.second); lcd_gotoxy(0,0); lcd_puts(txt);
    sprintf(txt,"Date:%02u-%02u-%02u",gregorian.day,gregorian.month,gregorian.year); lcd_gotoxy(0,1); lcd_puts(txt);   
}

//**********************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}


