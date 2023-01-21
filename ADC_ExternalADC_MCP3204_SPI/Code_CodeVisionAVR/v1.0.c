// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <alcd.h>
///#include <spi.h>
///#include <stdio.h>
#include <stdlib.h>

#include <Attachment\MCP320x.h>
void Config_LCD(void);
void Display_Loading(void); 
void Display_Values();

float ch0_volt=0;
float ch1_volt=0;
//float ch2_volt=0;
//float ch3_volt=0;
        
void main(void){
    Config_LCD();
    Display_Loading();
    Config_MCP320x();
    lcd_clear();

    while (1){
        ch0_volt=GetSingle_MCP3204(0); 
        ch1_volt=GetSingle_MCP3204(1);
        Display_Values();
        delay_ms(500);
    }
}

//********************************************************
void Display_Values(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("ADC with MCP3204"); 
    lcd_gotoxy(0,1); lcd_putsf("0:"); ftoa(ch0_volt,2,txt); lcd_puts(txt); lcd_putsf("V"); lcd_putsf(" ");
    lcd_gotoxy(8,1); lcd_putsf("1:"); ftoa(ch1_volt,2,txt); lcd_puts(txt); lcd_putsf("V"); lcd_putsf(" ");
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Display_Loading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
    //delay_ms(250);
    //lcd_clear();  
}
