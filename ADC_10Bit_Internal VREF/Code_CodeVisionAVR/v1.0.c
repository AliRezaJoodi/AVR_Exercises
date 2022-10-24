// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>
//#include <string.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#define ADC_VREF_TYPE 0xC0
#define GAIN    2560/1023
// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input){
    ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);
    // Start the AD conversion
    ADCSRA|=0x40;
    // Wait for the AD conversion to complete
    while ((ADCSRA & 0x10)==0);
    ADCSRA|=0x10;
    return ADCW;
}

void Configuration_LCD(void);
void Configuration_ADC(void);
void Display_LCD_Start(void);
void Get_ADC(unsigned char);
void Display_In(void);

float w=0;
float Input_mV=0;
float Input_V=0;

void main(void){
    Configuration_LCD();
    Configuration_ADC();
    Display_LCD_Start(); 
    
    while (1){
        Get_ADC(7);
        Display_In();
        delay_ms(200);                                        
    };
}

//********************************************************
void Configuration_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Configuration_ADC(void){
    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR=0x80;
    SFIOR=0x00;

    // ADC initialization
    // ADC Clock frequency: 125.000 kHz
    // ADC Voltage Reference: AVCC pin
    ADMUX=ADC_VREF_TYPE & 0xff;
    ADCSRA=0x83;
}

//********************************************************
void Display_LCD_Start(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("GitHub.com");
    lcd_gotoxy(0,1); lcd_putsf("AliRezaJoodi");
    delay_ms(1000); lcd_clear();
}

//********************************************************
void Get_ADC(unsigned char ch){
     w=read_adc(ch);
     Input_mV= w*GAIN;
     Input_V= Input_mV/1000;
}

//********************************************************
void Display_In(void){
    char buffer[16];
    //char txt[16];
    
    lcd_gotoxy(0,0); 
    lcd_putsf("In(0-1023):");
    itoa(w,buffer); lcd_puts(buffer); lcd_putsf(" ");
    
    //strcat(txt, "Input(mV): ");
    //strcat(txt, buffer);
    //strcat(txt, " ");
    //lcd_puts(txt); 
    
    lcd_gotoxy(0,1); 
    lcd_putsf("In(V):");
    ftoa(Input_V,3,buffer); lcd_puts(buffer); lcd_putsf(" ");   
}


