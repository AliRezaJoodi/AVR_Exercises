//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

void LCD_Config(void);
void LCD_DisplayLoadingPage(void);
void LCD_DisplayMainPage(void);

void main(void){

    LCD_Config();
    LCD_DisplayLoadingPage();
    delay_ms(500); lcd_clear(); 
    LCD_DisplayMainPage();
    
    while(1){
    };
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void LCD_DisplayLoadingPage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
}

//********************************************************
void LCD_DisplayMainPage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("GitHub.com");
    lcd_gotoxy(0,1); lcd_putsf("AliRezaJoodi");
}
