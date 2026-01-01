// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>

#ifndef _AVERAGE_STATIC_INCLUDED
#define _AVERAGE_STATIC_INCLUDED
    
#ifndef AVERAGE_HARDWARE
#define AVERAGE_HARDWARE 
    #define AVERAGE_COUNT     10 
#endif

#pragma used+
uint16_t Average_BlockUpdate_uint16(uint16_t);  // AVERAGE_COUNT will be 1~64 for input from 0~1023 
float Average_BlockUpdate_float(float);
float Average_MovingWithCircularBuffer_float(float);
float Average_MovingWithShift_float(float);
#pragma used-

#pragma library average_static.lib
    
#endif
