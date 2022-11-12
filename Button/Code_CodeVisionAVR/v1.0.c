// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

#define BUTTON1 PINB.0
#define BUTTON_INCR BUTTON1
void Config_Inputs(void){
    DDRB.0=0; PORTB.0=1;
}
bit button_incr_status=1;

void Display_Value(void);
void Get_Button(void);

unsigned char value;

void main(void){  
    Config_LCD(); Display_Value();
    Config_Inputs();
   
    while(1){
        Get_Button();
    };
}

//********************************************************
void Get_Button(void){
    if(BUTTON_INCR==0 && button_incr_status==1){
        delay_ms(30);
        if(BUTTON_INCR==0){
            ++value; Display_Value();
            button_incr_status=0;
        } 
    }
    if(BUTTON_INCR==1){button_incr_status=1;}
}

//********************************************************
void Display_Value(void){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt);
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}




