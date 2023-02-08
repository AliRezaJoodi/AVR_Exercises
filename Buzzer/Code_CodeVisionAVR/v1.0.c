//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

char bs_beep=0;
char bs_p1=0;
char bs_p2=0;
char bs_pc=0;

#include "Attachment\Buzzer.h"

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    TCNT0=0x06; 
    Beep_Buzzer(&bs_beep);
    P1_Buzzer(bs_p1);	
    P2_Buzzer(bs_p2);
    PC_Buzzer(bs_pc);
}
    
void Config_Timer0(void);

void main(void){  
    Config_Buzzer(); 
    Config_Timer0();
    
    Sound1_Buzzer(); delay_ms(500);
    Sound2_Buzzer(); delay_ms(500);
    Sound3_Buzzer(); delay_ms(1000);
    
    bs_beep=1;
    bs_p1=0;
    bs_p2=1;
    bs_pc=0;
     
    while(1){

    }
}

//******************************
void Config_Timer0(void){
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
    // Global enable interrupts
    #asm("sei")
}


