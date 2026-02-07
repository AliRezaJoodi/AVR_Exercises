// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AVERAGE_INCLUDED
#define AVERAGE_INCLUDED


#include <stdint.h>

/**
 * @note Default hardware macros can be overridden by the user.
 */ 
#include "hardware.h"

#ifndef AVERAGE_HARDWARE
#define AVERAGE_HARDWARE    
    #define AVERAGE_COUNT     10
    #warning "AVERAGE_HARDWARE is not defined; default configuration will be used."  
#endif

typedef struct {
    uint32_t sum;
    uint8_t count;
    uint16_t average;
} AverageBlock_u16_t;

typedef struct {
    uint16_t buf[AVERAGE_COUNT];
    uint8_t  index;
    uint32_t sum;
    uint8_t  count;
} AverageMoving_u16_t;

uint16_t Average_BlockUpdate_u16(uint16_t value, AverageBlock_u16_t *avgBlock);
uint16_t Average_MovingWithCircularBuffer_u16(uint16_t value, AverageMoving_u16_t *avgMoving);


#pragma library average.lib    
#endif
