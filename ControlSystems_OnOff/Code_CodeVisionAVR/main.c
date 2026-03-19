#include <stdint.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "utility_bit.h"
#include "controller_onoff.h"

typedef struct {
    volatile uint16_t temp;
    uint16_t sp;
    uint16_t hys;
} Oven_t;

Oven_t oven = {
    .temp = 0,  // ^C
    .sp = 250,  // ^C
    .hys = 10   // ^C
};

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

void LCD_Display(void);

void main(void){
    uint32_t buf = 0;
    uint16_t temp_last = 0;
    uint8_t task_lcd = 0;
    uint8_t control = 0;

    ADC_Init();
    IO_Config();
    LCD_Config();

    delay_ms(250);
    lcd_clear();

    while(1){
        buf = read_adc(TEMP_CH);
        oven.temp = (buf * 500) >> 10 ;  // mV = (Dn *5000) / 1024 , temp = mV / 10;

        control = Controller_OnOff(oven.temp, oven.sp, oven.hys);

        switch(control){
            case CTRL_ONOFF_LOW:
                WRITE_BIT(RLY_PORT, RLY_BIT, RLY_ACTIVATE);
                break;
            case CTRL_ONOFF_HIGH:
                WRITE_BIT(RLY_PORT, RLY_BIT, !RLY_ACTIVATE);
                break;
        }

//        if(control == 1){
//            WRITE_BIT(RLY_PORT, RLY_BIT, RLY_ACTIVATE);
//        }
//        else if (control == 2){
//            WRITE_BIT(RLY_PORT, RLY_BIT, !RLY_ACTIVATE);
//        }

        if(oven.temp != temp_last){
            temp_last = oven.temp;
            task_lcd = 1;
        }

        if(task_lcd){
            task_lcd =0;
            LCD_Display();
        }

        //delay_ms(500); task_lcd = 1;
    }
}

//******************************************
void LCD_Display(void){
    char txt[];
    uint16_t buf = 0;
    uint16_t half = oven.hys >> 1;

    lcd_gotoxy(0,0); lcd_putsf("Min SP  Max  PV");

    buf = oven.sp - half;
    itoa(buf, txt);
    lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("  ");

    itoa(oven.sp, txt);
    lcd_gotoxy(4,1); lcd_puts(txt); lcd_putsf("  ");

    buf = oven.sp + half;
    itoa(buf, txt);
    lcd_gotoxy(8,1); lcd_puts(txt); lcd_putsf("  ");

    itoa(oven.temp, txt);
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
