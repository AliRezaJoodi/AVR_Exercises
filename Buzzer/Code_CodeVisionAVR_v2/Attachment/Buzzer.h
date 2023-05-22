// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef INCLUDED_BUZZER
    #define INCLUDED_BUZZER

#ifndef PORTS_BUZZER
    #define PORTS_BUZZER
    
    #define BUZZER_DDR      DDRB.1
    #define BUZZER_PORT     PORTB.1
    #define BUZZER_PIN      PINB.1 
    #define BUZZER          BUZZER_PORT 
    
    #define ACTIVE_BUZZER   1 
    #define BUZZERLAG       10    // Sound Period/Call Period  ==> 80ms/8ms
    #define PERIOD1         625   // Sound Period/Call Period  ==> 5000ms/8ms
    #define PERIOD2         250   // Sound Period/Call Period  ==> 2000ms/8ms       
#endif

char single_beep=0;
char periodical_single_beep=0;
char periodical_double_beep=0;
char periodical_continuous_beep=0;

//******************************
void _ConfigTimer0(void){
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 31.250 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 8 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x06;
OCR0=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
    #asm("sei") // Global enable interrupts
}

//********************************************************
void ConfigBuzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVE_BUZZER; 
    _ConfigTimer0();
}


//*******************************************************
//Be Called Periodically
void MakeTheSingleBeep(char *status){
    static unsigned char i=0;
    if(*status){ 
        BUZZER=ACTIVE_BUZZER; 
        ++i; if(i>=BUZZERLAG){i=0; *status=0; BUZZER=!ACTIVE_BUZZER;}   
    }
}

//*******************************************************
//Be Called Periodically
void MakeThePeriodicalSingleBeep(char status){
    static unsigned int i=0;
    static char active=0; 
    
    if(status){
        ++i; 
        if(i>=PERIOD1){i=0; active=1;} 
        MakeTheSingleBeep(&active);
    }
}

//*******************************************************
//Be Called Periodically
void MakeThePeriodicalDoubleBeep(char status){
    static unsigned int i=0;
    static char active=0; 

    if(status){
        ++i; 
        if(i==PERIOD1){active=1;}  
        if(i>=(PERIOD1+(2*BUZZERLAG))){active=1;i=0;}
        MakeTheSingleBeep(&active);
    }
}

//*******************************************************
//Be Called Periodically
void MakeThePeriodicalContinuousBeep(char status){
    static unsigned int i=0;
    static char active=0; 

    if(status){
        ++i; 
        if(i>=PERIOD2){active=1;}  
        if(i>=(PERIOD2+(5*BUZZERLAG))){active=1;i=0;}
        MakeTheSingleBeep(&active);
    }
}

//*******************************************************
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    TCNT0=0x06; 
    MakeTheSingleBeep(&single_beep);
    MakeThePeriodicalSingleBeep(periodical_single_beep);	
    MakeThePeriodicalDoubleBeep(periodical_double_beep);
    MakeThePeriodicalContinuousBeep(periodical_continuous_beep);
}

#endif
