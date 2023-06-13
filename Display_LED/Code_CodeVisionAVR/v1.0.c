// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>  
 
#include "Attachment\LED.h"

void main(void){
    ConfigLeds();
      
    SetAllLeds(0b00000000); delay_ms(500); 
    SetAllLeds(0b10101010); delay_ms(500); SetAllLeds(0b00000000); delay_ms(500); 
    TurnOnAllLeds(); delay_ms(500); TurnOffAllLeds(); delay_ms(500);
    TurnOnOneLed(0); delay_ms(500); TurnOffOneLed(0); delay_ms(500); 
    SetOneLed(3,1); delay_ms(500); SetOneLed(3,0); delay_ms(500); 
    BlinkOnLED(7,500); 
    
    while(1){ 
    }
}

