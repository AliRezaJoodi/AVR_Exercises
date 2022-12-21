// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>
#include "Attachment\uart2.h"

unsigned char txt[20] = "Software UART\r" ;  

void main(void){
    initUART2(); // initialize the software UART2

    while(1){
        puts2(txt); delay_ms(1000);  
    }
}  

