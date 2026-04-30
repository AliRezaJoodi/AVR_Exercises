// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

float volt1=0;
float volt2=0;

#include "hardware.h"
#include "drivers/mcp3208.h"

void SPI_Config(void);
void LCD_Config(void);
void LCD_DisplayLoadingPage(void);
void LCD_DisplayMainPage();

void main(void){
    uint16_t in1 = 0;
    uint16_t in2 = 0;

    MCP3208_t mcp1 = {
        .cs = {
            .ddr   = &MCP3208_CS_DDR,
            .port  = &MCP3208_CS_PORT,
            //.index = MCP3208_CS_BIT,
            .mask = MCP3208_CS_MASK
        }
    };

    SPI_Config();
    LCD_Config();
    MCP3208_Init(&mcp1);

    LCD_DisplayLoadingPage();
    delay_ms(500);
    lcd_clear();

    while (1){
        in1 = MCP3208_GetCounts(&mcp1, MCP3208_CH1);
        in2 = MCP3208_GetCounts(&mcp1, MCP3208_CH6CH7);

        volt1 = in1 * 1.2210012f;
        volt2 = in2 * 1.2210012f;
        LCD_DisplayMainPage();
        delay_ms(500);
    }
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[16];
    lcd_gotoxy(0,0); lcd_putsf("In1(mV):"); ftoa(volt1,1,txt); lcd_puts(txt); lcd_putsf("   ");
    lcd_gotoxy(0,1); lcd_putsf("In2(mV):"); ftoa(volt2,1,txt); lcd_puts(txt); lcd_putsf("   ");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();
}

//********************************************************
void LCD_DisplayLoadingPage(void){
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("External ADC");
    lcd_gotoxy(0,1); lcd_putsf("With MCP3208");
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