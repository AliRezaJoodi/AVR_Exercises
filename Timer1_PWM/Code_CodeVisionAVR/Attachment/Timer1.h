
#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

    
#ifndef _INCLUDED_TIMER1
    #define _INCLUDED_TIMER1
    
    #define PERSCALER_1                 (0<<CS12) | (0<<CS11) | (1<<CS10)
    #define PERSCALER_8                 (0<<CS12) | (1<<CS11) | (0<<CS10)
    #define PERSCALER_64                (0<<CS12) | (1<<CS11) | (1<<CS10)
    #define PERSCALER_256               (1<<CS12) | (0<<CS11) | (0<<CS10)
     
    char task_t1=0;
    
#pragma used+

//******************************
// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void){
    task_t1=1; 
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
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
TCNT1H=0x00; TCNT1L=0x00;
ICR1H=0x00; ICR1L=0x00;
OCR1AH=0x00; OCR1AL=0x00;
OCR1BH=0x00; OCR1BL=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1);
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

//******************************
void SetPerscalerFromTimer1(char prescaler){
    TCCR1B=(TCCR1B & 0b11111000) | prescaler;        
}

//******************************
void DisableClockSourceFromTimer1(void){
    TCCR1B=TCCR1B & 0b11111000;        
}

//******************************
void EnableOverflowInterruptFromTimer1(void){
    SETBIT(TIMSK,TOIE1);    
}

//******************************
void DisableOverflowInterruptFromTimer1(void){
    CLRBIT(TIMSK,TOIE1);    
}

//******************************
void ResetTimer1(void){
    TCNT1H=0x00; TCNT1L=0x00;
    //TCNT1=0x00;
}

//**********************************
void SetInvertedOutputFromOC1A(void){
    TCCR1A=(TCCR1A & 0b00111111) | (1<<COM1A1) | (1<<COM1A0);
}

//**********************************
void SetNonInvertedOutputFromOC1A(void){
    TCCR1A=(TCCR1A & 0b00111111) | (1<<COM1A1) | (0<<COM1A0);
}

//**********************************
void DisconnectOutputFromOC1A(void){
    TCCR1A=(TCCR1A & 0b00111111) | (0<<COM1A1) | (0<<COM1A0);
}

//**********************************
void SetInvertedOutputFromOC1B(void){
    TCCR1A=(TCCR1A & 0b11001111) | (1<<COM1B1) | (1<<COM1B0);
}

//**********************************
void SetNonInvertedOutputFromOC1B(void){
    TCCR1A=(TCCR1A & 0b11001111) | (1<<COM1B1) | (0<<COM1B0);
}

//**********************************
void DisconnectOutputFromOC1B(void){
    TCCR1A=(TCCR1A & 0b11001111) | (0<<COM1B1) | (0<<COM1B0);
}

//**********************************
void Set8BitPWM(void){
    TCCR1A=(TCCR1A & 0b11111100) | (0<<WGM11) | (1<<WGM10);
}

//**********************************
void Set9BitPWM(void){
    TCCR1A=(TCCR1A & 0b11111100) | (1<<WGM11) | (0<<WGM10);
}

//**********************************
void Set10BitPWM(void){
    TCCR1A=(TCCR1A & 0b11111100) | (1<<WGM11) | (1<<WGM10);    
}

#pragma used-    
#endif
