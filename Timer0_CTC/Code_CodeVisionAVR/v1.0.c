//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

void ConfigTimer0ForCTC(void);

void main(void){
    ConfigTimer0ForCTC();
    OCR0=0;    //0~255 

    while(1){          
    }
}

//**********************************
void ConfigTimer0ForCTC(void){
    DDRB.3=1; PORTB.3=0;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: CTC top=OCR0
// OC0 output: Toggle on compare match
// Timer Period: 1 us
// Output Pulse(s):
// OC0 Period: 2 us Width: 1 us
TCCR0=(0<<WGM00) | (0<<COM01) | (1<<COM00) | (1<<WGM01) | (0<<CS02) | (1<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;
}
