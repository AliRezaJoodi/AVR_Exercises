// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

    
#ifndef _INCLUDED_TIMER1
    #define _INCLUDED_TIMER1
    
    #define T1_CLOCK_STOP                   TCCR1B=(TCCR1B & 0b11111000) | 0b000; 
    #define T1_CLOCK_P1                     TCCR1B=(TCCR1B & 0b11111000) | 0b001; 
    #define T1_CLOCK_P8                     TCCR1B=(TCCR1B & 0b11111000) | 0b010; 
    #define T1_CLOCK_P64                    TCCR1B=(TCCR1B & 0b11111000) | 0b011; 
    #define T1_CLOCK_P256                   TCCR1B=(TCCR1B & 0b11111000) | 0b100; 
    #define T1_CLOCK_P1024                  TCCR1B=(TCCR1B & 0b11111000) | 0b101; 
    #define T1_CLOCK_EXTERNAL_FALLING       TCCR1B=(TCCR1B & 0b11111000) | 0b110;  
    #define T1_CLOCK_EXTERNAL_RISING        TCCR1B=(TCCR1B & 0b11111000) | 0b111;
    #define T1_INT_OVF_ENABLE               SETBIT(TIMSK,TOIE1);
    #define T1_INT_OVF_DISABLE              CLRBIT(TIMSK,TOIE1); 
    #define T1_INT_COMPA_ENABLE             SETBIT(TIMSK,OCIE1A);
    #define T1_INT_COMPA_DISABLE            CLRBIT(TIMSK,OCIE1A); 
    #define T1_INT_COMPB_ENABLE             SETBIT(TIMSK,OCIE1B);
    #define T1_INT_COMPB_DISABLE            CLRBIT(TIMSK,OCIE1B);
    #define T1_RESET                        TCNT1H=0x00; TCNT1L=0x00;
    #define T1_OC1A_DISCONNECT              TCCR1A=(TCCR1A & 0b00111111) | (0<<COM1A1) | (0<<COM1A0);
    #define T1_OC1A_NONINVERTED             TCCR1A=(TCCR1A & 0b00111111) | (1<<COM1A1) | (0<<COM1A0); 
    #define T1_OC1A_INVERTED                TCCR1A=(TCCR1A & 0b00111111) | (1<<COM1A1) | (1<<COM1A0); 
    #define T1_OC1B_DISCONNECT              TCCR1A=(TCCR1A & 0b11001111) | (0<<COM1B1) | (0<<COM1B0);
    #define T1_OC1B_NONINVERTED             TCCR1A=(TCCR1A & 0b11001111) | (1<<COM1B1) | (0<<COM1B0); 
    #define T1_OC1B_INVERTED                TCCR1A=(TCCR1A & 0b11001111) | (1<<COM1B1) | (1<<COM1B0); 
    #define T1_PWM_8BIT                     TCCR1A=(TCCR1A & 0b11111100) | (0<<WGM11) | (1<<WGM10);
    #define T1_PWM_9BIT             	    TCCR1A=(TCCR1A & 0b11111100) | (1<<WGM11) | (0<<WGM10); 
    #define T1_PWM_10BIT                    TCCR1A=(TCCR1A & 0b11111100) | (1<<WGM11) | (1<<WGM10);
    
    char task_t1_ovf=0;
    char task_t1_compa=0;
    char task_t1_compb=0;
    
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
void ConfigTimer1ForTimer(void){
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 0.52429 s
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x00; TCNT1L=0x00;
ICR1H=0x00; ICR1L=0x00;
OCR1AH=0x00; OCR1AL=0x00;
OCR1BH=0x00; OCR1BL=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1);
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
