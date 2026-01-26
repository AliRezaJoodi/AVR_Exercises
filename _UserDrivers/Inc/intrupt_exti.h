// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)       if(STATUS){#asm("sei")} else{#asm("cli")}
#endif

#ifndef _EXTI_INCLUDED
    #define _EXTI_INCLUDED
        
    // Interrupt Sense Control
    #define LOW_LEVEL               	        0b00   //(0<<ISC01) | (0<<ISC00)
    #define ANY_CHANGE               	        0b01   //(0<<ISC01) | (1<<ISC00)
    #define FALLING_EDGE               	        0b10   //(1<<ISC01) | (0<<ISC00)
    #define RISING_EDGE               	        0b11   //(1<<ISC01) | (1<<ISC00)
    
    // Commands
    #define INT0_SetSenseControl(MODE)          MCUCR=(MCUCR & 0b11111100) | MODE; 
    #define INT1_SetSenseControl(MODE)          MCUCR=(MCUCR & 0b11110011) | (MODE<<2);
    #define INT2_SetSenseControl(MODE)          if(MODE==FALLING_EDGE){ClearBit(MCUCSR,ISC2);} else if(MODE==RISING_EDGE){SetBit(MCUCSR,ISC2);}
    #define INT0_EnableOrDisable(STATUS)        if(STATUS){SetBit(GICR,INT0); SetBit(GIFR,INTF0);} else{ClearBit(GICR,INT0);}
    #define INT1_EnableOrDisable(STATUS)        if(STATUS){SetBit(GICR,INT1); SetBit(GIFR,INTF1);} else{ClearBit(GICR,INT1);}
    #define INT2_EnableOrDisable(STATUS)        if(STATUS){SetBit(GICR,INT2); SetBit(GIFR,INTF2);} else{ClearBit(GICR,INT2);}
        
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
void INT0_Config(char mode){
    DDRD.2=0; PORTD.2=1;
    INT0_SetSenseControl(mode);
    INT0_EnableOrDisable(1);

    EnableGlobalInterrupt(1);
}
 
//**************************************
void INT1_Config(char mode){
    DDRD.3=0; PORTD.3=1;
    INT1_SetSenseControl(mode);
    INT1_EnableOrDisable(1);

    EnableGlobalInterrupt(1);
}

//**************************************
void INT2_Config(char mode){
    DDRB.2=0; PORTB.2=1;
    INT2_SetSenseControl(mode);
    INT2_EnableOrDisable(1);

    EnableGlobalInterrupt(1);
}
   
#pragma used-    
#endif
