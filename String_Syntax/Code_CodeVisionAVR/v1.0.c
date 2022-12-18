//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <lcd.h>
#include <delay.h>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

void Config_LCD(void);
void Display_loading(void);
void test1(void);
void Display_Clock(void);

void main(void){
    Config_LCD();
    Display_loading(); 
    
    test1(); 
    Display_Clock();
    
    while(1){
    };
}

//******************************************
void Display_Clock(void){
    char txt[16];
    unsigned char hour=9,minute=1,second=10; 
    
    sprintf(txt,"%02u:%02u:%02u",hour,minute,second);
    strncatf(txt,"                    ",16-strlen(txt)); 
    lcd_gotoxy(0,1); lcd_puts(txt);  
}

//********************************************************
void test1(void){
    char txt[16];
    int i=10;
    float f=21.3256;
    
    sprintf(txt, "i=%d f=%0.2f", i, f); lcd_gotoxy(0,0); lcd_puts(txt);
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Display_loading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
    delay_ms(500); lcd_clear();
}
