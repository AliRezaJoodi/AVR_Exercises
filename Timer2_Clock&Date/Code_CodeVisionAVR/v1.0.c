//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

unsigned char second,minute,hour;

// Timer 2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    ++second;
    if(second>59){
        second=0; ++minute; 
        if(minute>59){
            minute=0; ++hour; 
            if(hour>99){hour=0;}
        }
    }       
}

void Configuration_LCD(void);
void Config_Timer2(void);
void Display_Clock(void);

void main(void){
    unsigned char second_old=0;
    
    Configuration_LCD();
    Display_Clock();
    Config_Timer2();
    #asm("sei") // Global enable interrupts 
         
    while(1){
        if (second != second_old){
            Display_Clock();
            second_old = second;
        }      
    };
}

//******************************************
void Display_Clock(void){
    char txt[16];
    sprintf(txt,"%02u:%02u:%02u",hour,minute,second);
    strncatf(txt,"                    ",16-strlen(txt)); 
    lcd_gotoxy(0,0); lcd_puts(txt); 
    lcd_gotoxy(0,1); lcd_putsf("Timer2(Async)");  
}

//**************************************
void Config_Timer2(void){
    // Timer/Counter 2 initialization
    // Clock source: TOSC1 pin
    // Clock value: PCK2/128
    // Mode: Normal top=FFh
    // OC2 output: Disconnected
    ASSR=0x08;
    TCCR2=0x05;
    TCNT2=0x00;
    OCR2=0x00;
    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=0x40;
}

//********************************************************
void Configuration_LCD(void){
    lcd_init(16); lcd_clear();   
}
