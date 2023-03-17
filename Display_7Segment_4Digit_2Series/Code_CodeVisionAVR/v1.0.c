// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include "Attachment\DisplayOn7Segment.h"

void main(void){  
    Config_7Segment();
      
    while(1){
        Int_LefToRight_Display1(4321); delay_ms(5);
        Float_LefToRight_Display2(0.123); delay_ms(5);
    };
}
