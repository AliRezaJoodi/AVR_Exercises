// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

void Configuration_LCD(void);
void Display_loading(void);
void Display_Advertising(void);
unsigned char Keypad_Get(void);
char Converter(char);
void Display_Number(char, char);

char numer_initial, numer_correct;   
char numer_old=0;

void main(void){ 
    Configuration_LCD();
    Display_loading(); 
    Display_Advertising();
     
    Display_Number(numer_initial, numer_correct);
   
    while(1){
        numer_initial=Keypad_Get(); 
        numer_correct=Converter(numer_initial);
        
        if(numer_correct<12 && numer_old!=numer_correct){
            Display_Number(numer_initial, numer_correct);
            numer_old= numer_correct;
  	    }
    }
}

//*******************************************************
void Display_Number(char x1, char x2){
    char buffer[16];
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Num(Initial):"); 
    lcd_gotoxy(13,0); itoa(x1,buffer); lcd_puts(buffer);
    
    lcd_gotoxy(0,1); lcd_putsf("Num(Correct):"); 
    lcd_gotoxy(13,1); itoa(x2,buffer); lcd_puts(buffer);
}

//********************************************************
unsigned char Keypad_Get(void){
    char numer;
    DDRC=0b00001111; PORTC=0b11110000; delay_us(5); numer=PINC; 
    DDRC=0b11110000; PORTC=0b00001111; delay_us(5); numer=numer|PINC;
    return numer;
}

//********************************************************
char Converter(char key){
    #define Key_Max 12
    char i=0, number=0; 
    char keypad_data[12][2]={
        {238,0},
        {237,1},
        {235,2},
        {231,3},
        {222,4},
        {221,5},
        {219,6},
        {215,7},
        {190,8},
        {189,9},
        {187,10},
	    {183,11},
    };
    
    char keypad_data2[12]={10,7,4,1,0,8,5,2,11,9,6,3}; 
     
    if(key!=0xff){ 
        for(i=0; i<Key_Max; i++){    
            if(key==keypad_data[i][0])  break;   
        }
        number= keypad_data[i][1];
        number= keypad_data2[number];
    }  
    else number= Key_Max;
    
    return number; 
}

//********************************************************
void Configuration_LCD(void){
    lcd_init(16); lcd_clear();
}

//********************************************************
void Display_loading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
    delay_ms(500); lcd_clear();
}

//********************************************************
void Display_Advertising(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("GitHub.com");
    lcd_gotoxy(0,1); lcd_putsf("AliRezaJoodi");
    delay_ms(500); lcd_clear();
}





