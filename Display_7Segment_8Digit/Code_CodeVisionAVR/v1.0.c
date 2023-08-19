// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\Display_7Segment_8Digit.h"

unsigned long int value=87654321;

void main(void){
    Configure7Segment();
    
    while(1){
        Display_7Segment(value); 
        delay_ms(DISPLAYLAG); 
    };
}
