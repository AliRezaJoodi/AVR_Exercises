// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\Driver_74164.h"

void main(void){
    unsigned char value=0b00000101;

    while (1){
        for(value=0; value<=9; ++value){ 
            Drive_74164(value); delay_ms(400);
        }
    };
}