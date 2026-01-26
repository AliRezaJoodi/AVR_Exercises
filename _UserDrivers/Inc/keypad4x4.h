// GitHub Account:     GitHub.com/AliRezaJoodi

#include <io.h>
#include <delay.h> 

#ifndef _KEYPAD4x4_INCLUDED
#define _KEYPAD4x4_INCLUDED

#ifndef KEYPAD4x4_HARDWARE
#define KEYPAD4x4_HARDWARE
    #define KEYPAD4x4_DDR       DDRC
    #define KEYPAD4x4_PORT      PORTC
    #define KEYPAD4x4_PIN       PINC 
    
    #define N00                 215
    #define N01                 235
    #define N02                 219
    #define N03                 187
    #define N04                 237
    #define N05                 221
    #define N06                 189
    #define N07                 238
    #define N08                 222
    #define N09                 190
    #define N10                 126
    #define N11                 125
    #define N12                 123
    #define N13                 119
    #define N14                 183
    #define N15                 231
#endif

#pragma used+
unsigned char _Keypad4x4_GetInitialNumber(void);
unsigned char _Keypad4x4_ConvertNumber(unsigned char key);
unsigned char Keypad4x4_GetNumber(void);
#pragma used-

#pragma library keypad4x4.lib

#endif
