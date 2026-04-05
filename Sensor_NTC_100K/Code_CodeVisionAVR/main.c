// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

#include "hardware.h"
#include "ntc100k.h"

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

void LCD_Config(void);
void LCD_DisplayMainPage(uint32_t ohm, int16_t temp);
void ADC_Init(void);
uint16_t ConvertCountToMilliVolt(uint16_t count);
uint32_t ConvertMilliVoltToOhm(uint16_t mv, uint32_t res);

void main(void){
    uint16_t in = 0;
    uint16_t in_last = 0;
    uint16_t mv = 0;
    uint32_t ohm = 0;
    int16_t temp = 10;
    uint8_t lcd_flag = 0;

    LCD_Config();
    ADC_Init();

    while(1){
        in = read_adc(NTC100K_CH);
        if(in != in_last){
            in_last = in;
            lcd_flag = 1;
        }

        if (lcd_flag){
            lcd_flag = 0;

            mv = ConvertCountToMilliVolt(in);
            ohm = ConvertMilliVoltToOhm(mv, NTC100K_RESISTOR);
            temp = NTC100K_ConvertOhmToTemp(ohm);
            LCD_DisplayMainPage(ohm, temp);
        }
    };
}

//********************************************************
uint16_t ConvertCountToMilliVolt(uint16_t count){
    return ((uint32_t)(count) * ADC_VREF_MV) >> ADC_RESOLUTION_BITS;
}

//********************************************************
uint32_t ConvertMilliVoltToOhm(uint16_t mv, uint32_t res){
    uint32_t ohm = 0;
    ohm = (uint32_t)(res * mv) / (ADC_VREF_MV - mv);
    return ohm;
}

//******************************************
void LCD_DisplayMainPage(uint32_t ohm, int16_t temp){
    char txt[6];

    //txt[0] = '\0';
    itoa(temp, txt);
    lcd_gotoxy(0,1);
    lcd_putsf("Temp:");
    lcd_puts(txt);
    lcd_putsf("  ");

    ltoa(ohm, txt);
    lcd_gotoxy(0,0);
    lcd_putsf("Ohm:");
    //txt[0] = '\0';
    lcd_puts(txt);
    lcd_putsf("  ");
}

//********************************************************
void ADC_Init(void){
    // ADC initialization
    // ADC Clock frequency: 125.000 kHz
    // ADC Voltage Reference: AVCC pin
    // ADC Auto Trigger Source: ADC Stopped
    ADMUX=ADC_VREF_TYPE;
    ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0);
    SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
}

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();
}


