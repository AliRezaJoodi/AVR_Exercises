// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer1.h"

void main(void){ 
 
    ConfigTimer1ForPWM();
    SetNonInvertedOutputFromOC1A();
    SetInvertedOutputFromOC1B();
    Set10BitPWM();
    OCR1A=100;      //0~1023 
    OCR1B=100;     //0~1023  
    
    while(1){          
    }
}

