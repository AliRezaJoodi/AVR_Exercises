// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>

#include "aj_bit_u8.h"
#include "aj_bit_u16.h"
#include "aj_bit_u32.h"

void Test_u32(void);
void Test_u16(void);
void Test_u8(void);

void main(void){
	DDRA = 0xFFU;
	DDRB = 0xFFU;
	DDRC = 0xFFU;
	DDRD = 0xFFU;

	Test_u16();

	while(1);
}

//******************************************************
void Test_u32(void)
{
	uint32_t value_u32 = 0x80000001UL;

	value_u32 = AJ_BitU32_SetBit_Mask(value_u32, 0x03000030UL);

	while(1)
		{
		//PORTA =  AJ_BitU32_Get8Bit_Position(value_u32, 0U);
		PORTA =  AJ_BitU32_GetField_Position(value_u32, 0U, 8U);
		PORTB =  AJ_BitU32_Get8Bit_Position(value_u32, 8U);
		PORTC =  AJ_BitU32_Get8Bit_Position(value_u32, 16U);
		PORTD =  AJ_BitU32_Get8Bit_Position(value_u32, 24U);
		};
}

//******************************************************
void Test_u16(void)
{
	uint16_t value_u16 = 0x8001U;

	while(1)
		{
		PORTA =  AJ_BitU16_GetField_Position(value_u16, 0U, 8U);
		PORTB =  AJ_BitU16_GetField_Position(value_u16, 8U, 8U);
		};
}

//******************************************************
void Test_u8(void)
{
	uint8_t value_u8 = 0b10110111;

	while(1)
		PORTA =  AJ_BitU8_GetField_Position(value_u8, 1U, 7U);;
}


