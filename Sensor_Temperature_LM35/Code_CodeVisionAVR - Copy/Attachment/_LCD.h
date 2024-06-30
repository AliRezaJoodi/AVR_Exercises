// GitHub Account:  GitHub.com/AliRezaJoodi

#include <alcd.h>

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

#pragma used+

//********************************************************
void Display_LCD(float mv,float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Input:"); ftoa(mv,1,txt); lcd_puts(txt); lcd_putsf(" mV"); lcd_putsf(" ");
    lcd_gotoxy(0,1); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" ");   
}

//********************************************************
void Display2_LCD(float temp){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Temp:"); ftoa(temp,1,txt); lcd_puts(txt); lcd_putchar(0); lcd_putsf(" "); 
    lcd_gotoxy(0,1); lcd_putsf("LM35 Sensor");  
}

#pragma used-
