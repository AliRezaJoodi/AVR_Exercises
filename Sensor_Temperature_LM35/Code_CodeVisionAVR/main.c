// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include <lm35.h>

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input){
    ADMUX=adc_input | ADC_VREF_TYPE;
    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);
    // Start the AD conversion
    ADCSRA|=(1<<ADSC);
    // Wait for the AD conversion to complete
    while ((ADCSRA & (1<<ADIF))==0);
    ADCSRA|=(1<<ADIF);
    return ADCW;
}

void ADC_Config(void);
void LCD_Config(void);
void LCD_DisplayMainPage(float, float);

void main(void){
    float input_mv = 0;
    float temp = 0;
    
    ADC_Config();
    LCD_Config();

    while(1){ 
        input_mv = read_adc(LM35_CH) * 4.8875855; 
        temp = LM35_ConvertMilliVoltToTemp(input_mv);
        LCD_DisplayMainPage(input_mv, temp);
        delay_ms(250);                                       
    };
}

//********************************************************
void LCD_DisplayMainPage(float mv, float temp){
    char txt[16];
     
    lcd_gotoxy(0,0);
    lcd_putsf("Input(mV):");
    itoa(mv, txt);
    lcd_puts(txt);
    lcd_putsf("  ");
    
    lcd_gotoxy(0,1);
    lcd_putsf("Temp(^C):");
    ftoa(temp,1,txt);
    lcd_puts(txt);
    lcd_putsf("  ");   
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void ADC_Config(void){
    // ADC initialization
    // ADC Clock frequency: 500.000 kHz
    // ADC Voltage Reference: AVCC pin
    // ADC Auto Trigger Source: ADC Stopped
    ADMUX=ADC_VREF_TYPE;
    ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (1<<ADPS0);
    SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
}




