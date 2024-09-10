//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include <timer2.h>

void main(void){
    Timer2_ConfigForCTC();
    Timer2_SetCompareOutputValue(100);
    
    while(1){          
    }
}