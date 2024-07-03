//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <lcd.h>
#include <delay.h>
///#include <stdio.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include <Display_LCD_BarGraph.h>

void LCD_Config(void);
void LCD_DisplayMainPage(float);

void main(void){
    float value=0;
    
    LCD_Config();
    
    //_BarGraph_Test();
    //value=50; BarGraph_DisplayBarGraph(value);
    
    while(1){ 
        value=value+1; if(value>100){value=0;}
        LCD_DisplayMainPage(value);
        BarGraph_DisplayBarGraph(value);
        delay_ms(100);
    };
}

//******************************************
void LCD_DisplayMainPage(float x){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Value(%):"); ftoa(x,1,txt); lcd_puts(txt); lcd_putsf("  ");  
}

//******************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();  
}

