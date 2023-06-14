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

#define UP_BUTTON   PINB.1
#define DOWN_BUTTON PINB.0

char i=0;

#include "Attachment\_EEPROM.h"
void ConfigLCD(void);
void DisplayValue(void);
char CheckNewChange(char value);

void main(void){
    DDRB.1=0; PORTB.1=1;
    DDRB.0=0; PORTB.0=1;
    ConfigLCD();
    
    ValidateEEPROM();
    //SetDefaultValuesInEEPROM();
    LoadValuesOfEEPROM();
    
    DisplayValue();
    
    while (1){
        if(UP_BUTTON==0){
            i=i+1;
            delay_ms(250);
        }
        if(DOWN_BUTTON==0){
            i=i-1;
            delay_ms(250);
        }
        
        if(CheckNewChange(i)){
            DisplayValue();
            SaveNewChangesInEEPROM(); 
        }
    };
}

//******************************
char CheckNewChange(char value){
    static char value_old=0;  
    
    if(value!=value_old){value_old=value; return 1;}
        else {return 0;}
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void DisplayValue(void){
    char txt[16];
    lcd_clear();
    itoa(i,txt);
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt);
    lcd_gotoxy(0,1); lcd_putsf("Internal EEPROM");
}




