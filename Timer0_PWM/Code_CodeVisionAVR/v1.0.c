// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

void ConfigTimer0ForPWM(void);

void main(void){
 
    ConfigTimer0ForPWM(); 
    OCR0=50;   //0~255
    while(1){   
    }
}

//******************************************
void ConfigTimer0ForPWM(void){
    DDRB.3=1; PORTB.3=0;  
    
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Fast PWM top=0xFF
// OC0 output: Non-Inverted PWM
// Timer Period: 0.032 ms
// Output Pulse(s):
// OC0 Period: 0.032 ms Width: 0 us
TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;
}






