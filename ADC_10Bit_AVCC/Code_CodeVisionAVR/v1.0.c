// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <mega32_bits.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

float input_mv=0;
float input_v=0;

void ConfigLCD(void);
void DisplayMainPage(void);

#include <Attachment\ADC.h>

void main(void){
    ConfigLCD();
    ConfigADC();
    EnableADC(1);
    
    DDRB.0=1;
    PORTB.0=CHECK_ADC_ENABLE;
    while(1){
        input_int=GetIntValueFromADC(SINGLE7); 
        input_v=GetMilliVoltFromADC(SINGLE7); 
        DisplayMainPage();
        delay_ms(250);                                        
    };
}

//********************************************************
void DisplayMainPage(void){
    char txt[16];
    
    lcd_gotoxy(0,0); 
    lcd_putsf("In(0-1023):");
    itoa(input_int,txt); lcd_puts(txt); lcd_putsf(" ");
    
    lcd_gotoxy(0,1); 
    lcd_putsf("In(0-5V):");
    ftoa(input_v,3,txt); lcd_puts(txt); lcd_putsf(" ");   
}

//********************************************************
void ConfigLCD(void){
    lcd_init(16); lcd_clear();   
}


