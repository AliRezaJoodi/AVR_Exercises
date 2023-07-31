// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

#include "Attachment\Timer2.h"

void main(void){ 
 
    ConfigTimer2ForPWM(); 
    SetCompareOutputValueFromTimer2(25);
     
    while(1){   
    }
}





