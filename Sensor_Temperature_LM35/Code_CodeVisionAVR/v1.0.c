// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

#pragma used+

float input_mv=0;
float input_v=0;
float temp=0;
#pragma used-

#include <Attachment\_LCD.h>
#include <ADC.h>
#include <Sensor_LM35.h>
#include <Attachment\Character.h>

void main(void){

    Config_LCD();
    define_char(CHAR1,0);
    ADC_Config_10Bit_AVCC();

    while(1){ 
        input_mv=ADC_GetMilliVolt(LM35_CH); 
        temp=LM35_ConvertMilliVoltToTemp(input_mv);
        Display_LCD(input_mv,temp);
        delay_ms(250);                                       
    };
}



