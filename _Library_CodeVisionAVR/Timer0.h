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
    
#define SetTimerValueFromTimer0(VALUE)              TCNT0=VALUE;
#define SetCompareOutputValueFromTimer0(VALUE)      OCR0=VALUE;
#define EnableOverflowInterruptFromTimer0(STATUS)   if(STATUS){SETBIT(TIMSK,TOIE0);} else{CLRBIT(TIMSK,TOIE0);}
#define EnableCompareInterruptFromTimer0(STATUS)    if(STATUS){SETBIT(TIMSK,OCIE0);} else{CLRBIT(TIMSK,OCIE0);}
    
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
void ConfigTimer0ForTimer(void){
    SetOperationModeFromTimer0(T0_NORMAL);
    SetClockSourceFromTimer0(T0CLK_P1024);
    SetCompareOutputModeFromTimer0(T0_DISCONNECT);
    SetTimerValueFromTimer0(0);
    SetCompareOutputValueFromTimer0(0);
    EnableOverflowInterruptFromTimer0(1);
    EnableCompareInterruptFromTimer0(0); 
    
    EnableGlobalInterrupt(1);
}

//**************************************
void ConfigTimer0ForCounter(void){
    SetOperationModeFromTimer0(T0_NORMAL);
    SetClockSourceFromTimer0(T0PIN_RISING_EDGE);
    SetCompareOutputModeFromTimer0(T0_DISCONNECT); 
    SetTimerValueFromTimer0(0);
    SetCompareOutputValueFromTimer0(0);
    EnableOverflowInterruptFromTimer0(1);
    EnableCompareInterruptFromTimer0(0); 
    
    EnableGlobalInterrupt(1);
}

//**********************************
void ConfigTimer0ForPWM(void){
    DDRB.3=1;  
    
    SetOperationModeFromTimer0(T0_FAST_PWM);
    SetClockSourceFromTimer0(T0CLK_P1);
    SetCompareOutputModeFromTimer0(T0_NONINVERTED); 
    SetTimerValueFromTimer0(0);
    SetCompareOutputValueFromTimer0(0);
    EnableOverflowInterruptFromTimer0(0);
    EnableCompareInterruptFromTimer0(0); 
    
    EnableGlobalInterrupt(0);
}

//**********************************
void ConfigTimer0ForCTC(void){
    DDRB.3=1; PORTB.3=0;

    SetOperationModeFromTimer0(T0_CTC);
    SetClockSourceFromTimer0(T0CLK_P8); 
    SetCompareOutputModeFromTimer0(T0_TOGGLE);
    SetTimerValueFromTimer0(0);
    SetCompareOutputValueFromTimer0(0);
    EnableOverflowInterruptFromTimer0(0);
    EnableCompareInterruptFromTimer0(0); 
    
    EnableGlobalInterrupt(0);
}

#pragma used-    
#endif
