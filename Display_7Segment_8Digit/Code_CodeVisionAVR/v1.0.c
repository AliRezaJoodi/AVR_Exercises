// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\Driver_7Segment.h"

unsigned long int value=87654321;

void main(void){
    
    while(1){
        Display_7Segment(value); delay_us(500);
    };
}
