// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <stdlib.h>
#include <delay.h>
#include <alcd.h>

#include "hardware.h"
#include "modules/controller_pid.h"

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

uint8_t pid_flog = 0;

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

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    TCNT0=0x06;
    pid_flog = 1;
}

void ADC_Init(void);
void LCD_Config(void);
void LCD_DisplayMainPage(const CtrlPID_t *params, int16_t pwm);
void Timer0_Init(void);
void Timer1_Init(void);

void main(void){
    CtrlPID_t oven = {
        .kp = PID_FLOAT_TO_Q(4.547, PID_SCALE), // 1023 / error
        .ki = PID_FLOAT_TO_Q(0.01, PID_SCALE),
        .kd = PID_FLOAT_TO_Q(0.4547, PID_SCALE), // kp / 10

        .output_min = 0,
        .output_max = 1023,
        .scale = PID_SCALE,
        .dt = PID_DT_32MS,

        .i_sum = 0,
        .error_last = 0,

        .sp = 250,
        .pv = 0
    };

    int32_t buf = 0;
    int32_t buf_last = 0;
    uint8_t lcd_flog = 0;
    int16_t out = 0;

    ADC_Init();
    LCD_Config();
    Timer1_Init();
    Timer0_Init();

    delay_ms(250);
    lcd_clear();
    Ctrl_PID_Reset(&oven);
    #asm("sei") // Globally enable interrupts

    while(1){
        buf = read_adc(TEMP_CH);
        if(buf != buf_last){
            buf_last = buf;
            oven.pv = (buf * 500) >> 10 ;  // mV = (Dn *5000) / 1024 , temp = mV / 10;
            lcd_flog = 1;
        }

        if (pid_flog){
            pid_flog = 0;
            out = (uint16_t)Ctrl_PID_Update(&oven);
            OCR1A = out;
        }

        if(lcd_flog){
            lcd_flog = 0;
            LCD_DisplayMainPage(&oven, out);
        }
    }
}

//******************************************
void LCD_DisplayMainPage(const CtrlPID_t *params, int16_t pwm){
    char txt[6];

    lcd_gotoxy(0,0); lcd_putsf("SP  PV  PWM");

    ltoa(params->sp, txt);
    lcd_gotoxy(0,1); lcd_puts(txt); lcd_putsf("  ");

    ltoa(params->pv, txt);
    lcd_gotoxy(4,1); lcd_puts(txt); lcd_putsf("  ");

    itoa(pwm, txt);
    lcd_gotoxy(8,1); lcd_puts(txt); lcd_putsf("  ");
}

//********************************************************
void Timer1_Init(void){
    DDRD.4=1; PORTD.4=0;
    DDRD.5=1; PORTD.5=0;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: 125.000 kHz
    // Mode: Ph. correct PWM top=0x03FF
    // OC1A output: Non-Inverted PWM
    // OC1B output: Inverted PWM
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer Period: 16.368 ms
    // Output Pulse(s):
    // OC1A Period: 16.368 ms Width: 0 us
    // OC1B Period: 16.368 ms Width: 16.368 ms
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (1<<WGM10);
    TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;
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

//**********************************************
void Timer0_Init(void){
    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: 7.813 kHz
    // Mode: Normal top=0xFF
    // OC0 output: Disconnected
    // Timer Period: 32 ms
    TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
    TCNT0=0x06;
    OCR0=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
}

