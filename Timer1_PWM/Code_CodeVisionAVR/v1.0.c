#include <mega32a.h>
#include <delay.h>

void Config_Timer1_PWM(void);

void main(void){
    unsigned value1=250;
    unsigned value2=250;
    
    Config_Timer1_PWM();    
    OCR1A=value1; //0~1023 
    OCR1B=value2; //0~1023 
    
    while(1){          
    }
}

//**********************************
void Config_Timer1_PWM(void){
    DDRD.4=1;
    DDRD.5=1;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: 125.000 kHz
    // Mode: Ph. correct PWM top=0x03FF
    // OC1A output: Non-Inverted PWM
    // OC1B output: Inverted PWM
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer Period: 16.368 ms
    // Output Pulse(s):
    // OC1A Period: 16.368 ms Width: 0 us
    // OC1B Period: 16.368 ms Width: 16.368 ms
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (1<<WGM10);
    TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;
}
