// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <alcd.h>
///#include <spi.h>
///#include <stdio.h>
#include <stdlib.h>

#include <Attachment\MCP48xx.h>

void Config_LCD(void);
void Display_Loading(void); 
void Display_Values();

float ch0_volt=1.234;
float ch1_volt=3.543;
        
void main(void){
    Config_LCD();
    Display_Loading();
    Config_MCP48xx();
    lcd_clear();
    
    Set_MCP4822(ch0_volt,0);
    Set_MCP4822(ch1_volt,1);
    Display_Values(); 
    //ShutDown_MCP48xx(1);
    
    while (1){
    }
}

//********************************************************
void Display_Values(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("DAC with MCP4822"); 
    lcd_gotoxy(0,1); lcd_putsf("A:"); ftoa(ch0_volt,2,txt); lcd_puts(txt); lcd_putsf("V"); lcd_putsf(" ");
    lcd_gotoxy(8,1); lcd_putsf("B:"); ftoa(ch1_volt,2,txt); lcd_puts(txt); lcd_putsf("V"); lcd_putsf(" ");
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
