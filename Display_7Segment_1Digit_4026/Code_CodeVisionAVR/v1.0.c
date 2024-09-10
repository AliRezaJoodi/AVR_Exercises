// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\Driver_4026.h"

void main(void){
    unsigned char value=0;

    while (1){
        for(value=0; value<=9; ++value){ 
            Drive_4026(value); delay_ms(400);
        }
    };
}