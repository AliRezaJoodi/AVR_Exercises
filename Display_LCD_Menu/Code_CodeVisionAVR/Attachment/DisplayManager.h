//GitHub Account: GitHub.com/AliRezaJoodi

#include <lcd.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#ifndef TURN_OFF_LCD
    #define TURN_ON_LCD
#endif

#define LOADING_PAGE    0
#define AD_PAGE         1
#define MAIN_PAGE       2
#define SETVOLT_PAGE    3
#define SETAMP_PAGE     4

struct displayvalues{
    char mode;
    unsigned int delay;  
}display={MAIN_PAGE,500};
        
//********************************************************
void ConfigLCD(void){
    lcd_init(16); 
    lcd_clear();   
}

//********************************************************
void DisplayLoadingPage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Test LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loding ...");
}

//********************************************************
void DisplayAdvertagePage(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("GitHub.com");
    lcd_gotoxy(0,1); lcd_putsf("AliRezaJoodi");
}

//********************************************************
void DisplayMainPage(struct load value){
    char txt[16];
    lcd_clear(); 
    lcd_gotoxy(0,0); ftoa(value.volt,2,txt); lcd_putsf("Volt(V):"); lcd_puts(txt); 
    lcd_gotoxy(0,1); ftoa(value.amp,2,txt); lcd_putsf("Amp(A):"); lcd_puts(txt);
}

//********************************************************
void DisplaySetPage_Volt(struct load value){
    char txt[16];
    lcd_clear(); 
    lcd_gotoxy(0,0); ftoa(value.volt_sp,2,txt); lcd_putsf("Volt(V):"); lcd_puts(txt); 
    lcd_gotoxy(0,1); lcd_putsf("Set Point");
}

//********************************************************
void DisplaySetPage_Amp(struct load value){
    char txt[16];
    lcd_clear(); 
    lcd_gotoxy(0,0); ftoa(value.amp_sp,2,txt); lcd_putsf("Amp(A):"); lcd_puts(txt); 
    lcd_gotoxy(0,1); lcd_putsf("Set Point");
}

//********************************************************
void DisplayValuesOnTheLCD(void){
    #ifdef TURN_ON_LCD
        switch (display.mode){
            case LOADING_PAGE:
                DisplayLoadingPage(); delay_ms(display.delay); //lcd_clear();
                break;
            case AD_PAGE: 
                DisplayAdvertagePage(); delay_ms(display.delay); //lcd_clear();
                break;
            case MAIN_PAGE:  
                DisplayMainPage(device1);
                break;
            case SETVOLT_PAGE:
                DisplaySetPage_Volt(device1);
                break;
            case SETAMP_PAGE:
                DisplaySetPage_Amp(device1);
                break;
        }
    #endif
}