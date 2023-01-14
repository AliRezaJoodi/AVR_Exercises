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

#include "Attachment\Button.h"

void Display_Value(unsigned char);

void main(void){  
    unsigned char value=0;
    unsigned char old_value=0;
    
    Config_LCD(); Display_Value(value);
   
    while(1){ 
        //GetIncr_Button(&value);
        //GetIncr2_Button(&value);   
        GetIncr3_Button(&value);
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




