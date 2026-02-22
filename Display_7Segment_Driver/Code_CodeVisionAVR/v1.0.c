// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

#include <display_7segment_8digit.h>

unsigned long int value=87654321;

void main(void){
    Configure7Segment();
    
    while(1){
        Display_7Segment(value); 
        delay_ms(DISPLAYLAG); 
    };
}
