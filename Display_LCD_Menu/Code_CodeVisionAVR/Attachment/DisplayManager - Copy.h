
#include <lcd.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

// structure that contains controller specific graphic LCD initialization data
struct display_data{
    char value1;
    char value2;  
}menu;
        
//********************************************************
void Configuration_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void DisplayMenu2(struct display_data data){
    char txt[16];
    lcd_gotoxy(0,0); itoa(data.value1,txt);  lcd_putsf("Volt(V):"); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); itoa(data.value2,txt); lcd_putsf("Amp(A):"); lcd_puts(txt); lcd_putsf("  ");
}

//********************************************************
void Display_Loading(void){
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
