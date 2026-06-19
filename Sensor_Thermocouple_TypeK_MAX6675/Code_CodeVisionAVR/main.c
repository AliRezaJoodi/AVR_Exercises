// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <mega32a.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "aj_max6675.h"

#define MAX6675_CS  PORTB.4

uint16_t raw;
float temperature;

void SPI_Config(void);
void LCD_Config(void);
void LCD_DisplayMainPage(void);
//uint16_t MAX6675_ReadRaw(void);

void main(void){
    static const aj_max6675_t max = {
        .cs = {
            .ddr  = &AJ_MAX6675_CS_DDR,
            .port = &AJ_MAX6675_CS_PORT,
            .mask = AJ_MAX6675_CS_MASK
        }
    };

    SPI_Config();
    LCD_Config();
    AJ_MAX6675_Init(&max);
//    DDRA = 0XFF; DDRC = 0XFF;

    while (1){
        //In1 = MAX6675_ReadRaw();
        raw = AJ_MAX6675_ReadRaw(&max);
        temperature = raw * 0.25;
        LCD_DisplayMainPage();
        delay_ms(500);
    }
}

////*********************************************
//uint16_t MAX6675_ReadRaw(void){
//    uint8_t high_byte;
//    uint8_t low_byte;
//    uint16_t data = 0;
//
//    MAX6675_CS = 0;
//    delay_us(1);
//
//    high_byte = spi(0x00);
//    low_byte  = spi(0x00);
//
//    delay_us(1);
//    MAX6675_CS = 1;
//
//    PORTA = low_byte; PORTC = high_byte;
//    data = ((uint16_t)high_byte << 8) | low_byte;
//
//    if(data & 0x04){
//        return 0x00U;
//    }
//
//    return data >> 3;
//}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[20];

    lcd_gotoxy(0, 0);
    lcd_putsf("Raw:");
    itoa(raw, txt);
    lcd_puts(txt);
    lcd_putsf("   ");

    ftoa(temperature, 2, txt);
    lcd_gotoxy(0,1);
    lcd_putsf("Temp:");
    lcd_puts(txt);
    lcd_putsf("   ");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();
}


//********************************************************  Mode1
void SPI_Config(void){
    DDRB.4 = 1; PORTB.4 = 1;    // SS/CS output, inactive High
    DDRB.5 = 1; PORTB.5 = 0;    // MOSI output
    DDRB.6 = 0; PORTB.6 = 0;    // MISO input, pull-up disabled
    DDRB.7 = 1; PORTB.7 = 0;    // SCK output, idle Low for Mode 0

    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 125.000 kHz
    // SPI Clock Phase: Cycle Half
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (1<<CPHA) | (1<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);
}