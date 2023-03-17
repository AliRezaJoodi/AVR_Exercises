// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#include "Attachment\DisplayOn7Segment.h"

void main(void){  
    Config_7Segment();
      
    while(1){
        //Int_LefToRight_Display1(4321); delay_ms(300);
        Float_RightToLeft_Display2(9.123); delay_ms(300);
    };
}
