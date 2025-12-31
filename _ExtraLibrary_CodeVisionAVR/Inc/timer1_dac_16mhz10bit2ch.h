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

void Timer1_DAC_Config(void);

#pragma used+

void Timer1_DAC_SetVoltage_ChA (uint16_t mv);
void Timer1_DAC_SetVoltage_ChB (uint16_t mv);

#pragma used-

#pragma library timer1_dac_16mhz10bit2ch.lib

#endif
