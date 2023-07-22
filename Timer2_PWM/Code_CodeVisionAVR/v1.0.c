//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

#include "Attachment\Timer2.h"

void main(void){ 
 
    ConfigTimer2ForPWM(); 
    T2_OC2_DISCONNECT;
    T2_OC2_NONINVERTED;
    //T2_OC2_INVERTED;
    //T2_CLOCK_P32;
    OCR2=25;   //0~255
     
    while(1){   
    }
}





