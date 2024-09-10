//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include <timer0.h>

void main(void){
    Timer0_ConfigForCTC(); 
    Timer0_SetCompareOutputValue(0);	//255~0
    
    while(1){          
    }
}
