// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdint.h>

#include <tm1637.h>

void main(void){
    uint8_t seg1[6] = {0x5B, 0x3F, 0x66, 0x6D, 0x4F, 0x07};
    uint8_t seg2[6] = {0x7D, 0x06, 0x40, 0x3E, 0x79, 0x5E};

    TM1637_t tm1;
    TM1637_t tm2;
      
    tm1.clk.ddr  = &DDRC;
    tm1.clk.port = &PORTC;
    tm1.clk.pin  = &PINC;
    tm1.clk.index  = 0;

    tm1.dio.ddr  = &DDRC;
    tm1.dio.port = &PORTC;
    tm1.dio.pin  = &PINC;
    tm1.dio.index  = 1;
        
    tm2.clk.ddr  = &DDRD;
    tm2.clk.port = &PORTD;
    tm2.clk.pin  = &PIND;
    tm2.clk.index  = 2;

    tm2.dio.ddr  = &DDRD;
    tm2.dio.port = &PORTD;
    tm2.dio.pin  = &PIND;
    tm2.dio.index  = 3;    
                    
    TM1637_Config(&tm1);
    TM1637_Config(&tm2);
        
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
                                 
    };
}
