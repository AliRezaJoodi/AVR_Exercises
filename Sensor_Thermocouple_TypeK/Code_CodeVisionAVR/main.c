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
    typedef struct{
        int32_t tc_uv;      // measured thermocouple voltage (TC = HJ - CJ)
        int32_t cj_uv;      // cold junction equivalent voltage
        int32_t hj_uv;      // hot junction equivalent voltage (HJ = TC + CJ)

        int16_t cj_temp;
        int16_t hj_temp;
    } TC_K_t;

    TC_K_t oven;

    int16_t buf = 0;
    int16_t buf_last = 0;
    int32_t mv;

    uint8_t lcd_flag = 0;

    LCD_Config();
    ADC_Init();

    while (1){
        buf = read_adc(TC_CH);
        if(buf != buf_last){
            buf_last = buf;
            mv = ((uint32_t)buf * ADC_VREF) >> ADC_RESOLUTION_BIT;
            oven.tc_uv = (mv * 1000) / TC_GAIN;
            oven.cj_temp = 50;  // Must be measured using a temperature sensor, for example the LM35.
            oven.cj_uv = TC_ConvertTempToMicroVolt(oven.cj_temp);
            oven.hj_uv = oven.tc_uv + oven.cj_uv;
            oven.hj_temp = TC_ConvertMicroVoltToTemp(oven.hj_uv);

            lcd_flag = 1;
        }

        if(lcd_flag){
            lcd_flag = 0;
            LCD_DisplayMainPage(oven.hj_uv, oven.hj_temp);
        }
    }
}

//******************************************
void LCD_DisplayMainPage(int32_t uv, int16_t temp){
    char txt[6];

    ltoa(uv, txt);
    lcd_gotoxy(0,0);
    lcd_putsf("HJ(uV):");   // hot junction
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




