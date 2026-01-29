// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_BIT_INCLUDED
#define _UTILITY_BIT_INCLUDED  


#define SET_BIT(ADDRESS, POS)               ((ADDRESS) |= (0x01U << (POS)))    
#define CLEAR_BIT(ADDRESS, POS)             ((ADDRESS) &= ~(0x01U << (POS)))
#define TOGGLE_BIT(ADDRESS, POS)            ((ADDRESS) ^= (0x01U << (POS)))
#define TOGGLE_DATA(ADDRESS)                (~(ADDRESS))

#define WRITE_BIT( ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x01U << (POS))) | ((0x01U & (VALUE)) << (POS)))
#define WRITE_2BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x03U << (POS))) | ((0x03U & (VALUE)) << (POS)))
#define WRITE_3BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x07U << (POS))) | ((0x07U & (VALUE)) << (POS)))
#define WRITE_4BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x0FU << (POS))) | ((0x0FU & (VALUE)) << (POS)))
#define WRITE_5BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x1FU << (POS))) | ((0x1FU & (VALUE)) << (POS)))
#define WRITE_6BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x3FU << (POS))) | ((0x3FU & (VALUE)) << (POS)))
#define WRITE_7BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x7FU << (POS))) | ((0x7FU & (VALUE)) << (POS)))
#define WRITE_8BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0xFFU << (POS))) | ((0xFFU & (VALUE)) << (POS)))

#define GET_BIT( ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x01U)
#define GET_2BIT(ADDRESS, POS)           	(((ADDRESS) >> (POS)) & 0x03U)
#define GET_3BIT(ADDRESS, POS)           	(((ADDRESS) >> (POS)) & 0x07U)
#define GET_4BIT(ADDRESS, POS)           	(((ADDRESS) >> (POS)) & 0x0FU)
#define GET_5BIT(ADDRESS, POS)           	(((ADDRESS) >> (POS)) & 0x1FU)
#define GET_6BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x3FU)
#define GET_7BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x7FU)
#define GET_8BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0xFFU)

#endif

    
    