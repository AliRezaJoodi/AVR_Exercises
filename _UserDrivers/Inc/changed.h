// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _CHANGED_INCLUDED
#define _CHANGED_INCLUDED


#include <stdint.h>

uint8_t Changed_Exact_u16(uint16_t value, uint16_t *value_last);
uint8_t Changed_Threshold_u16(uint16_t value, uint16_t *value_last, uint16_t threshold);
uint8_t Changed_Threshold_f32(float value, float *value_last, float threshold);


#pragma library changed.lib    
#endif
