// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_INCLUDED
#define _UTILITY_INCLUDED  


#define GetMsb(INT)                         ((INT&0xFF00) >> 8)
#define GetLsb(INT)                         (INT&0x00FF)
#define GetInt(MSB,LSB)                     ((MSB<<8)+(LSB&0x00FF))
    
#define SetBit(ADDRESS, BIT)                ADDRESS = (ADDRESS) | (1<<(BIT));
#define ClearBit(ADDRESS, BIT)              ADDRESS = (ADDRESS) & (~(1<<(BIT)));
#define ToggleBit(ADDRESS, BIT)             ADDRESS = (ADDRESS) ^ (1<<(BIT));
#define ToggleData(ADDRESS)        			ADDRESS = ~(ADDRESS);
//#define ToggleByte(VALUE)                   VALUE = ~(VALUE);

#define WriteBit(ADDRESS, FROM, VALUE)		ADDRESS = ((ADDRESS) & (~(0b1<<(FROM)))) 	| ((0b1&(VALUE)) << (FROM));
#define Write2Bit(ADDRESS, FROM, VALUE)		ADDRESS = ((ADDRESS) & (~(0b11<<(FROM)))) 	| ((0b11&(VALUE)) << (FROM));
#define Write3Bit(ADDRESS, FROM, VALUE)		ADDRESS = ((ADDRESS) & (~(0b111<<(FROM)))) 	| ((0b111&(VALUE)) << (FROM));
#define Write4Bit(ADDRESS, FROM, VALUE)		ADDRESS = ((ADDRESS) & (~(0b1111<<(FROM)))) | ((0b1111&(VALUE)) << (FROM));
#define Write5Bit(ADDRESS, FROM, VALUE)		ADDRESS = ((ADDRESS) & (~(0b11111<<(FROM))))| ((0b11111&(VALUE)) << (FROM));

#define GetBit(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0b1)
#define Get2Bit(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0b11)
#define Get3Bit(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0b111)
#define Get4Bit(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0b1111)
#define Get5Bit(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0b11111)


#endif

    
    