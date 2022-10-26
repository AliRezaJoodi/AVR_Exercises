//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <lcd.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

void Configuration_LCD(void);
void Display_loading(void);
void Display_Advertising(void);
void test1(void);

void main(void){

    Configuration_LCD();
    Display_loading(); 
    Display_Advertising();
    
    test1(); 
    
    while(1){
    };
}

//********************************************************
void test1(void){
    char buffer[16];
    int i = 10;
    float f = 21.3256;
    
    sprintf(buffer, "i=%d f=%1.2f", i, f); 
    lcd_gotoxy(0,0); lcd_puts(buffer);
}

//********************************************************
void Configuration_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Display_loading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
    delay_ms(500); lcd_clear();
}

//********************************************************
void Display_Advertising(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("GitHub.com");
    lcd_gotoxy(0,1); lcd_putsf("AliRezaJoodi");
    delay_ms(500); lcd_clear();
}
