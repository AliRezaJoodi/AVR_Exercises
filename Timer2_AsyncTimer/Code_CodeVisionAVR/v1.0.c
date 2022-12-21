//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

unsigned char value=0;

// Timer 2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    ++value;      
}

void Configuration_LCD(void);
void Display_Value(char);
void Config_Timer2(void);

void main(void){
    unsigned char status=0;
    
    Configuration_LCD();
    Display_Value(value);
    Config_Timer2();
    #asm("sei") // Global enable interrupts 
         
    while(1){
        if (value != status){
            Display_Value(value); 
            status = value;
        }      
    };
}

//**********************************
void Display_Value(char x){
    char txt[16]; 
    //lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("i="); itoa(x,txt); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Timer2 (Async)");    
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
