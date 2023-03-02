// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

#pragma used+
unsigned int input_int=0;
float input_mv=0;
float input_v=0;
float temp=0;
#pragma used-

#include <Attachment\_LCD.h>
#include <Attachment\ADC.h>
#include <Attachment\LM35.h>
#include <Attachment\Character.h>
#include <Attachment\Average.h>

void main(void){
    Config_LCD();
    Config_ADC();
    define_char(CHAR1,0); 
    
    while(1){ 
        input_mv=GetMilliVolt_ADC(CH_LM35); 
        temp=Convert_mVtoTemp_LM35(input_mv);
        temp=Average(temp);
        Display_LCD(temp);
        delay_ms(250);                                        
    };
}




