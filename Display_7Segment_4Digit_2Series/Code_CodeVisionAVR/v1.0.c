// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\DisplayOn7Segment.h"

unsigned int value1=1234;
unsigned int value2=4321;

void main(void){
    
    while(1){
        DisplayOn7Segment_D1_Int(value1); delay_ms(1);
        DisplayOn7Segment_D2_Int(value2); delay_ms(1);
    };
}
