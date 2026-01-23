// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_BIT_INCLUDED
#define _UTILITY_BIT_INCLUDED  


#define SET_BIT(ADDRESS, POS)               ((ADDRESS) |= (0x01U << (POS)))    
#define CLEAR_BIT(ADDRESS, POS)             ((ADDRESS) &= ~(0x01U << (POS)))
#define TOGGLE_BIT(ADDRESS, POS)            ((ADDRESS) ^= (0x01U << (POS)))
#define TOGGLE_DATA(ADDRESS)                (~(ADDRESS))

#define WRITE_BIT(ADDRESS,  POS,  VALUE)    ((ADDRESS) = ((ADDRESS) & ~(0x01U << (POS)))  | ((0x01U & (VALUE)) << (POS)))
#define WRITE_2BIT(ADDRESS, FROM, VALUE)    ((ADDRESS) = ((ADDRESS) & ~(0x03U << (FROM))) | ((0x03U & (VALUE)) << (FROM)))
#define WRITE_3BIT(ADDRESS, FROM, VALUE)    ((ADDRESS) = ((ADDRESS) & ~(0x07U << (FROM))) | ((0x07U & (VALUE)) << (FROM)))
#define WRITE_4BIT(ADDRESS, FROM, VALUE)    ((ADDRESS) = ((ADDRESS) & ~(0x0FU << (FROM))) | ((0x0FU & (VALUE)) << (FROM)))
#define WRITE_5BIT(ADDRESS, FROM, VALUE)    ((ADDRESS) = ((ADDRESS) & ~(0x1FU << (FROM))) | ((0x1FU & (VALUE)) << (FROM)))

#define GET_BIT(ADDRESS, POS)           	(((ADDRESS) >> (POS)) 	& 0x01U)
#define GET_2BIT(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0x03U)
#define GET_3BIT(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0x07U)
#define GET_4BIT(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0x0FU)
#define GET_5BIT(ADDRESS, FROM)           	(((ADDRESS) >> (FROM)) 	& 0x1FU)


#endif

    
    