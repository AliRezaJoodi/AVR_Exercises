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

#define BUTTON1_DDR DDRB.0
#define BUTTON1_PORT PORTB.0
#define BUTTON1_PIN PINB.0
#define BUTTON_INCR BUTTON1_PIN

#define PRESS_BUTTON 0
#define DEFAULT_BUTTON !PRESS_BUTTON

void Config_IO(void){
    #define INPUT 0   
    #define OUTPUT !INPUT
    #define PULL_UP 1
    #define PULL_DOWN !PULL_UP
    
    BUTTON1_DDR=INPUT; BUTTON1_PORT=PULL_UP;
}

void Display_Value(void);
void Get_Button(void);

unsigned char value;

void main(void){  
    Config_LCD(); Display_Value();
    Config_IO();
   
    while(1){
        Get_Button();
    };
}

//********************************************************
void Get_Button(void){
    bit status_button1=1;
    if(BUTTON_INCR==PRESS_BUTTON && status_button1==DEFAULT_BUTTON){
        delay_ms(30);
        if(BUTTON_INCR==PRESS_BUTTON){
            ++value; Display_Value();
            status_button1=PRESS_BUTTON;
        } 
    }
    if(BUTTON_INCR==DEFAULT_BUTTON){status_button1=DEFAULT_BUTTON;}
}

//********************************************************
void Display_Value(void){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt);
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}




