// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

    
#ifndef _INCLUDED_TIMER0
    #define _INCLUDED_TIMER0

    #define T2_CLOCK_STOP                   TCCR2=(TCCR2 & 0b11111000) | 0b000; 
    #define T2_CLOCK_P1                     TCCR2=(TCCR2 & 0b11111000) | 0b001; 
    #define T2_CLOCK_P8                     TCCR2=(TCCR2 & 0b11111000) | 0b010; 
    #define T2_CLOCK_P32                    TCCR2=(TCCR2 & 0b11111000) | 0b011; 
    #define T2_CLOCK_P64                    TCCR2=(TCCR2 & 0b11111000) | 0b100; 
    #define T2_CLOCK_P128                   TCCR2=(TCCR2 & 0b11111000) | 0b101; 
    #define T2_CLOCK_P256                   TCCR2=(TCCR2 & 0b11111000) | 0b110;
    #define T2_CLOCK_P1024                  TCCR2=(TCCR2 & 0b11111000) | 0b111;
    #define T2_INT_OVF_ENABLE               SETBIT(TIMSK,TOIE2);
    #define T2_INT_OVF_DISABLE              CLRBIT(TIMSK,TOIE2); 
    #define T2_INT_COMP_ENABLE              SETBIT(TIMSK,OCIE2);
    #define T2_INT_COMP_DISABLE             CLRBIT(TIMSK,OCIE2);
    #define T2_RESET                        TCNT2=0x00;
    #define T2_SET(VALUE)                   TCNT2=VALUE;
    #define T2_END                          TCNT2=255;
    #define T2_OC2_DISCONNECT               TCCR2=(TCCR2 & 0b11001111) | (0b00<<4);
    #define T2_OC2_NONINVERTED              TCCR2=(TCCR2 & 0b11001111) | (0b10<<4); 
    #define T2_OC2_INVERTED                 TCCR2=(TCCR2 & 0b11001111) | (0b11<<4); 
 
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
// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Normal top=0xFF
// OC2 output: Disconnected
// Timer Period: 32.768 ms
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (1<<CS22) | (1<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<OCIE2) | (1<<TOIE2);
}

//**************************************
void ConfigTimer2ForAsyncTimer(void){
// Timer/Counter 2 initialization
// Clock source: TOSC1 pin
// Clock value: PCK2/128
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=1<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (1<<CS22) | (0<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<OCIE2) | (1<<TOIE2);
}

//**********************************
void ConfigTimer2ForPWM(void){
    DDRD.7=1; PORTD.7=0;  
    
// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Fast PWM top=0xFF
// OC2 output: Non-Inverted PWM
// Timer Period: 0.032 ms
// Output Pulse(s):
// OC2 Period: 0.032 ms Width: 0 us
ASSR=0<<AS2;
TCCR2=(1<<PWM2) | (1<<COM21) | (0<<COM20) | (1<<CTC2) | (0<<CS22) | (0<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2=0x00;
}

//**********************************
void ConfigTimer2ForCTC(void){
    DDRD.7=1; PORTD.7=0;
    
// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: CTC top=OCR2A
// OC2 output: Toggle on compare match
// Timer Period: 0.125 us
// Output Pulse(s):
// OC2 Period: 0.25 us Width: 0.125 us
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (1<<COM20) | (1<<CTC2) | (0<<CS22) | (0<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2=0x00;
}

#pragma used-    
#endif
