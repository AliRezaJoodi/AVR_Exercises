// GitHub Account:  GitHub.com/AliRezaJoodi

// System Clock:    16MHz
// Timer1 Mode:     Fast PWM
// PWM Resolution:  10 Bits
// A Channel:       OC1A, PIND.5 
// B Channel:       OC1B, PIND.4
// Output Type:     RC, Low Pass Filter 

#include <io.h>  
#include <stdint.h>

#ifndef _TIMER1_DAC_INCLUDED
#define _TIMER1_DAC_INCLUDED


#ifndef _TIMER1_DAC_HARDWARE
#define _TIMER1_DAC_HARDWARE 
    #define _TIMER1_DAC_MAXVOLT     5000    // mV
#endif

#define Timer1_DAC_ClearOutput_ChA          OCR1A = 0;
#define Timer1_DAC_ClearOutput_ChB          OCR1B = 0 ;
#define Timer1_DAC_ClearOutput_ALL          OCR1A = 0; OCR1B = 0;
#define Timer1_DAC_ClearOutput(CH)          ((CH) == 0 ? (OCR1A = 0) : (OCR1B = 0))

void Timer1_DAC_Config(void);

#pragma used+
void Timer1_DAC_SetVoltage_ChA (uint16_t mv);           // OC1A
void Timer1_DAC_SetVoltage_ChB (uint16_t mv);           // OC1B
void Timer1_DAC_SetVoltage (uint16_t mv, uint8_t ch);   // 1: OC1A, 2: OC1B
#pragma used-


#pragma library timer1_dac_16mhz10bit2ch.lib

#endif
