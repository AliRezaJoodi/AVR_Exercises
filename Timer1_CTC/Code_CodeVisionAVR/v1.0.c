// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <timer1.h>

void main(void){
    Timer1_ConfigForCTC();
    Timer1_SetCompareAValue(0);  //1023~0 
    
    while(1){          
    }
}

