// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
//#include <stdio.h>
//#include <stdlib.h>

#include "hardware.h"
#include "utils/bit.h"
#include "drivers/tm1637.h"

void main(void){
    //char txt[];
    uint8_t seg1[6] ={
        0x3F,   // 0
        0x06,   // 1
        0x5B,   // 2
        0x4F,   // 3
        0x66,   // 4
        0x6D    // 5
    };

    uint8_t seg2[6] = {0x7D, 0x06, 0x40, 0x3E, 0x79, 0x5E};

//    uint8_t key[2] = {
//        0b00000000,
//        0b00000000,
//    };

    TM1637_t tm1 = {
        .clk = {
            .ddr   = &TM1637_CLK_DDR,
            .port  = &TM1637_CLK_PORT,
            .pin   = &TM1637_CLK_PIN,
            .index =  TM1637_CLK_BIT
        },
        .dio = {
            .ddr   = &TM1637_DIO_DDR,
            .port  = &TM1637_DIO_PORT,
            .pin   = &TM1637_DIO_PIN,
            .index =  TM1637_DIO_BIT
        }
    };

    TM1637_t tm2 = {
        .clk = {
            .ddr   = &TM1637_CLK2_DDR,
            .port  = &TM1637_CLK2_PORT,
            .pin   = &TM1637_CLK2_PIN,
            .index =  TM1637_CLK2_BIT
        },
        .dio = {
            .ddr   = &TM1637_DIO2_DDR,
            .port  = &TM1637_DIO2_PORT,
            .pin   = &TM1637_DIO2_PIN,
            .index =  TM1637_DIO2_BIT
        }
    };

    TM1637_Init(&tm1);
    TM1637_Init(&tm2);

    TM1637_WriteDisplayRegister_AutoIncr(&tm1, seg1, 6, 0);
    TM1637_WriteDisplayRegister_AutoIncr(&tm2, seg2, 6, 0);
    delay_ms(1000);

    TM1637_WriteDisplayRegister_Fixed(&tm1, seg1[5], 2); delay_ms(1000);
    TM1637_ClearDisplay(&tm1); delay_ms(1000);
    TM1637_WriteDisplayRegister_Fixed(&tm1, seg1[2], 5); delay_ms(1000);
    TM1637_SendCommand(&tm1, 0b10000111); delay_ms(1000); //Turn off the display
    TM1637_SetDisplay(&tm1, 1, 7); delay_ms(1000);

    TM1637_ClearDisplay(&tm2);
    TM1637_Write2Digits_G1G2(&tm2, seg1); delay_ms(1000); TM1637_ClearDisplay(&tm2); delay_ms(500);
    TM1637_Write3Digits_G1G3(&tm2, seg1); delay_ms(1000); TM1637_ClearDisplay(&tm2); delay_ms(500);
    TM1637_Write3Digits_G4G6(&tm2, seg1); delay_ms(1000); TM1637_ClearDisplay(&tm2); delay_ms(500);
    TM1637_Write4Digits_G1G4(&tm2, seg1); delay_ms(1000); TM1637_ClearDisplay(&tm2); delay_ms(500);
    TM1637_Write6Digits_G1G6(&tm2, seg1); delay_ms(1000); TM1637_ClearDisplay(&tm2); delay_ms(500);

    while(1){
//        sprintf(txt, "0x%02X\r", key[0]); puts(txt);
        TM1637_WriteDisplayRegister_AutoIncr(&tm1, seg1, 6, 0); delay_ms(500);
        TM1637_WriteDisplayRegister_AutoIncr(&tm2, seg2, 6, 0); delay_ms(500);
        TM1637_ClearDisplay(&tm1);
        TM1637_ClearDisplay(&tm2);
        delay_ms(500);
    };
}
