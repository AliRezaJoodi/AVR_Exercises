// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <mega32_bits.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

float input_v=0;
float ohm=0;

void LCD_Config(void);
void LCD_DisplayMainPage(void);

#include <ADC.h>
#include <NTC_100K.h>

void main(void){
    LCD_Config();
    ADC_Config_10Bit_AVCC();
    ADC_Enable(1);
    
    DDRB.0=1;
    PORTB.0=CHECK_ADC_ENABLE;
    while(1){
        input_v=ADC_GetVolt(SINGLE0);
        ohm=NTC_ConvertVoltToOhm(input_v);
        LCD_DisplayMainPage();
        delay_ms(250);                                        
    };
}

//********************************************************
void LCD_DisplayMainPage(void){
    char txt[16];
        
    lcd_gotoxy(0,0); 
    lcd_putsf("In(V):");
    ftoa(input_v,3,txt); lcd_puts(txt); lcd_putsf(" ");
    
    lcd_gotoxy(0,1); 
    lcd_putsf("Ohm(K):");
    ftoa(ohm/1000,3,txt); lcd_puts(txt); lcd_putsf(" ");   
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}


