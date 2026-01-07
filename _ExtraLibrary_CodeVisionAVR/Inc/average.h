// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _AVERAGE_INCLUDED
#define _AVERAGE_INCLUDED

#include <stdint.h>
   
#define AVERAGE_COUNT     10 

#pragma used+
typedef struct {
    uint32_t sum;
    uint8_t i;
    uint16_t average;
} AverageBlock_u16_t;

typedef struct {
    uint16_t buf[AVERAGE_COUNT];
    uint8_t  i;
    uint32_t sum;
    uint8_t  count;
} AverageMoving_u16_t;

uint16_t Average_BlockUpdate_u16(uint16_t value, AverageBlock_u16_t *avgBlock);
uint16_t Average_MovingWithCircularBuffer_u16(uint16_t value, AverageMoving_u16_t *avgMoving);
#pragma used-

#pragma library average.lib
    
#endif
