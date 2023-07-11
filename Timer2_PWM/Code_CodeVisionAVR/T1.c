//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

#include "Attachment\Converter.h"

void ConfigTimer2ForPWM(void);

void main(void){ 
    unsigned char value; 
    ConfigTimer2ForPWM(); 
    
    value=Convert_0to100_0to255(50); OCR2=value;
     
    while(1){   
    }
}

//******************************************
void ConfigTimer2ForPWM(void){
    DDRD.7=1; PORTD.7=0;  
    
    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: 250.000 kHz
    // Mode: Fast PWM top=0xFF
    // OC2 output: Non-Inverted PWM
    // Timer Period: 1.024 ms
    // Output Pulse(s):
    // OC2 Period: 1.024 ms Width: 0 us
    ASSR=0<<AS2;
    TCCR2=(1<<PWM2) | (1<<COM21) | (0<<COM20) | (1<<CTC2) | (0<<CS22) | (1<<CS21) | (1<<CS20);
    TCNT2=0x00;
    OCR2=0x00;  //0~255
}






