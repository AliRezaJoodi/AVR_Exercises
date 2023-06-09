
#include <lcd.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

struct display_data{
    char txt1[16]; 
    char txt2[16];
    char value1;
    char value2;  
}display={"Lin1","Lin2",0,0};
        
//********************************************************
void ConfigLCD(void){
    lcd_init(16); 
    lcd_clear();   
}

//********************************************************
void DisplayMenu2(void){
    char txt[16];
    lcd_clear(); 
    lcd_gotoxy(0,0); itoa(display.value1,txt);  lcd_putsf("Volt(V):"); lcd_puts(txt); 
    lcd_gotoxy(0,1); itoa(display.value2,txt); lcd_putsf("Amp(A):"); lcd_puts(txt);
}

//********************************************************
void DisplayMenu1(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_puts(display.txt1);
    lcd_gotoxy(0,1); lcd_puts(display.txt2);
}
