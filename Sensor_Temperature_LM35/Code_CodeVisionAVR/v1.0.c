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

#include "Attachment\HardwarePorting_v1.0.h"
#include <ADC.h>
#include <Sensor_LM35.h>
#include "Attachment\LCD.h"
#include <Display_LCD_Char.h>

void main(void){
    LCD_Config();
    Char_Define(char0, 0);
    ADC_Config_AVCC_10Bit();

    while(1){ 
        input_mv=ADC_GetMilliVolt(LM35_CH); 
        temp=LM35_ConvertMilliVoltToTemp(input_mv);
        LCD_DisplayMainPage(input_mv,temp);
        delay_ms(250);                                       
    };
}



