// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

#include <display_7segment_4digit_2display.h>

void main(void){  
    Config_7Segment();
      
    while(1){
        //Int_LefToRight_Display1(4321); delay_ms(5);
        //Float_LefToRight_Display2(0.123); delay_ms(5);
        //Display1(4.321, 3); delay_ms(250);  
        //Display2(1.234, 1); delay_ms(250);
        DisplayAll(54.321, 0.432); delay_ms(4);    
    };
}
