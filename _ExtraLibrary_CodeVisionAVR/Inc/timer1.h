// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif
    
#ifndef _TIMER1_INCLUDED
    #define _TIMER1_INCLUDED
    
    // Operation Mode 
    #define T1_NORMAL                       0b0000
    #define T1_PWM_PHASE_8BIT               0b0001
    #define T1_PWM_PHASE_9BIT               0b0010
    #define T1_PWM_PHASE_10BIT              0b0011
    #define T1_CTC_OCR1A                    0b0100
    #define T1_FAST_PWM_8BIT                0b0101
    #define T1_FAST_PWM_9BIT                0b0110
    #define T1_FAST_PWM_10BIT               0b0111
    #define T1_PWM_PHASE_FREQUENCY_ICR1     0b1000
    #define T1_PWM_PHASE_FREQUENCY_OCR1A    0b1001
    #define T1_PWM_PHASE_ICR1               0b1010
    #define T1_PWM_PHASE_OCR1A              0b1011
    #define T1_CTC_ICR1                     0b1100
    #define T1_RESERVED                     0b1101
    #define T1_FAST_PWM_ICR1                0b1110
    #define T1_FAST_PWM_OCR1A               0b1111
    
    // Clock Source Selections
    #define T1CLK_STOP                      0b000 
    #define T1CLK_P1                        0b001 
    #define T1CLK_P8                        0b010 
    #define T1CLK_P64                       0b011 
    #define T1CLK_P256                      0b100 
    #define T1CLK_P1024                     0b101 
    #define T1PIN_FALLING_EDGE              0b110
    #define T1PIN_RISING_EDGE               0b111
    
    // Compare Output Mode
    #define T1_DISCONNECT                   0b00
    #define T1_TOGGLE                       0b01
    #define T1_NONINVERTED                  0b10
    #define T1_INVERTED                     0b11
    
    // Input Capture Edge Select on the ICP1 Pin
    #define ICP1PIN_FALLING_EDGE            (0<<ICES1)
    #define ICP1PIN_RISING_EDGE             (1<<ICES1)
    
    // Commands  
    #define Timer1_SetOperationMode(MODE)                    TCCR1A=(TCCR1A & 0b11111100) | (MODE & 0b0011); \
                                                             TCCR1B=(TCCR1B & 0b11100111) | ((MODE & 0b1100)<<1);
    #define Timer1_SetClockSource(MODE)                      TCCR1B=(TCCR1B & 0b11111000) | MODE;
    #define Timer1_SetCompare1AOutputMode(MODE)              TCCR1A=(TCCR1A & 0b00111111) | (MODE<<6);
    #define Timer1_SetCompare1BOutputMode(MODE)              TCCR1A=(TCCR1A & 0b11001111) | (MODE<<4);
    #define Timer1_EnableInputCaptureNoiseCanceler(STATUS)   if(STATUS){SetBit(TCCR1B,ICNC1);} else{ClearBit(TCCR1B,ICNC1);}
    #define Timer1_SetInputCaptureEdgeSelect(MODE)           TCCR1B=(TCCR1B & 0b10111111) | MODE;
    #define Timer1_SetTimerValue(VALUE)                      TCNT1H=GetMsb(VALUE); TCNT1L=GetLsb(VALUE);  
    #define Timer1_SetCompareAValue(VALUE)                   OCR1AH=GetMsb(VALUE); OCR1AL=GetLsb(VALUE);
    #define Timer1_SetCompareBValue(VALUE)                   OCR1BH=GetMsb(VALUE); OCR1BL=GetLsb(VALUE);
    #define Timer1_SetInputCaptureValue(VALUE)               ICR1H=GetMsb(VALUE); ICR1L=GetLsb(VALUE);
    #define Timer1_EnableOverflowInterrupt(STATUS)           if(STATUS){SetBit(TIMSK,TOIE1);} else{ClearBit(TIMSK,TOIE1);}
    #define Timer1_EnableCompareAInterrupt(STATUS)           if(STATUS){SetBit(TIMSK,OCIE1A);} else{ClearBit(TIMSK,OCIE1A);}
    #define Timer1_EnableCompareBInterrupt(STATUS)           if(STATUS){SetBit(TIMSK,OCIE1B);} else{ClearBit(TIMSK,OCIE1B);}
    #define Timer1_EnableInputCaptureInterrupt(STATUS)       if(STATUS){SetBit(TIMSK,TICIE1);} else{ClearBit(TIMSK,TICIE1);}
        
    char task_t1_ovf=0;
    char task_t1_compa=0;
    char task_t1_compb=0;
    char task_t1_capture=0;
    
#pragma used+

//**************************************
interrupt [TIM1_OVF] void timer1_ovf_isr(void){
    task_t1_ovf=1; 
}

//**************************************
interrupt [TIM1_COMPA] void timer1_compa_isr(void){
    task_t1_compa=1;
}

//**************************************
interrupt [TIM1_COMPB] void timer1_compb_isr(void){
    task_t1_compb=1;
}

//**************************************
interrupt [TIM1_CAPT] void timer1_capt_isr(void){
    task_t1_capture=1;
}
    
//**************************************
void Timer1_ConfigForTimer(void){
    Timer1_SetOperationMode(T1_NORMAL);
    Timer1_SetClockSource(T1CLK_P8);
    Timer1_SetCompare1AOutputMode(T1_DISCONNECT);
    Timer1_SetCompare1BOutputMode(T1_DISCONNECT); 
    Timer1_EnableInputCaptureNoiseCanceler(0);
    Timer1_SetInputCaptureEdgeSelect(ICP1PIN_FALLING_EDGE);
    Timer1_SetTimerValue(0);
    Timer1_SetCompareAValue(0);
    Timer1_SetCompareBValue(0);  
    Timer1_SetInputCaptureValue(0);
    Timer1_EnableOverflowInterrupt(1); 
    Timer1_EnableCompareAInterrupt(0);
    Timer1_EnableCompareBInterrupt(0);
    Timer1_EnableInputCaptureInterrupt(0); 
    
    EnableGlobalInterrupt(1);
}

//**************************************
void Timer1_ConfigForCounter(void){
    Timer1_SetOperationMode(T1_NORMAL);
    Timer1_SetClockSource(T1PIN_RISING_EDGE);
    Timer1_SetCompare1AOutputMode(T1_DISCONNECT);
    Timer1_SetCompare1BOutputMode(T1_DISCONNECT); 
    Timer1_EnableInputCaptureNoiseCanceler(0);
    Timer1_SetInputCaptureEdgeSelect(ICP1PIN_FALLING_EDGE);
    Timer1_SetTimerValue(0);
    Timer1_SetCompareAValue(0);
    Timer1_SetCompareBValue(0);  
    Timer1_SetInputCaptureValue(0);
    Timer1_EnableOverflowInterrupt(1); 
    Timer1_EnableCompareAInterrupt(0);
    Timer1_EnableCompareBInterrupt(0);
    Timer1_EnableInputCaptureInterrupt(0); 
    
    EnableGlobalInterrupt(1);
}

//**********************************
void Timer1_ConfigForPWM(void){
    DDRD.4=1;
    DDRD.5=1;

    Timer1_SetOperationMode(T1_FAST_PWM_10BIT);
    Timer1_SetClockSource(T1CLK_P8);
    Timer1_SetCompare1AOutputMode(T1_NONINVERTED);
    Timer1_SetCompare1BOutputMode(T1_INVERTED); 
    Timer1_EnableInputCaptureNoiseCanceler(0);
    Timer1_SetInputCaptureEdgeSelect(ICP1PIN_FALLING_EDGE);
    Timer1_SetTimerValue(0);
    Timer1_SetCompareAValue(100);
    Timer1_SetCompareBValue(100);  
    Timer1_SetInputCaptureValue(0);
    Timer1_EnableOverflowInterrupt(1); 
    Timer1_EnableCompareAInterrupt(0);
    Timer1_EnableCompareBInterrupt(0);
    Timer1_EnableInputCaptureInterrupt(0); 
    
    EnableGlobalInterrupt(0);
}

//**********************************
void Timer1_ConfigForCTC(void){
    DDRD.4=1;
    DDRD.5=1;

    Timer1_SetOperationMode(T1_CTC_OCR1A);
    Timer1_SetClockSource(T1CLK_P8);
    Timer1_SetCompare1AOutputMode(T1_TOGGLE);
    Timer1_SetCompare1BOutputMode(T1_DISCONNECT); 
    Timer1_EnableInputCaptureNoiseCanceler(0);
    Timer1_SetInputCaptureEdgeSelect(ICP1PIN_FALLING_EDGE);
    Timer1_SetTimerValue(0);
    Timer1_SetCompareAValue(0);
    Timer1_SetCompareBValue(0);  
    Timer1_SetInputCaptureValue(0);
    Timer1_EnableOverflowInterrupt(0); 
    Timer1_EnableCompareAInterrupt(0);
    Timer1_EnableCompareBInterrupt(0);
    Timer1_EnableInputCaptureInterrupt(0); 
    
    EnableGlobalInterrupt(0);
}

#pragma used-    
#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    