//GitHub Account:   GitHub.com/AliRezaJoodi

#include <delay.h>

#ifndef _BARGRAPH_INCLUDED
#define _BARGRAPH_INCLUDED

#ifndef BARGRAPH_HARDWARE
#define BARGRAPH_HARDWARE
    #define LCD_COLUMN      16
    #define MAXIMUM_BAR     LCD_COLUMN * 5
    #define DISPLAY_ROW     1    
#endif

#define BAR1       2
#define BAR2       3
#define BAR3       4
#define BAR4       5
#define BAR5       6

#pragma used+

typedef unsigned char byte;
flash byte bar1[8]={
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
};  

flash byte bar2[8]={
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
};

flash byte bar3[8]={
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
};

flash byte bar4[8]={
    0b11110,
    0b11110,
    0b11110,
    0b11110,
    0b11110,
    0b11110,
    0b11110,
};

flash byte bar5[8]={
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
};

//********************************************************
//Syntax for define:    define_char(bar1,0);
//Syntax for use:       lcd_putchar(0);
void _define_char(byte flash *pc,byte char_code){
    byte i,a;
    a=(char_code<<3) | 0x40;
    for (i=0; i<8; i++) {lcd_write_byte(a++,*pc++);}
}

//********************************************************
void _BarGraph_DefineAllChars(void){
    _define_char(bar1,BAR1);
    _define_char(bar2,BAR2);
    _define_char(bar3,BAR3);
    _define_char(bar4,BAR4);
    _define_char(bar5,BAR5);   
}

// Input(float):    0~100%
//********************************************************
void BarGraph_DisplayBarGraph(float percent){
    float bars_float=0; 
    unsigned char bars=0;
    unsigned char n5=0;
    unsigned char n_=0;
    unsigned char i=0;
    unsigned char null=0;
    
    static char status=0;
    if(status==0){_BarGraph_DefineAllChars(); status=1;}
    
    lcd_gotoxy(0,DISPLAY_ROW); 
     
    if(percent<0){percent=0;} else if(percent>100){percent=100;} 
    bars_float=percent/100*MAXIMUM_BAR; bars=bars_float;
    
    n5=bars/5; for(i=0; i<n5; ++i){lcd_putchar(BAR5);}
      
    n_=bars%5;
    if(n_==1){lcd_putchar(BAR1);}
        else if(n_==2){lcd_putchar(BAR2);} 
            else if(n_==3){lcd_putchar(BAR3);}
                else if(n_==4){lcd_putchar(BAR4);}
                    else if(n_==5){lcd_putchar(BAR5);}
    
   null=LCD_COLUMN-n5; if(n_!=0){--null;} 
   for(i=0;i<null;++i){lcd_putsf(" ");}
}

//********************************************************
void _BarGraph_Test(void){
    unsigned char i=0;
    float value=0;
       
    for(i=0; i<=100; ++i){ 
        value=i;
        BarGraph_DisplayBarGraph(value); 
        delay_ms(2);
    } 
    
    for(i=100; i>0; --i){
        value=i;
        BarGraph_DisplayBarGraph(value); 
        delay_ms(2);
    }   
}

#pragma used-
#endif


