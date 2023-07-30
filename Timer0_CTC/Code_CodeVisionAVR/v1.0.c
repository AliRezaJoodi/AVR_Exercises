//GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>

#include "Attachment\Timer0.h"

void main(void){
    ConfigTimer0ForCTC(); 
    SetCompareOutputValueFromTimer0(0);	//255~0
    
    while(1){          
    }
}
