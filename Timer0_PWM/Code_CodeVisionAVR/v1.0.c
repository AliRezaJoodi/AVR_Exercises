// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include "Attachment\Timer0.h"

void main(void){ 
    ConfigTimer0ForPWM(); 
    SetCompareOutputValueFromTimer0(50);   //0~255 
    
    while(1){   
    }
}






