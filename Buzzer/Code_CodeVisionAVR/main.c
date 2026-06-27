// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega16a.h>
#include <delay.h>

#include "hardware.h"
#include "aj_buzzer.h"

volatile uint8_t system_tick = 0U;

void Timer2_Init(void);

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    TCNT2=0x06; // Reinitialize Timer2 value

    system_tick ++;
}

void main(void){
    AJ_Buzzer_Init();

    Timer2_Init();
    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (1<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

    #asm("sei") // Globally enable interrupts

    AJ_Buzzer_Start(system_tick, AJ_BUZZER_COUNT2);

    while(1){
        AJ_Buzzer_Refresh(system_tick);
    }
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



