//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer2.h"

void main(void){
    ConfigTimer2ForCTC();
    SetCompareOutputValueFromTimer2(100);
    
    while(1){          
    }
}