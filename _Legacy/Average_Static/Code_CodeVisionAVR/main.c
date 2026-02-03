// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

//#include <adc.h>
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

#include <average_static.h>

void LCD_Config(void);
void LCD_DisplayMainPage(float);
void ADC_Config(void);

void main(void){
    uint16_t volt_u16=0;
    uint16_t volt_last_u16=0;     
    float volt=0;
    
    bit dispaly_task=0;
    
    LCD_Config();
    ADC_Config();
       
    while(1){
        volt_u16 = read_adc(7);
        volt_u16 = Average_BlockUpdate_u16(volt_u16);
        if(volt_u16 != volt_last_u16){ 
            volt_last_u16 = volt_u16; 
            volt = volt_u16 * 4.8875855;
            dispaly_task=1;
        }
          
        if(dispaly_task){ 
            dispaly_task = 0;
            LCD_DisplayMainPage(volt); 
        }                                       
    };
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

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();   
}

//********************************************************
void LCD_DisplayMainPage(float volt){
    char txt[16];
    
    lcd_gotoxy(0,0);
    lcd_putsf("Volt(mV):");
    itoa(volt, txt); 
    lcd_puts(txt);
    lcd_gotoxy(0,1); 
    lcd_putsf("Average");  
}




