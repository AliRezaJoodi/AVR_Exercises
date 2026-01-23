// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_BYTE_INCLUDED
#define _UTILITY_BYTE_INCLUDED  

#include <stdint.h>

static inline uint8_t GetMsb(uint16_t value){
    return (uint8_t)(value >> 8);
}

static inline uint8_t GetLsb(uint16_t value){
    return (uint8_t)(value & 0xFF);
}

static inline uint16_t MakeU16(uint8_t msb, uint8_t lsb){
    return ( ( (uint16_t)msb << 8 ) | lsb );
}

#endif
