//GitHub Account: GitHub.com/AliRezaJoodi

#include <lcd.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#ifndef TURN_OFF_THE_LCD
    #define TURN_ON_THE_LCD
#endif

#define BILLBOARD_PAGE  0
#define MAIN_PAGE       1

struct display_data{
    char text1[16]; 
    char text2[16];
    float valu1;
    float valu2;  
}display={"Lin 1","Lin 2",0,0};
        
//********************************************************
void ConfigLCD(void){
    lcd_init(16); 
    lcd_clear();   
}

//********************************************************
void DisplayMainPage(void){
    char txt[16];
    lcd_clear(); 
    lcd_gotoxy(0,0); ftoa(display.valu1,3,txt); lcd_putsf("Volt(V):"); lcd_puts(txt); 
    lcd_gotoxy(0,1); ftoa(display.valu2,3,txt); lcd_putsf("Amp(A):"); lcd_puts(txt);
}

//********************************************************
void DisplayBillboardPage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_puts(display.text1);
    lcd_gotoxy(0,1); lcd_puts(display.text2);
}

//********************************************************
void DisplayLoading(void){
    strcpy(display.text1, "Test LCD"); 
    strcpy(display.text2, "Loding ...");
    DisplayBillboardPage();
}

//********************************************************
void SyncronValues(void){
    display.valu1=device1.volt;
    display.valu2=device1.amp;
}

//********************************************************
void DisplayValuesOnTheLCD(char page){
    #ifdef TURN_ON_THE_LCD
        SyncronValues();
     
        switch (page){
            case BILLBOARD_PAGE: 
                DisplayLoading();
                break;
            case MAIN_PAGE:  
                DisplayMainPage();
                break;
        }
    #endif
}