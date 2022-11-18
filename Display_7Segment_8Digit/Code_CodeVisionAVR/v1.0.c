// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\Driver_7Segment.h"

unsigned long int value=87654321;

void Drive_7Segment(unsigned long int);

void main(void){
    Config_7Segment();
    
    while(1){
        Drive_7Segment(value); delay_us(500);
    };
}
