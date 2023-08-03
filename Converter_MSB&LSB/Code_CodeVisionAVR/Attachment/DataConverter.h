// GitHub Account: GitHub.com/AliRezaJoodi

#define SetBit(ADDRESS,BIT)                 (ADDRESS|=(1<<BIT))
#define ClearBit(ADDRESS,BIT)               (ADDRESS&=~(1<<BIT))
#define ToggleBit(ADDRESS,BIT)              (ADDRESS^=(1<<BIT))
#define CheckBit(ADDRESS,BIT)               ((ADDRESS&(1<<BIT))>>BIT)
#define EqualBit(ADDRESS,BIT,STATUS)        if(STATUS){SetBit(ADDRESS,BIT);} else{ClearBit(ADDRESS,BIT);}
#define ToggleByte(VALUE)                   (VALUE^0b11111111) 

#define GetMsb(INT)                         ((INT&0xFF00)>>8)
#define GetLsb(INT)                         (INT&0x00FF)
#define GetInt(MSB,LSB)                     ((MSB<<8)+(LSB&0x00FF))

#define FixValueBetween0To100(VALUE)        if(VALUE<0){VALUE=0;} else if(VALUE>100){VALUE=100;}
#define InverseValueBetween0To100(VALUE)    VALUE=100-VALUE;

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
