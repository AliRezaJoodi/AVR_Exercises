// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\DisplayOn7Segment.h"

//unsigned int value1=1234;
//unsigned int value2=4321;
//float value1_float=1000.3;

void main(void){    
    while(1){
        DisplayOn7Segment_D1_Int(4321); delay_ms(1);
        //DisplayOn7Segment_D2_Int(1234); delay_ms(1);
        //DisplayOn7Segment_D1_Float(100.3); delay_ms(1);
        DisplayOn7Segment_D2_Float(10.02); delay_ms(1);
    };
}
