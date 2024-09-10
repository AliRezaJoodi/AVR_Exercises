// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif
    
#ifndef _TIMER2_INCLUDED
    #define _TIMER2_INCLUDED
   
    // Operation Mode
    #define T2_NORMAL                           (0<<WGM21) | (0<<WGM20)
    #define T2_PHASE_CORRECT_PWM                (0<<WGM21) | (1<<WGM20)
    #define T2_CTC                              (1<<WGM21) | (0<<WGM20)
    #define T2_FAST_PWM                         (1<<WGM21) | (1<<WGM20)
    
    // Clock Source Selections
    #define T2CLK_STOP                          0b000 
    #define T2CLK_P1                            0b001 
    #define T2CLK_P8                            0b010 
    #define T2CLK_P32                           0b011 
    #define T2CLK_P64                           0b100 
    #define T2CLK_P128                          0b101 
    #define T2CLK_P256                          0b110
    #define T2CLK_P1024                         0b111
    
    // Compare Output Mode
    #define T2_DISCONNECT                       0b00
    #define T2_TOGGLE                           0b01
    #define T2_NONINVERTED                      0b10
    #define T2_INVERTED                         0b11
    
    // Commands
    #define Timer2_SetOperationMode(MODE)            TCCR2=(TCCR2 & 0b10110111) | MODE; 
    #define Timer2_EnableAsynchronStatus(STATUS)     if(STATUS){SetBit(ASSR,AS2);} else{ClearBit(ASSR,AS2);}
    #define Timer2_SetClockSource(MODE)              TCCR2=(TCCR2 & 0b11111000) | MODE; 
    #define Timer2_SetCompareOutputMode(MODE)        TCCR2=(TCCR2 & 0b11001111) | (MODE<<4);
    #define Timer2_SetTimerValueFrom(VALUE)              TCNT2=VALUE;
    #define Timer2_SetCompareOutputValue(VALUE)      OCR2=VALUE;
    #define Timer2_EnableOverflowInterrupt(STATUS)   if(STATUS){SetBit(TIMSK,TOIE2);} else{ClearBit(TIMSK,TOIE2);}
    #define Timer2_EnableCompareInterrupt(STATUS)    if(STATUS){SetBit(TIMSK,OCIE2);} else{ClearBit(TIMSK,OCIE2);}
    
    char task_t2_ovf=0;
    char task_t2_comp=0;
    
#pragma used+

//**************************************
interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    task_t2_ovf=1; 
}

//**************************************
interrupt [TIM2_COMP] void timer2_comp_isr(void){
    task_t2_comp=1;
}
    
//**************************************
void Timer2_ConfigForTimer(void){
    Timer2_SetOperationMode(T2_NORMAL);
    Timer2_EnableAsynchronStatus(0);
    Timer2_SetClockSource(T2CLK_P1024);
    Timer2_SetCompareOutputMode(T2_DISCONNECT);
    Timer2_SetTimerValueFrom(0);
    Timer2_SetCompareOutputValue(0);
    Timer2_EnableOverflowInterrupt(1);
    Timer2_EnableCompareInterrupt(0);
    
    EnableGlobalInterrupt(1);
}

//**************************************
void Timer2_ConfigForAsyncTimer(void){
    Timer2_SetOperationMode(T2_NORMAL);
    Timer2_EnableAsynchronStatus(1);
    Timer2_SetClockSource(T2CLK_P128);
    Timer2_SetCompareOutputMode(T2_DISCONNECT);
    Timer2_SetTimerValueFrom(0);
    Timer2_SetCompareOutputValue(0);
    Timer2_EnableOverflowInterrupt(1);
    Timer2_EnableCompareInterrupt(0);
    
    EnableGlobalInterrupt(1);
}

//**********************************
void Timer2_ConfigForPWM(void){
    DDRD.7=1; PORTD.7=0;  
    
    Timer2_SetOperationMode(T2_FAST_PWM);
    Timer2_EnableAsynchronStatus(0);
    Timer2_SetClockSource(T2CLK_P1);
    Timer2_SetCompareOutputMode(T2_NONINVERTED);
    Timer2_SetTimerValueFrom(0);
    Timer2_SetCompareOutputValue(0);
    Timer2_EnableOverflowInterrupt(0);
    Timer2_EnableCompareInterrupt(0);
    
    EnableGlobalInterrupt(0);
}

//**********************************
void Timer2_ConfigForCTC(void){
    DDRD.7=1; PORTD.7=0;
    
    Timer2_SetOperationMode(T2_CTC);
    Timer2_EnableAsynchronStatus(0);
    Timer2_SetClockSource(T2CLK_P1);
    Timer2_SetCompareOutputMode(T2_TOGGLE);
    Timer2_SetTimerValueFrom(0);
    Timer2_SetCompareOutputValue(0);
    Timer2_EnableOverflowInterrupt(0);
    Timer2_EnableCompareInterrupt(0);
    
    EnableGlobalInterrupt(0);
}

#pragma used-    
#endif
