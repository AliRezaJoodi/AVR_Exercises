// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <mega32a.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "thermocouple_k.h"

//float tc_mv=0;
//int tc_temp;

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

void ADC_Init(void);
void LCD_Config(void);
//void Display_Temp(float,int);
//void Test(void);
void LCD_DisplayMainPage(int32_t uv, int16_t temp);

void main(void){
    int16_t tc_buf = 0;
    int16_t tc_buf_last = 0;
    int32_t tc_mv, tc_uv;
    int16_t tc_temp = 0;
    int16_t cj_temp = 50;   // Cold Junction
    int32_t cj_uv = 0;

    uint8_t lcd_flag = 0;

    LCD_Config();
    ADC_Init();

    while (1){
        tc_buf = read_adc(TC_CH);
        if(tc_buf != tc_buf_last){
            tc_buf_last = tc_buf;
            tc_mv = ((uint32_t)tc_buf * ADC_VREF) >> ADC_RESOLUTION_BIT;
            tc_uv = (tc_mv * 1000) / TC_GAIN;
            cj_uv = TC_ConvertTempToMicroVolt(cj_temp);
            tc_temp = TC_ConvertMicroVoltToTemp(tc_uv + cj_uv);

            lcd_flag = 1;
        }

        if(lcd_flag){
            lcd_flag = 0;
            LCD_DisplayMainPage(tc_uv + cj_uv, tc_temp);
        }
    }
}

//******************************************
void LCD_DisplayMainPage(int32_t uv, int16_t temp){
    char txt[6];

    ltoa(uv, txt);
    lcd_gotoxy(0,0);
    lcd_putsf("TC(uV):");
    lcd_puts(txt);
    lcd_putsf("  ");

    itoa(temp, txt);
    lcd_gotoxy(0,1);
    lcd_putsf("Temp(C):");
    lcd_puts(txt);
    lcd_putsf("  ");
}

////******************************************
//void Test(void){
//    tc_mv=TC_ConvertTempToMilliVolt(1000);
//    //tc_mv = -6.404;
//    //tc_temp=TC_ConvertMilliVoltToTemp(tc_mv);
//    Display_Temp(tc_mv,tc_temp);
//    while(1){}
//}

////******************************************
//void Display_Temp(float in_mv,int temp){
//    char txt[16];
//    lcd_clear();
//    //lcd_gotoxy(0,1); lcd_putsf("Type K TC");
//    sprintf(txt,"TC:%4.3fmV",in_mv); lcd_gotoxy(0,0); lcd_puts(txt); //lcd_putsf("  ");
//    if(-270<=temp && temp<=1372){
//        //sprintf(txt,"%4.3fmV  %4d",in_mv, tc_temp); lcd_gotoxy(0,0); lcd_puts(txt); lcd_putchar(0); //lcd_putsf("  ");
//        sprintf(txt,"TC:%4d",tc_temp); lcd_gotoxy(0,1); lcd_puts(txt); lcd_putchar(0); //lcd_putsf("  ");
//    }
//    else{lcd_gotoxy(0,1); lcd_putsf("TC:Null"); lcd_putsf("    ");};
//}

//********************************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();
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




