// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

#include <Attachment\Config_ADC.h>
#define CH_ADC 7

unsigned int input_int=0;
float input_mv=0;
float input_v=0;
    
void Config_LCD(void);
void Display_Value(void);
void Display2_Value(void);

void main(void){
   Config_LCD();
   Config_ADC();

    while (1){
        input_int=Get_ADC_Int(CH_ADC);
        input_mv=Get_ADC_mV(CH_ADC); 
        input_v=Get_ADC_V(CH_ADC); 
        Display_Value();
        delay_ms(500); 
    }   
}

//********************************************************
void Display_Value(void){
    char txt[16]; 
    itoa(input_int,txt); lcd_gotoxy(0,0); lcd_putsf("In(0-1023):"); lcd_puts(txt); lcd_putsf(" ");
    ftoa(input_v,3,txt); lcd_gotoxy(0,1); lcd_putsf("In(0-3V3):"); lcd_puts(txt); lcd_putsf(" ");  

}

//********************************************************
void Display2_Value(void){
    char txt[16]; 
    //itoa(input_int,txt); lcd_gotoxy(0,0); lcd_putsf("In(0-1023):"); lcd_puts(txt); lcd_putsf(" ");
    ftoa(input_v,3,txt); lcd_gotoxy(0,0); lcd_putsf("In(0-3V3):"); lcd_puts(txt); lcd_putsf(" ");  
    lcd_gotoxy(0,1); lcd_putsf("ADC 10Bit AREF");
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();
}





