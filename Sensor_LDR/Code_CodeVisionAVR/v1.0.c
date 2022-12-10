// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#define GAIN    5000/1023
#define CH_LCR   7

void Config_LCD(void);
void Config_ADC(void);
float Read_adc(unsigned char);
void Display_LDR(float);

float in_mv=0;

void main(void){
    Config_ADC();
    Config_LCD(); 
    
    while (1){
        in_mv=Read_adc(CH_LCR);
        Display_LDR(in_mv);
        delay_ms(300);                                        
    };
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Config_ADC(void){
    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR=0x80;
    SFIOR=0x00;

    // ADC initialization
    // ADC Clock frequency: 125.000 kHz
    // ADC Voltage Reference: AVCC pin
    ADMUX=0x40 & 0xff;
    ADCSRA=0x83;
}

//********************************************************
float Read_adc(unsigned char adc_input){
    float x=0;
    ADMUX=adc_input | (0x40 & 0xff);
    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);
    // Start the AD conversion
    ADCSRA|=0x40;
    // Wait for the AD conversion to complete
    while ((ADCSRA & 0x10)==0);
    ADCSRA|=0x10;
    x=ADCW; x= x*GAIN;
    return x;
}

//********************************************************
void Display_LDR(float mv){
    char txt[16]; 
    lcd_gotoxy(0,0); lcd_putsf("Input(V):"); ftoa(mv/1000,3,txt); lcd_puts(txt); lcd_putsf(" ");
    lcd_gotoxy(0,1); lcd_putsf("LDR Driver");
}



