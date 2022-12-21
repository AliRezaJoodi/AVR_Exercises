// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (1<<ADLAR))
#define GAIN    5000/256

void Config_LCD(void);
void Display_loading(void);
void Display_Advertising(void);
void Config_ADC(void);
unsigned char read_adc(unsigned char);
void Get_ADC(unsigned char);
void Display_In(void);

float w=0;
float Input_mV=0;
float Input_V=0;

void main(void){

    Config_LCD();
    Display_loading();  
    Display_Advertising();
    Config_ADC(); 

    while(1){
        Get_ADC(7);
        Display_In();
        delay_ms(200); 
    }
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
    
    lcd_gotoxy(0,0); 
    lcd_putsf("In(0-256):");
    itoa(w,buffer); lcd_puts(buffer); lcd_putsf(" ");
    
    lcd_gotoxy(0,1); 
    lcd_putsf("In(0-5V):");
    ftoa(Input_V,3,buffer); lcd_puts(buffer); lcd_putsf(" ");   
}

//********************************************************
void Display_loading(void){
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

//********************************************************
void Config_ADC(void){
    // ADC initialization
    // ADC Clock frequency: 125.000 kHz
    // ADC Voltage Reference: AVCC pin
    // ADC Auto Trigger Source: ADC Stopped
    // Only the 8 most significant bits of
    // the AD conversion result are used
    ADMUX=ADC_VREF_TYPE;
    ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
}

//********************************************************
// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input){
    ADMUX=adc_input | ADC_VREF_TYPE;
    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);
    // Start the AD conversion
    ADCSRA|=(1<<ADSC);
    // Wait for the AD conversion to complete
    while ((ADCSRA & (1<<ADIF))==0);
    ADCSRA|=(1<<ADIF);
    return ADCH;
}

//********************************************************
void Config_LCD(void){
    // Alphanumeric LCD initialization
    // Connections are specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTD Bit 0
    // RD - PORTD Bit 1
    // EN - PORTD Bit 2
    // D4 - PORTD Bit 4
    // D5 - PORTD Bit 5
    // D6 - PORTD Bit 6
    // D7 - PORTD Bit 7
    // Characters/line: 16
    lcd_init(16); lcd_clear();   
}