// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include <timer0.h>

void main(void){ 
    Timer0_ConfigForPWM(); 
    Timer0_SetCompareOutputValue(50);   //0~255 
    
    while(1){   
    }
}






