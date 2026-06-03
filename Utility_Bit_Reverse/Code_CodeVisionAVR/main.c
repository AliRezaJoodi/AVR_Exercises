// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>

#include "aj_bit_reverse.h"

void Test_u32(void);
void Test_u16(void);
void Test_u8(void);

void main(void){
    DDRA = 0xFFU;
    DDRB = 0xFFU;
    DDRC = 0xFFU;
    DDRD = 0xFFU;

    Test_u32();

    while(1){
    };
}

//***********************************************
void Test_u32(void){
    uint32_t value_u32 = 0x00000031UL;

    value_u32 = AJ_Bit_Reverse_u32(value_u32);

    while(1){
        PORTA = (uint8_t)((value_u32 >> 0U)  & 0xFFU);
        PORTB = (uint8_t)((value_u32 >> 8U)  & 0xFFU);
        PORTC = (uint8_t)((value_u32 >> 16U) & 0xFFU);
        PORTD = (uint8_t)((value_u32 >> 24U) & 0xFFU);
    };
}

//***********************************************
void Test_u16(void){
    uint16_t value_u16 = 0x0031U;

    value_u16 = AJ_Bit_Reverse_u16(value_u16);

    while(1){
        PORTA = (uint8_t)((value_u16 >> 0U) & 0xFFU);
        PORTB = (uint8_t)((value_u16 >> 8U) & 0xFFU);
    };
}

//***********************************************
void Test_u8(void){
    uint8_t value_u8 = 0x31U;

    value_u8 = AJ_Bit_Reverse_u8(value_u8);

    while(1){
        PORTA = value_u8;
    };
}


