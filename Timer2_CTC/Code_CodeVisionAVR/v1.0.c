//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer2.h"

void main(void){
    ConfigTimer2ForCTC();
    //T2_CLOCK_STOP;
    OCR2=0;    //0~255 

    while(1){          
    }
}