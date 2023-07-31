// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif
    
#ifndef _INCLUDED_TIMER0
    #define _INCLUDED_TIMER0
   
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
    #define SetOperationModeFromTimer2(MODE)            TCCR2=(TCCR2 & 0b10110111) | MODE; 
    #define SetAsynchronStatusFromTimer2(STATUS)        if(STATUS){SETBIT(ASSR,AS2);} else{CLRBIT(ASSR,AS2);}
    #define SetClockSourceFromTimer2(MODE)              TCCR2=(TCCR2 & 0b11111000) | MODE; 
    #define SetCompareOutputModeFromTimer2(MODE)        TCCR2=(TCCR2 & 0b11001111) | (MODE<<4);
    #define SetTimerValueFromTimer2(VALUE)              TCNT2=VALUE;
    #define SetCompareOutputValueFromTimer2(VALUE)      OCR2=VALUE;
    #define EnableOverflowInterruptFromTimer2(STATUS)   if(STATUS){SETBIT(TIMSK,TOIE2);} else{CLRBIT(TIMSK,TOIE2);}
    #define EnableCompareInterruptFromTimer2(STATUS)    if(STATUS){SETBIT(TIMSK,OCIE2);} else{CLRBIT(TIMSK,OCIE2);}
    
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
void ConfigTimer2ForTimer(void){
    SetOperationModeFromTimer2(T2_NORMAL);
    SetAsynchronStatusFromTimer2(0);
    SetClockSourceFromTimer2(T2CLK_P1024);
    SetCompareOutputModeFromTimer2(T2_DISCONNECT);
    SetTimerValueFromTimer2(0);
    SetCompareOutputValueFromTimer2(0);
    EnableOverflowInterruptFromTimer2(1);
    EnableCompareInterruptFromTimer2(0);
    
    EnableGlobalInterrupt(1);
}

//**************************************
void ConfigTimer2ForAsyncTimer(void){
    SetOperationModeFromTimer2(T2_NORMAL);
    SetAsynchronStatusFromTimer2(1);
    SetClockSourceFromTimer2(T2CLK_P128);
    SetCompareOutputModeFromTimer2(T2_DISCONNECT);
    SetTimerValueFromTimer2(0);
    SetCompareOutputValueFromTimer2(0);
    EnableOverflowInterruptFromTimer2(1);
    EnableCompareInterruptFromTimer2(0);
    
    EnableGlobalInterrupt(1);
}

//**********************************
void ConfigTimer2ForPWM(void){
    DDRD.7=1; PORTD.7=0;  
    
    SetOperationModeFromTimer2(T2_FAST_PWM);
    SetAsynchronStatusFromTimer2(0);
    SetClockSourceFromTimer2(T2CLK_P1);
    SetCompareOutputModeFromTimer2(T2_NONINVERTED);
    SetTimerValueFromTimer2(0);
    SetCompareOutputValueFromTimer2(0);
    EnableOverflowInterruptFromTimer2(0);
    EnableCompareInterruptFromTimer2(0);
    
    EnableGlobalInterrupt(0);
}

//**********************************
void ConfigTimer2ForCTC(void){
    DDRD.7=1; PORTD.7=0;
    
    SetOperationModeFromTimer2(T2_CTC);
    SetAsynchronStatusFromTimer2(0);
    SetClockSourceFromTimer2(T2CLK_P1);
    SetCompareOutputModeFromTimer2(T2_TOGGLE);
    SetTimerValueFromTimer2(0);
    SetCompareOutputValueFromTimer2(0);
    EnableOverflowInterruptFromTimer2(0);
    EnableCompareInterruptFromTimer2(0);
    
    EnableGlobalInterrupt(0);
}

#pragma used-    
#endif
