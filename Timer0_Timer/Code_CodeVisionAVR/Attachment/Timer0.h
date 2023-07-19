
#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

    
#ifndef _INCLUDED_TIMER0
    #define _INCLUDED_TIMER0

    #define T0_CLOCK_STOP                   TCCR0=(TCCR0 & 0b11111000) | 0b000; 
    #define T0_CLOCK_P1                     TCCR0=(TCCR0 & 0b11111000) | 0b001; 
    #define T0_CLOCK_P8                     TCCR0=(TCCR0 & 0b11111000) | 0b010; 
    #define T0_CLOCK_P64                    TCCR0=(TCCR0 & 0b11111000) | 0b011; 
    #define T0_CLOCK_P256                   TCCR0=(TCCR0 & 0b11111000) | 0b100; 
    #define T0_CLOCK_P1024                  TCCR0=(TCCR0 & 0b11111000) | 0b101; 
    #define T0_CLOCK_EXTERNAL_FALLING       TCCR0=(TCCR0 & 0b11111000) | 0b110;  
    #define T0_CLOCK_EXTERNAL_RISING        TCCR0=(TCCR0 & 0b11111000) | 0b111;
    #define T0_INT_ENABLE                   SETBIT(TIMSK,TOIE0);
    #define T0_INT_DISABLE                  CLRBIT(TIMSK,TOIE0);
    #define T0_RESET                        TCNT0=0x00;
    #define T0_OC0_DISCONNECT               TCCR0=(TCCR0 & 0b11001111) | (0b00<<4);
    #define T0_OC0_NONINVERTED              TCCR0=(TCCR0 & 0b11001111) | (0b10<<4); 
    #define T0_OC0_INVERTED                 TCCR0=(TCCR0 & 0b11001111) | (0b11<<4); 
 
    char task_t0=0;
    
#pragma used+

//******************************
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    task_t0=1; 
}
    
//**************************************
void ConfigTimer0ForTimer(void){
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 0.977 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 0.26214 s
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<OCIE0) | (1<<TOIE0);
}

//**************************************
void ConfigTimer0ForCounter(void){
// Timer/Counter 0 initialization
// Clock source: T0 pin Rising Edge
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;

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
TCNT0=0x00;
OCR0=0x00;
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
TCNT0=0x00;
OCR0=0x00;
}

#pragma used-    
#endif
