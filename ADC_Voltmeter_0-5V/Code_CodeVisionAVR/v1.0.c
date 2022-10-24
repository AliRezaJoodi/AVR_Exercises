/*
    Title:               0~5V Voltmeter
    MCU:                 ATmega32  
    Clock Frequency:     1.000000 MHz  
    Voltage References:  AVCC  
    GitHub Account:     GitHub.com/AliRezaJoodi
*/

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

#define ADC_VREF_TYPE 0x40
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
float Read_the_adc(unsigned char);
void Display_LCD(float);

float Input_mV=0;

void main(void){
    Configuration_ADC();
    Configuration_LCD();
    Display_LCD_Start(); 
    
    while (1){
        Input_mV=Read_the_adc(7);
        Display_LCD(Input_mV);
        delay_ms(300);                                        
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
float Read_the_adc(unsigned char ch){
     float x=0; 
     x=read_adc(ch);
     x= x*4.8828125;
     return x;
}

//********************************************************
void Display_LCD(float x){
    char buffer[16];
    //char txt[16];
    
    lcd_gotoxy(0,0); 
    lcd_putsf("Input(mV): ");
    ftoa(x,0,buffer); lcd_puts(buffer);
    lcd_putsf(" ");
    //strcat(txt, "Input(mV): ");
    //strcat(txt, buffer);
    //strcat(txt, " ");
    //lcd_puts(txt); 
    
    x=x/1000;
    lcd_gotoxy(0,1); 
    lcd_putsf("Input(V): ");
    ftoa(x,2,buffer); lcd_puts(buffer);
    lcd_putsf(" ");   
}


