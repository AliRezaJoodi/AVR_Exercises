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

#include <Attachment\BarGraph.h>

void Config_LCD(void);
void Display_MainPage(float);

void main(void){
    float value=0;
    
    Config_LCD();
    
    Test_BarGraph();
    //value=50; Display_BarGraph(value);
    
    while(1){
        Display_MainPage(value);
        Display_BarGraph(value);
        delay_ms(100);
        value=value+1; if(value>100){value=0;}
    };
}

//******************************************
void Display_MainPage(float x){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Value(%):"); ftoa(x,1,txt); lcd_puts(txt); lcd_putsf("  ");  
}

//******************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();  
}

