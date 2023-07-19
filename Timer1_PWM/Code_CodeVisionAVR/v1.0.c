// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer1.h"

void main(void){ 
 
    ConfigTimer1ForPWM();
    T1_OC1A_NONINVERTED;
    T1_OC1B_INVERTED;
    T1_PWM_10BIT;
    OCR1A=100;      //0~1023 
    OCR1B=100;     //0~1023  
    
    while(1){          
    }
}

