// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer1.h"

void main(void){
    ConfigTimer1ForCTC();
    OCR1A=0;    //1023~0 

    while(1){          
    }
}

