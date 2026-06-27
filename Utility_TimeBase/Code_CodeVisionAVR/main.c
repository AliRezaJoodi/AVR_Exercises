// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega16a.h>
#include <delay.h>

#include "hardware.h"
#include "aj_timebase.h"

void Timer2_Init(void);

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    TCNT2=0x06; // Reinitialize Timer2 value

    AJ_TimeBase_CountTicks();
}

void main(void){
    aj_timebase_t tick_last = 0;
    aj_timebase_t tick_now = 0;

    Timer2_Init();
    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (1<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

    #asm("sei") // Globally enable interrupts

    DDRD.3 = 1; PORTD.3 = 0;
    tick_last = AJ_TimeBase_GetTicks();

    while(1){
        tick_now = AJ_TimeBase_GetTicks();

        if (AJ_TimeBase_HasElapsed(tick_now, tick_last, 500)){
            tick_last = tick_now;
            PORTD.3 = !PORTD.3;
        }
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



