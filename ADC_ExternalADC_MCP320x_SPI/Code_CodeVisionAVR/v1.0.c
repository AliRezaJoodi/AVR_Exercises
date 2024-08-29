// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

void ConfigSPI(void);
void ConfigLCD(void);
void DisplayLoading(void); 
void DisplayValues();

float volt1=0;
float volt2=0;

#include <ADC_MCP320x.h>
        
void main(void){
    ConfigSPI();
    ConfigLCD();
    MCP320x_Config();
    
    DisplayLoading(); delay_ms(500); lcd_clear();

    while (1){
        volt1=MCP3202_GetSingleADC(0); 
        volt2=MCP3202_GetDifferentialADC(01);  
        
        //volt1=MCP3204_GetSingleADC(0); 
        //volt2=MCP3204_GetDifferentialADC(32);
        
        //volt1=MCP3208_GetSingleADC(0); 
        //volt2=MCP3208_GetDifferentialADC(32);  
        
        DisplayValues();
        delay_ms(500);
    }
}

//********************************************************
void DisplayValues(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("CH0(mV):"); ftoa(volt1,1,txt); lcd_puts(txt); lcd_putsf(" ");
    lcd_gotoxy(0,1); lcd_putsf("Diff(mV):"); ftoa(volt2,1,txt); lcd_puts(txt); lcd_putsf(" ");
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void DisplayLoading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("External ADC");
    lcd_gotoxy(0,1); lcd_putsf("With MCP320x"); 
}

//********************************************************
void ConfigSPI(void){
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