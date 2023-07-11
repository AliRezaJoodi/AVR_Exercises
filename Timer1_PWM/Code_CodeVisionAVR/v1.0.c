//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include "Attachment\Converter.h"

void ConfigTimer1ForPWM(void);

void main(void){  
    ConfigTimer1ForPWM();
    OCR1A=Convert_0to100_0to1023(50); 
    OCR1B=Convert_0to100_0to1023(75);  
    
    while(1){          
    }
}

//**********************************
void ConfigTimer1ForPWM(void){
    DDRD.4=1;
    DDRD.5=1;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Fast PWM top=0x03FF
// OC1A output: Non-Inverted PWM
// OC1B output: Inverted PWM
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 1.024 ms
// Output Pulse(s):
// OC1A Period: 1.024 ms Width: 0 us
// OC1B Period: 1.024 ms Width: 1.024 ms
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (1<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
}
