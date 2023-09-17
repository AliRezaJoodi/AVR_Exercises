// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_INCLUDED
    #define _UTILITY_INCLUDED  
    
#define SetBit(ADDRESS,BIT)                 ADDRESS= (ADDRESS) | (1<<(BIT));
#define ClearBit(ADDRESS,BIT)               ADDRESS= (ADDRESS) & (~(1<<(BIT)));
#define ToggleBit(ADDRESS,BIT)              ADDRESS= (ADDRESS) ^ (1<<(BIT));
#define WriteBit(ADDRESS,BIT,STATUS)        ADDRESS= ((ADDRESS) & (~(0b1<<(BIT)))) | (((STATUS)&0b1) << (BIT));
#define GetBit(ADDRESS,BIT)                 (((ADDRESS) >> (BIT)) & 0b1)
#define ToggleByte(VALUE)                   VALUE= ~(VALUE);

#define GetMsb(INT)                         (((INT)&0xFF00) >> 8)
#define GetLsb(INT)                         ((INT)&0x00FF)
#define GetInt(MSB,LSB)                     (((MSB)<<8)+((LSB)&0x00FF))

#endif

    
    