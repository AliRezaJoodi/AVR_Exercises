// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>
//#include <stdio.h>
//#include <stdlib.h>

#include <utility_bit.h>
#include "hardware.h"
#include <tm1637.h>

void main(void){
    char txt[];
    uint8_t seg1[6] = {0x5B, 0x3F, 0x66, 0x6D, 0x4F, 0x07};
    uint8_t seg2[6] = {0x7D, 0x06, 0x40, 0x3E, 0x79, 0x5E};

//    uint8_t key[2] = {
//        0b00000000,   
//        0b00000000,
//    };
    
    TM1637_t tm1;
    TM1637_t tm2;
      
    tm1.clk.ddr     = &TM1637_TM1_CLK_DDR;
    tm1.clk.port    = &TM1637_TM1_CLK_PORT;
    tm1.clk.pin     = &TM1637_TM1_CLK_PIN;
    tm1.clk.index   =  TM1637_TM1_CLK_BIT;

    tm1.dio.ddr     = &TM1637_TM1_DIO_DDR;
    tm1.dio.port    = &TM1637_TM1_DIO_PORT;
    tm1.dio.pin     = &TM1637_TM1_DIO_PIN;
    tm1.dio.index   =  TM1637_TM1_DIO_BIT;
        
    tm2.clk.ddr     = &TM2637_TM2_CLK_DDR;
    tm2.clk.port    = &TM2637_TM2_CLK_PORT;
    tm2.clk.pin     = &TM2637_TM2_CLK_PIN;
    tm2.clk.index   =  TM2637_TM2_CLK_BIT;

    tm2.dio.ddr     = &TM2637_TM2_DIO_DDR;
    tm2.dio.port    = &TM2637_TM2_DIO_PORT;
    tm2.dio.pin     = &TM2637_TM2_DIO_PIN;
    tm2.dio.index   =  TM2637_TM2_DIO_BIT;    
                    
    TM1637_Config(&tm1);
    TM1637_Config(&tm2);

//    sprintf(txt, "0x%02X\r", key[0]); puts(txt);
            
    TM1637_SetSegments(&tm1, seg1, 6, 0);
    TM1637_SetSegments(&tm2, seg2, 6, 0);
    delay_ms(1000);  
     
    TM1637_SetSegments_FixedAddress(&tm1, seg1[5], 2); delay_ms(1000);
    TM1637_ResetSegments(&tm1); delay_ms(1000);
    TM1637_SetSegments_FixedAddress(&tm1, seg1[2], 5); delay_ms(1000);    
    TM1637_SendCommand(&tm1, 0b10000111); delay_ms(1000); //Turn off the display 
    TM1637_SetDisplay(&tm1, 1, 7); delay_ms(1000);
    
    TM1637_ResetSegments(&tm2);
    TM1637_SetSegments_4Digits(&tm2, seg1); delay_ms(1000);
    
    while(1){ 
//        sprintf(txt, "0x%02X\r", key[0]); puts(txt);
        TM1637_SetSegments(&tm1, seg1, 6, 0); delay_ms(500);
        TM1637_SetSegments(&tm2, seg2, 6, 0); delay_ms(500);  
        TM1637_ResetSegments(&tm1); 
        TM1637_ResetSegments(&tm2);
        delay_ms(500);                            
    };
}
