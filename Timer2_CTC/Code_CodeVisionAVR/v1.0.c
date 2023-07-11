//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

void ConfigTimer2ForCTC(void);

void main(void){
    ConfigTimer2ForCTC();
    OCR2=0;    //0~255 

    while(1){          
    }
}

//**********************************
void ConfigTimer2ForCTC(void){
    DDRD.7=1; PORTD.7=0;
    
// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: CTC top=OCR2A
// OC2 output: Toggle on compare match
// Timer Period: 1 us
// Output Pulse(s):
// OC2 Period: 2 us Width: 1 us
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (1<<COM20) | (1<<CTC2) | (0<<CS22) | (1<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;
}
