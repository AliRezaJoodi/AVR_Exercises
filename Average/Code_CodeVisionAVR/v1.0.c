// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

#pragma used+
//unsigned int input_int=0;
float input_mv=0;
float input_v=0;
float temp=0;
#pragma used-

#include "Attachment\HardwarePorting_v1.0.h"
#include <ADC.h>
#include <Sensor_LM35.h>
#include <Average.h>
#include "Attachment\_LCD.h"
#include "Attachment\Character.h"


void main(void){
    Config_LCD();
    ADC_Config_AVCC_10Bit();
    define_char(CHAR1,0); 
    
    while(1){ 
        input_v=ADC_GetVolt(LM35_CH); 
        temp=LM35_ConvertVoltToTemp(input_v);
        temp=Average(temp);
        Display_LCD(temp);
        delay_ms(250);                                        
    };
}




