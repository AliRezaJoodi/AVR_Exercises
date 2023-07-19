// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer0.h"

void main(void){
 
    ConfigTimer0ForPWM(); 
    T0_CLOCK_P1;
    T0_OC0_DISCONNECT;
    T0_OC0_INVERTED;
    T0_OC0_NONINVERTED; 
    OCR0=50;   //0~255 
    
    while(1){   
    }
}






