// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef GET_INT
    #define GET_INT(MSB,LSB)            (MSB<<8)+LSB;
#endif

#ifndef GET_MSB     
    #define GET_MSB(INT)                INT>>8;
#endif

#ifndef GET_LSB
    #define GET_LSB(INT)                INT&0x00FF;
#endif

#ifndef ENABLE_GLOBAL_INTERRUPT
    #define ENABLE_GLOBAL_INTERRUPT(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif
    
#ifndef _INCLUDED_TIMER1
    #define _INCLUDED_TIMER1
    
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
    
    // PWM Output Mode
    #define T1_DISCONNECT                   0b00
    #define T1_NONINVERTED                  0b10
    #define T1_INVERTED                     0b11
    
    // Input Capture Edge Select on the ICP1 Pin
    #define ICP1PIN_FALLING_EDGE            (0<<ICES1)
    #define ICP1PIN_RISING_EDGE             (1<<ICES1)

    // Commands
    #define SET_TIMER1_OPERATIONMODE(MODE)      TCCR1A=(TCCR1A & 0b11111100) | (MODE & 0b0011); TCCR1B=(TCCR1B & 0b11100111) | ((MODE & 0b1100)<<1);
    #define SET_TIMER1_CLOCKSOURCE(MODE)        TCCR1B=(TCCR1B & 0b11111000) | MODE;
    #define SET_TIMER1_OC1APIN(MODE)            TCCR1A=(TCCR1A & 0b00111111) | (MODE<<6);
    #define SET_TIMER1_OC1BPIN(MODE)            TCCR1A=(TCCR1A & 0b11001111) | (MODE<<4);
    #define SET_TIMER1_TCNT0VALUE(VALUE)        TCNT1H=GET_MSB(VALUE); TCNT1L=GET_LSB(VALUE);  
    #define SET_TIMER1_OCR1AVALUE(VALUE)        OCR1AH=GET_MSB(VALUE); OCR1AL=GET_LSB(VALUE);
    #define SET_TIMER1_OCR1BVALUE(VALUE)        OCR1BH=GET_MSB(VALUE); OCR1BL=GET_LSB(VALUE);
    #define SET_TIMER1_CAPTUREVALUE(VALUE)      ICR1H=GET_MSB(VALUE); ICR1L=GET_LSB(VALUE);
    #define SET_TIMER1_CAPTUREMODE(MODE)        TCCR1B=(TCCR1B & 0b10111111) | MODE;
    #define ENABLE_TIMER1_INT_OVF(STATUS)       if(STATUS){SETBIT(TIMSK,TOIE1);} else{CLRBIT(TIMSK,TOIE1);}
    #define ENABLE_TIMER1_INT_COMPA(STATUS)     if(STATUS){SETBIT(TIMSK,OCIE1A);} else{CLRBIT(TIMSK,OCIE1A);}
    #define ENABLE_TIMER1_INT_COMPB(STATUS)     if(STATUS){SETBIT(TIMSK,OCIE1B);} else{CLRBIT(TIMSK,OCIE1B);}
    #define ENABLE_TIMER1_INT_CAPTURE(STATUS)   if(STATUS){SETBIT(TIMSK,TICIE1);} else{CLRBIT(TIMSK,TICIE1);}
    
    // Commands: Different type    
    #define SetOperationModeFromTimer1(MODE)                    TCCR1A=(TCCR1A & 0b11111100) | (MODE & 0b0011); TCCR1B=(TCCR1B & 0b11100111) | ((MODE & 0b1100)<<1);
    #define SetClockSourceFromTimer1(MODE)                      TCCR1B=(TCCR1B & 0b11111000) | MODE;
    #define SetPWM1AOutputModeFromTimer1(MODE)                  TCCR1A=(TCCR1A & 0b00111111) | (MODE<<6);
    #define SetPWM1BOutputModeFromTimer1(MODE)                  TCCR1A=(TCCR1A & 0b11001111) | (MODE<<4);
    #define EnableInputCaptureNoiseCancelerFromTimer1(STATUS)   if(STATUS){SETBIT(TCCR1B,ICNC1);} else{CLRBIT(TCCR1B,ICNC1);}
    #define SetInputCaptureEdgeSelectFromTimer1(MODE)           TCCR1B=(TCCR1B & 0b10111111) | MODE;
    #define SetTimerValueFromTimer1(VALUE)                      TCNT1H=GET_MSB(VALUE); TCNT1L=GET_LSB(VALUE);  
    #define SetCompareAValueFromTimer1(VALUE)                   OCR1AH=GET_MSB(VALUE); OCR1AL=GET_LSB(VALUE);
    #define SetCompareBValueFromTimer1(VALUE)                   OCR1BH=GET_MSB(VALUE); OCR1BL=GET_LSB(VALUE);
    #define SetInputCaptureValueFromTimer1(VALUE)               ICR1H=GET_MSB(VALUE); ICR1L=GET_LSB(VALUE);
    #define EnableOverflowInterruptFromTimer1(STATUS)           if(STATUS){SETBIT(TIMSK,TOIE1);} else{CLRBIT(TIMSK,TOIE1);}
    #define EnableCompareAInterruptFromTimer1(STATUS)           if(STATUS){SETBIT(TIMSK,OCIE1A);} else{CLRBIT(TIMSK,OCIE1A);}
    #define EnableCompareBInterruptFromTimer1(STATUS)           if(STATUS){SETBIT(TIMSK,OCIE1B);} else{CLRBIT(TIMSK,OCIE1B);}
    #define EnableInputCaptureInterruptFromTimer1(STATUS)       if(STATUS){SETBIT(TIMSK,TICIE1);} else{CLRBIT(TIMSK,TICIE1);}
        
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
void ConfigTimer1ForTimer(void){
    SetOperationModeFromTimer1(T1_NORMAL);
    SetClockSourceFromTimer1(T1CLK_P8);
    SetPWM1AOutputModeFromTimer1(T1_DISCONNECT);
    SetPWM1BOutputModeFromTimer1(T1_DISCONNECT); 
    EnableInputCaptureNoiseCancelerFromTimer1(0);
    SetInputCaptureEdgeSelectFromTimer1(ICP1PIN_FALLING_EDGE);
    SetTimerValueFromTimer1(0);
    SetCompareAValueFromTimer1(0);
    SetCompareBValueFromTimer1(0);  
    SetInputCaptureValueFromTimer1(0);
    EnableOverflowInterruptFromTimer1(1); 
    EnableCompareAInterruptFromTimer1(0);
    EnableCompareBInterruptFromTimer1(0);
    EnableInputCaptureInterruptFromTimer1(0); 
    
    ENABLE_GLOBAL_INTERRUPT(1);
}

//**************************************
void ConfigTimer1ForCounter(void){
// Timer/Counter 1 initialization
// Clock source: T1 pin Rising Edge
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (1<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x00; TCNT1L=0x00;
ICR1H=0x00; ICR1L=0x00;
OCR1AH=0x00; OCR1AL=0x00;
OCR1BH=0x00; OCR1BL=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1);
}

//**********************************
void ConfigTimer1ForPWM(void){
    DDRD.4=1;
    DDRD.5=1;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Fast PWM top=0x03FF
// OC1A output: Non-Inverted PWM
// OC1B output: Inverted PWM
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 1.024 ms
// Output Pulse(s):
// OC1A Period: 1.024 ms Width: 0 us
// OC1B Period: 1.024 ms Width: 1.024 ms
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (1<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
TCNT1H=0x00; TCNT1L=0x00;
ICR1H=0x00; ICR1L=0x00;
OCR1AH=0x00; OCR1AL=0x00;
OCR1BH=0x00; OCR1BL=0x00;
}

//**********************************
void ConfigTimer1ForCTC(void){
    DDRD.4=1; PORTD.4=0;
    DDRD.5=1; PORTD.5=0;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: CTC top=OCR1A
// OC1A output: Toggle on compare match
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 1 us
// Output Pulse(s):
// OC1A Period: 2 us Width: 1 us
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (1<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
TCNT1H=0x00; TCNT1L=0x00;
ICR1H=0x00; ICR1L=0x00;
OCR1AH=0x00; OCR1AL=0x00;
OCR1BH=0x00; OCR1BL=0x00;
}

#pragma used-    
#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    