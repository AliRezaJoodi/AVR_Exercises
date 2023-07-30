// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef ENABLE_GLOBAL_INTERRUPT
    #define ENABLE_GLOBAL_INTERRUPT(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif
    
#ifndef _INCLUDED_TIMER0
    #define _INCLUDED_TIMER0
    
    // Waveform Generation Mode
    #define T0_NORMAL                       (0<<WGM01) | (0<<WGM00)
    #define T0_PHASE_CORRECT_PWM            (0<<WGM01) | (1<<WGM00)
    #define T0_CTC                          (1<<WGM01) | (0<<WGM00)
    #define T0_FAST_PWM                     (1<<WGM01) | (1<<WGM00)
    
    // Clock Source Selections
    #define T0CLK_STOP                      0b000 
    #define T0CLK_P1                        0b001 
    #define T0CLK_P8                        0b010 
    #define T0CLK_P64                       0b011 
    #define T0CLK_P256                      0b100 
    #define T0CLK_P1024                     0b101 
    #define T0PIN_FALLING_EDGE              0b110
    #define T0PIN_RISING_EDGE               0b111
    
    // PWM Output Mode
    #define T0_DISCONNECT                   0b00
    #define T0_NONINVERTED                  0b10
    #define T0_INVERTED                     0b11
    
    // Commands
    #define SET_TIMER0_OPERATIONMODE(MODE)  TCCR0=(TCCR0 & 0b10110111) | MODE;
    #define SET_TIMER0_CLOCKSOURCE(MODE)    TCCR0=(TCCR0 & 0b11111000) | MODE; 
    #define SET_TIMER0_TCNT0VALUE(VALUE)    TCNT0=VALUE;
    #define SET_TIMER0_OC0PIN(MODE)         TCCR0=(TCCR0 & 0b11001111) | (MODE<<4);
    #define SET_TIMER0_OCR0VALUE(VALUE)     OCR0=VALUE;
    #define ENABLE_TIMER0_INT_OVF(STATUS)   if(STATUS){SETBIT(TIMSK,TOIE0);} else{CLRBIT(TIMSK,TOIE0);}
    #define ENABLE_TIMER0_INT_COMP(STATUS)  if(STATUS){SETBIT(TIMSK,OCIE0);} else{CLRBIT(TIMSK,OCIE0);}
    
    // Commands: Different type
    #define SetOperationModeFromTimer0(MODE)            TCCR0=(TCCR0 & 0b10110111) | MODE; 
    #define SetClockSourceFromTimer0(MODE)              TCCR0=(TCCR0 & 0b11111000) | MODE; 
    #define SetTimerValueFromTimer0(VALUE)              TCNT0=VALUE;     
    #define SetPwmOutputModeFromTimer0(MODE)            TCCR0=(TCCR0 & 0b11001111) | (MODE<<4);
    #define SetCompareValueFromTimer0(VALUE)            OCR0=VALUE;
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
    SetTimerValueFromTimer0(0);
    SetPwmOutputModeFromTimer0(T0_DISCONNECT);
    SetCompareValueFromTimer0(0);
    EnableOverflowInterruptFromTimer0(1);
    EnableCompareInterruptFromTimer0(0); 
    
    ENABLE_GLOBAL_INTERRUPT(1);
}

//**************************************
void ConfigTimer0ForCounter(void){
// Timer/Counter 0 initialization
// Clock source: T0 pin Rising Edge
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (1<<CS01) | (1<<CS00);
SetTimerValueFromTimer0(0);
SetCompareValueFromTimer0(0);

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<OCIE0) | (1<<TOIE0);
}

//**********************************
void ConfigTimer0ForPWM(void){
    DDRB.3=1; PORTB.3=0;  
    
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Fast PWM top=0xFF
// OC0 output: Non-Inverted PWM
// Timer Period: 0.032 ms
// Output Pulse(s):
// OC0 Period: 0.032 ms Width: 0 us
TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
SetTimerValueFromTimer0(0);
SetCompareValueFromTimer0(0);
}

//**********************************
void ConfigTimer0ForCTC(void){
    DDRB.3=1; PORTB.3=0;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: CTC top=OCR0
// OC0 output: Toggle on compare match
// Timer Period: 1 us
// Output Pulse(s):
// OC0 Period: 2 us Width: 1 us
TCCR0=(0<<WGM00) | (0<<COM01) | (1<<COM00) | (1<<WGM01) | (0<<CS02) | (1<<CS01) | (0<<CS00);
SetTimerValueFromTimer0(0);
SetCompareValueFromTimer0(0);
}

#pragma used-    
#endif
