// GitHub Account:  GitHub.com/AliRezaJoodi

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

#pragma used+

//********************************************************
void Display_LCD(float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" "); 
    lcd_gotoxy(0,1); lcd_putsf("Average");  
}

#pragma used-
