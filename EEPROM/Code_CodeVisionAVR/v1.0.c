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

#define Key_up PINB.1
#define Key_down PINB.0

void Config_LCD(void);
void Display_Value(void);
void EEPROM_Load(void);
void EEPROM_Save(void);

unsigned char i;
eeprom unsigned char i_eeprom; 

void main(void){
    DDRB.1=0; PORTB.1=1;
    DDRB.0=0; PORTB.0=1;
    Config_LCD();
    
    EEPROM_Load();
    Display_Value();
    
    while (1){
        if (Key_up==0){
            i=i+1;
            EEPROM_Save();
            Display_Value();
            delay_ms(200);
        }
        if (Key_down==0){
            i=i-1;
            EEPROM_Save();
            Display_Value();
            delay_ms(200);
        }
    };
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Display_Value(void){
    char buffer[16];
    lcd_clear();
    itoa(i,buffer);
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(buffer);
    lcd_gotoxy(0,1); lcd_putsf("Internal EEPROM");
}

//********************************************************
void EEPROM_Load(void){
    i=i_eeprom; delay_ms(10);
}

//********************************************************
void EEPROM_Save(void){
    i_eeprom=i; delay_ms(10);
}




