// GitHub Account: GitHub.com/AliRezaJoodi

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

#include "Attachment\Button.h"

void Display_Value(unsigned char);

void main(void){  
    unsigned char value=100;
    unsigned char old_value=0;
    
    ConfigButtons();
    Config_LCD(); Display_Value(value);
   
    while(1){ 
        if(CheckIncrButton_OneStep()){++value;}
        if(CheckIncrButton_Continuously()){++value;}   
        if(CheckSetButton()){value=0;}
        
        if(old_value!=value){Display_Value(value); old_value=value;}
    };
}

//********************************************************
void Display_Value(unsigned char value){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}




