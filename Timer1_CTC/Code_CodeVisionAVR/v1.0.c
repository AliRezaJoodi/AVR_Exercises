//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

void ConfigTimer1ForCTC(void);

void main(void){
    ConfigTimer1ForCTC();
    OCR1A=0;    //0~1023 

    while(1){          
    }
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
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00; OCR1AL=0x00;
OCR1BH=0x00; OCR1BL=0x00;
}
