// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _AVERAGE_STATIC_INCLUDED
#define _AVERAGE_STATIC_INCLUDED


#include <stdint.h>

#include "hardware.h"

#ifndef AVERAGE_STATIC_HARDWARE
#define AVERAGE_STATIC_HARDWARE
    #warning "AVERAGE_STATIC_HARDWARE is not defined; default configuration will be used."    
    #define AVERAGE_STATIC_COUNT    10     
#endif

uint16_t Average_BlockUpdate_u16(uint16_t);
uint16_t Average_MovingWithCircularBuffer_u16(uint16_t);

float Average_BlockUpdate_f32(float);
float Average_MovingWithCircularBuffer_f32(float);
float Average_MovingWithShift_f32(float);   // Not recommended due to high clock consumption.


#pragma library average_static.lib    
#endif
