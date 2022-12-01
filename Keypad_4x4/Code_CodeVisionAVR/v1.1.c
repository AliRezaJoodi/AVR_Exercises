// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include <Attachment\Keypad_4x4.h>

void Configuration_LCD(void);
void Display_loading(void);
void Display_Advertising(void);
void Display_Number(char, char);
void Display2_Number(char, char);

unsigned char numer_initial, numer_correct;   
unsigned char numer_old=0;

void main(void){ 
    Configuration_LCD();
    Display_loading(); 
    Display_Advertising(); 
    Display2_Number(numer_initial, numer_correct);
   
    while(1){
        numer_initial=Get_Port(); 
        numer_correct=Converter_Data(numer_initial);
        //numer_correct=Get_Keypad();
        
        if(numer_correct<16 && numer_old!=numer_correct){
            Display2_Number(numer_initial, numer_correct);
            numer_old= numer_correct;
  	    }
    }
}


//*******************************************************
void Display2_Number(char x1, char x2){
    char buffer[16]; 
    lcd_clear();
    
    lcd_gotoxy(0,0); itoa(x1,buffer); lcd_puts(buffer); lcd_putsf("  ");
    lcd_gotoxy(4,0); lcd_putsf("=>"); 
    lcd_gotoxy(7,0); itoa(x2,buffer); lcd_puts(buffer); lcd_putsf("  ");
        
    lcd_gotoxy(0,1); lcd_putsf("4x4Keypad Driver"); 
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
void Configuration_LCD(void){
    lcd_init(16); lcd_clear();
}

//********************************************************
void Display_loading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("4x4Keypad Driver");
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





