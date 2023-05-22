// GitHub Account: GitHub.com/AliRezaJoodi
/*
Beep modes:
    0:  No Periodical Beep 
    1:  Making  A Periodical Single Beep
    2:  Making  A Periodical Double Beep
    3:  Making  A Periodical Continuous Beep
*/

#ifndef INCLUDED_BUZZER
    #define INCLUDED_BUZZER

#ifndef PORTS_BUZZER
    #define PORTS_BUZZER
    
    #define BUZZER_DDR      DDRB.1
    #define BUZZER_PORT     PORTB.1
    #define BUZZER_PIN      PINB.1 
    #define BUZZER          BUZZER_PORT 
    
    #define ACTIVE_BUZZER   1 
    #define BUZZERLAG       3       // Sound Period/Call Period  ==> 100ms/32.768ms
    #define PERIOD1         152     // Sound Period/Call Period  ==> 5000ms/32.768ms
    #define PERIOD2         61      // Sound Period/Call Period  ==> 2000ms/32.768ms           
#endif

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)  (ADDRESS|=1<<BIT)
#endif

#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)  (ADDRESS &=~(1<<BIT))
#endif

char single_beep=0;
char _buzzer_task=0; 
char beep_mode=0;

//******************************
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    _buzzer_task=1;
}

//******************************
void _ConfigTimer0(void){
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 32.768 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    //TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
    #asm("sei") // Global enable interrupts 
}

//******************************
void ConfigBuzzer(void){
    BUZZER_DDR=1; BUZZER_PORT=!ACTIVE_BUZZER; 
    _ConfigTimer0();
}

#pragma used+

//******************************
void _EnableTimer0(void){
    SETBIT(TIMSK,TOIE0);
}

//******************************
void _DisableTimer0(void){
    CLRBIT(TIMSK,TOIE0);
}

//******************************
char _Cunt100ms(void){
    static unsigned char i=0;
    ++i; if(i>=BUZZERLAG){i=0; return 1;}  
    return 0;
}

//******************************
//Be Called Periodically
void MakeABeep(char *status){
    if(*status){ 
        BUZZER=ACTIVE_BUZZER; 
        if(_Cunt100ms()){*status=0; BUZZER=!ACTIVE_BUZZER;}   
    }
}

//******************************
//Be Called Periodically
void MakeThePeriodicalSingleBeep(void){
    static unsigned int i=0;
    static char active=0; 
    
    ++i; 
    if(i>=PERIOD1){i=0; active=1;} 
    MakeABeep(&active);
}

//******************************
//Be Called Periodically
void MakeThePeriodicalDoubleBeep(void){
    static unsigned int i=0;
    static char active=0; 

    ++i; 
    if(i==PERIOD1){active=1;}  
    if(i>=(PERIOD1+(2*BUZZERLAG))){active=1;i=0;}
    MakeABeep(&active);
}

//******************************
//Be Called Periodically
void MakeThePeriodicalContinuousBeep(void){
    static unsigned int i=0;
    static char active=0; 

    ++i; 
    if(i>=PERIOD2){active=1;}  
    if(i>=(PERIOD2+(5*BUZZERLAG))){active=1;i=0;}
    MakeABeep(&active);
}

//******************************
// Call in the main
void RunTheBuzzerTasks(void){
    if(single_beep==1 || beep_mode>0){_EnableTimer0();} 
     
    if(_buzzer_task){
        _buzzer_task=0;
        
        if(single_beep==0 && beep_mode==0){_DisableTimer0();}
        MakeABeep(&single_beep);
    
        switch(beep_mode){ 
            case 1: 
                MakeThePeriodicalSingleBeep();
                break;
            case 2: 
                MakeThePeriodicalDoubleBeep();
                break;
            case 3: 
                MakeThePeriodicalContinuousBeep();
                break;
        }
    }     
}

#pragma used-

#endif
