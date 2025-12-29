// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

float volt1=0;
float volt2=0;

#include "Attachment\hardware_v1.0.h"
#include <adc_mcp3202.h>
 
void SPI_Config(void);
void LCD_Config(void);

#pragma used+
void LCD_DisplayLoadingPage(void); 
void LCD_DisplayMainPage();
#pragma used-
       
void main(void){
    SPI_Config();
    LCD_Config();
    MCP3202_Config();
    
    LCD_DisplayLoadingPage(); delay_ms(500); lcd_clear();

    while (1){ 
        volt1=MCP3202_GetSingleEndedADC(0); 
        volt2=MCP3202_GetDifferentialADC(01);  
        
        LCD_DisplayMainPage();
        delay_ms(500);
    }
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("CH0(mV):"); ftoa(volt1,1,txt); lcd_puts(txt); lcd_putsf(" ");
    lcd_gotoxy(0,1); lcd_putsf("Diff(mV):"); ftoa(volt2,1,txt); lcd_puts(txt); lcd_putsf(" ");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void LCD_DisplayLoadingPage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("External ADC");
    lcd_gotoxy(0,1); lcd_putsf("With MCP3202"); 
}

//********************************************************
void SPI_Config(void){
    DDRB.4=1; PORTB.4=0;    //SS
    DDRB.5=1; PORTB.5=0;    //MOSI
    DDRB.6=0; PORTB.6=0;    //MISO
    DDRB.7=1; PORTB.7=0;    //SCK

// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2000.000 kHz
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First
SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
SPSR=(0<<SPI2X);
}