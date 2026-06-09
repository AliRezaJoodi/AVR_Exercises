// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>

#include <mega32a.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include "hardware.h"
#include "aj_timebase.h"
#include "aj_button.h"

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);
void Timer2_Init(void);

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    TCNT2=0x06; // Reinitialize Timer2 value

    AJ_TimeBase_CountTicks();
}

void main(void){
    uint8_t tick_now = 0;
    uint8_t value = 100;
    uint8_t value_last = 0;

    aj_button_t buttonIncr = {
        .hw = {
            .ddr   = &AJ_BUTTON_DDR,
            .port  = &AJ_BUTTON_PORT,
            .pin   = &AJ_BUTTON_PIN,
            //.index = AJ_BUTTON_POS,
            .mask  = AJ_BUTTON_MASK
        },
        .config = {
            .pressed = AJ_BUTTON_ACTIVE_LOW,
            .pull    = AJ_BUTTON_PULL_NONE
        },
        .tick_last = 0,
        .state   = 0
    };

    aj_button_t buttonDecr = {
        .hw = {
            .ddr   = &AJ_BUTTON2_DDR,
            .port  = &AJ_BUTTON2_PORT,
            .pin   = &AJ_BUTTON2_PIN,
            //.index = AJ_BUTTON2_POS,
            .mask  = AJ_BUTTON2_MASK
        },
        .config = {
            .pressed = AJ_BUTTON_ACTIVE_LOW,
            .pull    = AJ_BUTTON_PULL_UP
        },
        .tick_last = 0,
        .state   = 0
    };

    aj_button_t buttonClear = {
        .hw = {
            .ddr   = &AJ_BUTTON3_DDR,
            .port  = &AJ_BUTTON3_PORT,
            .pin   = &AJ_BUTTON3_PIN,
            //.index = AJ_BUTTON3_POS,
            .mask  = AJ_BUTTON3_MASK
        },
        .config = {
            .pressed = AJ_BUTTON_ACTIVE_HIGH,
            .pull    = AJ_BUTTON_PULL_NONE
        },
        .tick_last = 0,
        .state   = 0
    };

    AJ_Button_Init(&buttonIncr);
    AJ_Button_Init(&buttonDecr);
    AJ_Button_Init(&buttonClear);

    LCD_Config();
    LCD_DisplayMainPage(value);

    Timer2_Init();
    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (1<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

    #asm("sei") // Globally enable interrupts

    while(1){
        tick_now = AJ_TimeBase_GetTicks();

        if( AJ_Button_GetAutoRepeat(&buttonIncr, tick_now) ){
            value++;
        }

        if( AJ_Button_GetTrigger(&buttonDecr, tick_now) ){
            value--;
        }

        if( AJ_Button_GetTrigger(&buttonClear, tick_now) ){
            value = 0;
        }

        if( value_last != value ){
            value_last = value;
            LCD_DisplayMainPage(value);
        }
    };
}

//********************************************************
void Timer2_Init(void){
    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: 250.000 kHz
    // Mode: Normal top=0xFF
    // OC2 output: Disconnected
    // Timer Period: 1 ms
    ASSR=0<<AS2;
    TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (1<<CS21) | (1<<CS20);
    TCNT2=0x06;
    OCR2=0x00;
}

//********************************************************
void LCD_DisplayMainPage(unsigned char value){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();
}




