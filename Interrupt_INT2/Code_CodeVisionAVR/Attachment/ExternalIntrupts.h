// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)       if(STATUS){#asm("sei")} else{#asm("cli")}
#endif

#ifndef _INCLUDED_INTRUPTS
    #define _INCLUDED_INTRUPTS
        
    // Interrupt Sense Control
    #define LOW_LEVEL               	        0b00   //(0<<ISC01) | (0<<ISC00)
    #define ANY_CHANGE               	        0b01   //(0<<ISC01) | (1<<ISC00)
    #define FALLING_EDGE               	        0b10   //(1<<ISC01) | (0<<ISC00)
    #define RISING_EDGE               	        0b11   //(1<<ISC01) | (1<<ISC00)
    
    // Commands
    #define SetInterrupt0SenseControl(MODE)     MCUCR=(MCUCR & 0b11111100) | MODE; 
    #define SetInterrupt1SenseControl(MODE)     MCUCR=(MCUCR & 0b11110011) | (MODE<<2);
    #define SetInterrupt2SenseControl(MODE)     if(MODE==FALLING_EDGE){CLRBIT(MCUCSR,ISC2);} else if(MODE==RISING_EDGE){SETBIT(MCUCSR,ISC2);}
    #define EnableInterrupt0(STATUS)            if(STATUS){SETBIT(GICR,INT0); SETBIT(GIFR,INTF0);} else{CLRBIT(GICR,INT0);}
    #define EnableInterrupt1(STATUS)            if(STATUS){SETBIT(GICR,INT1); SETBIT(GIFR,INTF1);} else{CLRBIT(GICR,INT1);}
    #define EnableInterrupt2(STATUS)            if(STATUS){SETBIT(GICR,INT2); SETBIT(GIFR,INTF2);} else{CLRBIT(GICR,INT2);}
        
#pragma used+

char task_int0=0;
char task_int1=0;
char task_int2=0;

//**************************************
interrupt [EXT_INT0] void ext_int0_isr(void){
    task_int0=1;
}

//**************************************
interrupt [EXT_INT1] void ext_int1_isr(void){
    task_int1=1;
}

//**************************************
interrupt [EXT_INT2] void ext_int2_isr(void){
    task_int2=1;
}
    
//**************************************
void ConfigExternalInterrupts(void){
    DDRD.2=0; PORTD.2=1;
    SetInterrupt0SenseControl(RISING_EDGE);
    EnableInterrupt0(0);
    
    DDRD.3=0; PORTD.3=1;
    SetInterrupt1SenseControl(RISING_EDGE);
    EnableInterrupt1(0);
    
    DDRB.2=0; PORTB.2=1;
    SetInterrupt2SenseControl(RISING_EDGE);
    EnableInterrupt2(1);

    EnableGlobalInterrupt(1);
}    

#pragma used-    
#endif
