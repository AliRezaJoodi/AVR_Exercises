// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include <utility_bit.h>
#include <average.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#define TASK_VOLT1          0
#define TASK_VOLT2          1

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

void LCD_Config(void);
void LCD_DisplayMainPage(float volt, uint8_t line);
void ADC_Config(void);

void main(void){
    float volt1 = 0;
    uint16_t volt1_u16=0; 
    uint16_t volt1_last_u16=0;
    AverageBlock_u16_t volt1_t = {0};

    float volt2 = 0;
    uint16_t volt2_u16=0;
    uint16_t volt2_last_u16=0;
    AverageBlock_u16_t volt2_t = {0};
     
    uint8_t tasks=0;
    
    LCD_Config();
    ADC_Config();
      
    while(1){ 
        delay_ms(10);
        volt1_u16 = read_adc(ADC_CH1);
        volt1_u16 = Average_BlockUpdate_u16(volt1_u16, &volt1_t);
        if( volt1_u16 != volt1_last_u16 ){
            volt1_last_u16 = volt1_u16;
            volt1 = volt1_u16 * 4.8875855;
            SET_BIT(tasks, TASK_VOLT1);
        }
          
        volt2_u16 = read_adc(ADC_CH2);
        volt2_u16 = Average_BlockUpdate_u16(volt2_u16, &volt2_t);
        if( volt2_u16 != volt2_last_u16 ){
            volt2_last_u16 = volt2_u16;
            volt2 = volt2_u16 * 4.8875855;
            SET_BIT(tasks, TASK_VOLT2);
        }
                  
        if(GET_BIT(tasks, TASK_VOLT1)){
            CLEAR_BIT(tasks, TASK_VOLT1);
            LCD_DisplayMainPage(volt1, 1);
        }
                  
        if(GET_BIT(tasks, TASK_VOLT2)){
            CLEAR_BIT(tasks, TASK_VOLT2);
            LCD_DisplayMainPage(volt2, 2);
        }                                       
    };
}

//********************************************************
void LCD_DisplayMainPage(float volt, uint8_t line){
    char txt[16];
    switch (line){
        case 1:
            lcd_gotoxy(0,0);
            lcd_putsf("Volt1(mv):"); 
            itoa(volt, txt); 
            lcd_puts(txt);
            lcd_putsf("   "); 
            break;
        case 2:
            lcd_gotoxy(0,1);
            lcd_putsf("Volt2(mv):");
            itoa(volt, txt); 
            lcd_puts(txt);
            lcd_putsf("   "); 
            break;
        default:
            break;
    }
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





