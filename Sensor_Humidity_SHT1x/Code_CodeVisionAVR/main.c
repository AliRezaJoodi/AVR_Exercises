// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
#include <stdio.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port = 0x1b ;PORTA
#endasm
#include <lcd.h>

//#define __SYSTEM_CLOCK__ 2000000

#include "hardware.h"
#include "sht1x.h"

float temperature = 0;
float humidity = 0;
void Display_Values(void);

void main(void){
    const SHT1x_t sht1 = {
        .sck = {
            .ddr   = &SHT1X_SCK_DDR,
            .port  = &SHT1X_SCK_PORT,
            .pin   = &SHT1X_SCK_PIN,
            .index = SHT1X_SCK_BIT
        },
        .data = {
            .ddr   = &SHT1X_DATA_DDR,
            .port  = &SHT1X_DATA_PORT,
            .pin   = &SHT1X_DATA_PIN,
            .index = SHT1X_DATA_BIT
        }
    };

    lcd_init(16);
    lcd_clear();
    SHT1x_Init(&sht1);

    while(1){
        humidity = Get_Humidity(&sht1);
        temperature =  Get_Temp(&sht1);
        Display_Values();
        delay_ms(500);
    }
}

//***********************
void Display_Values(void){
    char txt[16];
    lcd_clear();
    sprintf(txt,"Humidity(%%)=%3.1f",humidity); lcd_gotoxy(0,0); lcd_puts(txt);
    sprintf(txt,"Temp(C)=%3.1f",temperature); lcd_gotoxy(0,1); lcd_puts(txt);
}

