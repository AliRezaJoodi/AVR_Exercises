// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "aj_bit_reg.h"

void main(void){
    uint8_t input4x_mask = 0;
    uint8_t value = 0;

    AJ_BitReg_SetBit_Position(&DDRD, 0U);

//    AJ_BitReg_SetBit_Position(&PORTD, 0U); delay_ms(500);
//    AJ_BitReg_ClearBit_Position(&PORTD, 0U); delay_ms(500);

//    AJ_BitReg_ToggleBit_Position(&PORTD, 0U); delay_ms(500);
//    AJ_BitReg_ToggleBit_Position(&PORTD, 0U); delay_ms(500);

//    AJ_BitReg_ToggleBits_Mask(&PORTD, 0x01U); delay_ms(500);
//    AJ_BitReg_ToggleBits_Mask(&PORTD, 0x01U); delay_ms(500);

//    AJ_BitReg_SetBits_Mask(&PORTD, 0x01U); delay_ms(500);
//    AJ_BitReg_ClearBits_Mask(&PORTD, 0x01U); delay_ms(500);

//    AJ_BitReg_WriteBit_Position(&PORTD, 0U, 1U); delay_ms(500);
//    AJ_BitReg_WriteBit_Position(&PORTD, 0U, 0U); delay_ms(500);

    AJ_BitReg_SetBits_Mask(&DDRD, 0xF0U);

//    AJ_BitReg_SetBits_Mask(&PORTD, (1U << 6U) | (1U << 7U)); delay_ms(500);
//    AJ_BitReg_ClearBits_Mask(&PORTD, (1U << 6U) | (1U << 7U)); delay_ms(500);

//    AJ_BitReg_Write4Bits_Position(&PORTD, 4U, 6U); delay_ms(500);
//    AJ_BitReg_WriteField_Mask(&PORTD, 0xF0U, 9U); delay_ms(500);

    input4x_mask = (1U << 6) | (1U << 5) | (1U << 4) | (1U << 3);
    AJ_BitReg_ClearBits_Mask(&DDRB, input4x_mask);

    AJ_BitReg_ClearBit_Position(&DDRC, 1U);
    AJ_BitReg_SetBits_Mask(&PORTC, (1U << 1U));

    while(1){
//        PORTD.0 = AJ_BitReg_IsBitSet_Position(&PINC, 1U);
        PORTD.0 = AJ_BitReg_AreBitsSet_Mask(&PINC, (1U << 1U));

        //value = AJ_BitReg_GetField_Mask(&PINB, input4x_mask);
        value = AJ_BitReg_Get4Bits_Position(&PINB, 3U);
        AJ_BitReg_Write4Bits_Position(&PORTD, 4U, value);
    };
}



