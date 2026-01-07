// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _CHANGED_STATIC_INCLUDED
#define _CHANGED_STATIC_INCLUDED

#include <stdint.h>

#pragma used+
uint8_t Changed_Exact_u16(uint16_t value);
uint8_t Changed_Threshold_u16(uint16_t value, uint16_t threshold);
uint8_t Changed_Threshold_f32(float value, float threshold);
#pragma used-

#pragma library changed_static.lib
    
#endif
