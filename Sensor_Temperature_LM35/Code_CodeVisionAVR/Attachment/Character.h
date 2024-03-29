// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef INCLUDED_CHAR
    #define INCLUDED_CHAR
    
#ifndef PORTS_CHAR
    #define PORTS_CHAR
     
    #define CHAR0               char0
    #define CHAR1               char1
#endif

#pragma used+

typedef unsigned char byte;
flash byte char0[8]={
    0b10000111,
    0b10000101,
    0b10000111,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000
};  //^

flash byte char1[8]={
    0b10001000,
    0b10010100,
    0b10001000,
    0b10000011,
    0b10000100,
    0b10000100,
    0b10000011,
    0b10000000
};  //^c

//********************************************************
//Syntax for define:    define_char(CHAR_DEGREE,0);
//Syntax for use:       lcd_putchar(0);
void define_char(byte flash *pc,byte char_code){
    byte i,a;
    a=(char_code<<3) | 0x40;
    for (i=0; i<8; i++) {lcd_write_byte(a++,*pc++);}
}

#pragma used-

#endif
