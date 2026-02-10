// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdlib.h>
#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include <mcp3201.h>

float In1 = 0;
float In2 = 0;

void SPI_Config(void);
void LCD_Config(void);
void LCD_DisplayMainPage(void);
        
void main(void){
    MCP3201_t mcp1; 
    MCP3201_t mcp2;
    
    mcp1.cs.ddr     = &MCP3201_CS1_DDR;
    mcp1.cs.port    = &MCP3201_CS1_PORT;
    mcp1.cs.index   =  MCP3201_CS1_BIT;

    mcp2.cs.ddr     = &MCP3201_CS2_DDR;
    mcp2.cs.port    = &MCP3201_CS2_PORT;
    mcp2.cs.index   =  MCP3201_CS2_BIT;
        
    SPI_Config();
    LCD_Config();
    MCP3201_Init(&mcp1);
    MCP3201_Init(&mcp2);
    
    while (1){ 
        In1 = MCP3201_GetMilliVolt(&mcp1);
        In2 = MCP3201_GetMilliVolt(&mcp2);
        
        LCD_DisplayMainPage();
        delay_ms(500);
    }
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[5]; 
    
    lcd_gotoxy(0, 0);
    lcd_putsf("In1(mV):");
    itoa(In1, txt);
    lcd_puts(txt);
    lcd_putsf("   ");
    
    lcd_gotoxy(0, 1);
    lcd_putsf("In2(mV):");
    itoa(In2, txt);
    lcd_puts(txt);
    lcd_putsf("   ");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();   
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