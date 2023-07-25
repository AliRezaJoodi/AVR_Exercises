//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

void ConfigTimer2ForCTC(void);
void ConfigTimer0ForPWM(void);

void main(void){          
    ConfigTimer2ForCTC();
    OCR2=0;   //255~0 
    
    ConfigTimer0ForPWM();
    OCR0=25;    //0~255 
    
    while(1){          
    }
}

//**********************************
void ConfigTimer0ForPWM(void){
    DDRB.3=1; PORTB.3=0;

// Timer/Counter 0 initialization
// Clock source: T0 pin Rising Edge
// Mode: Fast PWM top=0xFF
// OC0 output: Non-Inverted PWM
TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;
}

//**********************************
void ConfigTimer2ForCTC(void){
    DDRD.7=1;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 16000.000 kHz
// Mode: CTC top=OCR2A
// OC2 output: Toggle on compare match
// Timer Period: 0.0625 us
// Output Pulse(s):
// OC2 Period: 0.125 us Width: 0.0625 us
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (1<<COM20) | (1<<CTC2) | (0<<CS22) | (0<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2=0x00;
}
