#include <stdint.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "utility_bit.h"
#include "controller_onoff.h"

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
void IO_Config(void);
void LCD_Display(const CtrlOnOff_In_t *params);

void main(void){
    CtrlOnOff_In_t oven = {
        .sp = 250,
        .hysteresis = 10,
        .pv = 0
    };

    int32_t buf = 0;
    uint16_t pv_last = 0;
    uint8_t task_lcd = 0;
    uint8_t control = 0;

    ADC_Init();
    IO_Config();
    LCD_Config();

    delay_ms(250);
    lcd_clear();

    while(1){
        buf = read_adc(TEMP_CH);
        oven.pv = (buf * 500) >> 10 ;  // mV = (Dn *5000) / 1024 , temp = mV / 10;

        control = Ctrl_OnOff_Update(&oven);

        switch(control){
            case CTRL_ONOFF_LOW:
                WRITE_BIT(RLY_PORT, RLY_BIT, RLY_ACTIVATE);
                break;
            case CTRL_ONOFF_HIGH:
                WRITE_BIT(RLY_PORT, RLY_BIT, !RLY_ACTIVATE);
                break;
        }

        if(oven.pv != pv_last){
            pv_last = oven.pv;
            task_lcd = 1;
        }

        if(task_lcd){
            task_lcd =0;
            LCD_Display(&oven);
        }
    }
}

//******************************************
void LCD_Display(const CtrlOnOff_In_t *params){
    char txt[6];
    uint16_t buf = 0;
    uint16_t half = params->hysteresis >> 1;

    lcd_gotoxy(0,0); lcd_putsf("Min SP  Max  PV");

    buf = params->sp - half;
    itoa(buf, txt);
    lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("  ");

    itoa(params->sp, txt);
    lcd_gotoxy(4,1); lcd_puts(txt); lcd_putsf("  ");

    buf = params->sp + half;
    itoa(buf, txt);
    lcd_gotoxy(8,1); lcd_puts(txt); lcd_putsf("  ");

    itoa(params->pv, txt);
    lcd_gotoxy(13,1); lcd_puts(txt); lcd_putsf("  ");
}

//******************************************
void IO_Config(void){
    //RLY_DDR = 0; RLY_PORT = !RLY_ACTIVATE;
    SET_BIT(RLY_DDR, RLY_BIT);
    WRITE_BIT(RLY_PORT,RLY_BIT, !RLY_ACTIVATE);
}

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
