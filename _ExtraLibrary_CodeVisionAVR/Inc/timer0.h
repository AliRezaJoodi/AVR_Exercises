// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif
    
#ifndef _TIMER0_INCLUDED
    #define _TIMER0_INCLUDED
    
// Operation Mode
#define T0_NORMAL               (0<<WGM01) | (0<<WGM00)
#define T0_PHASE_CORRECT_PWM    (0<<WGM01) | (1<<WGM00)
#define T0_CTC                  (1<<WGM01) | (0<<WGM00)
#define T0_FAST_PWM             (1<<WGM01) | (1<<WGM00)
#define SetOperationModeFromTimer0(MODE) \
    TCCR0=(TCCR0 & 0b10110111) | MODE;
    
// Clock Source Selections
#define T0CLK_STOP          0b000 
#define T0CLK_P1            0b001 
#define T0CLK_P8            0b010 
#define T0CLK_P64           0b011 
#define T0CLK_P256          0b100 
#define T0CLK_P1024         0b101 
#define T0PIN_FALLING_EDGE  0b110
#define T0PIN_RISING_EDGE   0b111
#define SetClockSourceFromTimer0(MODE) \
    TCCR0=(TCCR0 & 0b11111000) | MODE; 
    
// Compare Output Mode
#define T0_DISCONNECT       0b00
#define T0_TOGGLE           0b01
#define T0_NONINVERTED      0b10
#define T0_INVERTED         0b11
#define SetCompareOutputModeFromTimer0(MODE) \
    TCCR0=(TCCR0 & 0b11001111) | (MODE<<4);
    
#define Timer0_SetTimerValue(VALUE)              TCNT0=VALUE;
#define Timer0_SetCompareOutputValue(VALUE)      OCR0=VALUE;
#define Timer0_EnableOverflowInterrupt(STATUS)   if(STATUS){SetBit(TIMSK,TOIE0);} else{ClearBit(TIMSK,TOIE0);}
#define Timer0_EnableCompareInterrupt(STATUS)    if(STATUS){SetBit(TIMSK,OCIE0);} else{ClearBit(TIMSK,OCIE0);}
    
char task_t0_ovf=0;
char task_t0_comp=0;
    
#pragma used+

//******************************
interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    task_t0_ovf=1; 
}

//**************************************
interrupt [TIM0_COMP] void timer0_comp_isr(void){
    task_t0_comp=1;
}
    
//**************************************
void Timer0_ConfigForTimer(void){
    SetOperationModeFromTimer0(T0_NORMAL);
    SetClockSourceFromTimer0(T0CLK_P1024);
    SetCompareOutputModeFromTimer0(T0_DISCONNECT);
    Timer0_SetTimerValue(0);
    Timer0_SetCompareOutputValue(0);
    Timer0_EnableOverflowInterrupt(1);
    Timer0_EnableCompareInterrupt(0); 
    
    EnableGlobalInterrupt(1);
}

//**************************************
void Timer0_ConfigForCounter(void){
    SetOperationModeFromTimer0(T0_NORMAL);
    SetClockSourceFromTimer0(T0PIN_RISING_EDGE);
    SetCompareOutputModeFromTimer0(T0_DISCONNECT); 
    Timer0_SetTimerValue(0);
    Timer0_SetCompareOutputValue(0);
    Timer0_EnableOverflowInterrupt(1);
    Timer0_EnableCompareInterrupt(0); 
    
    EnableGlobalInterrupt(1);
}

//**********************************
void Timer0_ConfigForPWM(void){
    DDRB.3=1;  
    
    SetOperationModeFromTimer0(T0_FAST_PWM);
    SetClockSourceFromTimer0(T0CLK_P1);
    SetCompareOutputModeFromTimer0(T0_NONINVERTED); 
    Timer0_SetTimerValue(0);
    Timer0_SetCompareOutputValue(0);
    Timer0_EnableOverflowInterrupt(0);
    Timer0_EnableCompareInterrupt(0); 
    
    EnableGlobalInterrupt(0);
}

//**********************************
void Timer0_ConfigForCTC(void){
    DDRB.3=1; PORTB.3=0;

    SetOperationModeFromTimer0(T0_CTC);
    SetClockSourceFromTimer0(T0CLK_P8); 
    SetCompareOutputModeFromTimer0(T0_TOGGLE);
    Timer0_SetTimerValue(0);
    Timer0_SetCompareOutputValue(0);
    Timer0_EnableOverflowInterrupt(0);
    Timer0_EnableCompareInterrupt(0); 
    
    EnableGlobalInterrupt(0);
}

#pragma used-    
#endif
