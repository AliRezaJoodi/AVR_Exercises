#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

/*
 * Choose ONLY ONE configuration below:
 * - TIMEBASE_REG8_U8    (8-bit registers, 8-bit counter)
 * - TIMEBASE_REG8_U32   (8-bit registers, 32-bit counter)
 * - TIMEBASE_REG32_U32  (32-bit registers, 32-bit counter)
 */
#define TIMEBASE_CONFIG
    #define TIMEBASE_REG8_U8

#endif
