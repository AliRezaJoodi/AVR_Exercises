//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>   
#include "Attachment\Hardware_v1.0.h"
#include "Attachment\LED.h"

void main(void){  
    Set_Leds(0b00000000); delay_ms(500); 
    Set_Leds(0b10101010); delay_ms(500); Set_Leds(0b00000000); delay_ms(500); 
    On_Leds(); delay_ms(500); Off_Leds(); delay_ms(500);
    On_Led(0); delay_ms(500); Off_Led(0); delay_ms(500);
    On_Led(ALARM1); delay_ms(500); Off_Led(ALARM1); delay_ms(500); 
    Flasher_Led(ALARM2,500); delay_ms(500); 
    Set_Led(ALARM3,ACTIVATE_LED); delay_ms(500); Set_Led(ALARM3,DEACTIVATE_LED); delay_ms(500); 
    
    while(1){ 
    }
}

