
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
    
//**************************************
void ConfigTimer1ForTimerMode(void){
    TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
    TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
    TCNT1H=0x00; TCNT1L=0x00;
    ICR1H=0x00; ICR1L=0x00;
    OCR1AH=0x00; OCR1AL=0x00;
    OCR1BH=0x00; OCR1BL=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK= TIMSK | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1);
}

#pragma used+

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void){
    task_t1=1; 
}

//******************************
void SetPerscalerForTimer1(char prescaler){
    TCCR1B=TCCR1B | prescaler;        
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
#pragma used-    
#endif
