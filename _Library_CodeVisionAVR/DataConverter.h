// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _CONVERTER_INCLUDED
    #define _CONVERTER_INCLUDED

#define FixValueBetween0To100(VALUE)        if(VALUE<0){VALUE=0;} else if(VALUE>100){VALUE=100;}
#define InverseValueBetween0To100(VALUE)    VALUE= 100-VALUE;

#define Convert_0to100_0to1023(VALUE)       (VALUE*10.23)
#define Convert_0to100_0to255(VALUE)        (VALUE*2.55)
#define Convert_0to100_0to5V(VALUE)         (VALUE*0.05)
#define Convert_0to100_1to5V(VALUE)         ((VALUE*0.04)+1)
#define Convert_0to100_0to3V3(VALUE)        (VALUE*0.033)

#define Convert_0to5V_0to1023(VALUE)        (VALUE*204.6)
#define Convert_0to5V_0to255(VALUE)         (VALUE*51)
#define Convert_0to3V3_0to1023(VALUE)       (VALUE*310)
#define Convert_0to3V3_0to255(VALUE)        (VALUE*77.272727)

#define Convert_0to1023_0to5V(VALUE)        (VALUE*0.0048875855)
#define Convert_0to255_0to5V(VALUE)         (VALUE*0.0196078)
#define Convert_0to1023_0to2V56(VALUE)      (VALUE*0.002502444)
#define Convert_0to255_0to2V56(VALUE)       (VALUE*0.0100391936)

#endif

