//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include "Attachment\Config_Hardware_v1.0.txt"

bit old_status_button1=1;
bit old_status_button2=1;
bit old_status_button3=1;

void main(void){        
    Config_IO();
        
    while(1){
        if(BUTTON1==0 && old_status_button1==1){
            old_status_button1=0;
            LED=1;
        }
        if(BUTTON1==1){old_status_button1=1;} 
        
        if(BUTTON2==0 && old_status_button2==1){
            old_status_button2=0;
            LED=0;
        }
        if(BUTTON2==1){old_status_button2=1;}  
    }
}


