// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "Attachment\hardware_v1.0.h"
#include <adc.h>
#include <sensor_lm35.h>
///#include <average_static.h>
#include <changed_pointer.h>

#pragma used+
void UART_Config(void);
void UART_MonitorTemp1_f32(float value);
void UART_MonitorTemp2_f32(float value);
#pragma used-

void main(void){
    float buf=0;
      
    uint16_t input1_u16=0; 
    uint16_t input1_u16_last=0;    
    
    uint16_t input2_u16=0; 
    uint16_t input2_u16_last=0;    
        
    ADC_Config_AVCC_10Bit();
    UART_Config();     
    putsf("Loading ...\r");  
    delay_ms(500);
           
    while(1){
          input1_u16 = ADC_GetCounts(LM35_CH);
          ///input1_u16 = Average_BlockUpdate_u16(input1_u16);
          if(Changed_Exact_u16(input1_u16, &input1_u16_last)){      //Difference = 0.488^c
            buf = ADC_ConvertCountsToMilliVolt(input1_u16);
            buf = LM35_ConvertMilliVoltToTemp_Celsius(buf);
            UART_MonitorTemp1_f32(buf);
          }
          
          input2_u16 = ADC_GetCounts(LM35_CH2);
          if(Changed_Exact_u16(input2_u16, &input2_u16_last)){      //Difference = 0.488^c
            buf = ADC_ConvertCountsToMilliVolt(input2_u16);
            buf = LM35_ConvertMilliVoltToTemp_Celsius(buf);
            UART_MonitorTemp2_f32(buf);
          }
          
//          input2_u16 = ADC_GetCounts(LM35_CH2);
//          if(Changed_Threshold_u16(input2_u16, &input2_u16_last, 2)){   //Difference = (0.488^c)*2
//            buf = ADC_ConvertCountsToMilliVolt(input2_u16);
//            buf = LM35_ConvertMilliVoltToTemp_Celsius(buf);
//            UART_MonitorTemp2_f32(buf);
//          }                                            
    };

}

//********************************************************
void UART_MonitorTemp1_f32(float value){ 
    char txt[16];     

    ftoa(value,1,txt);
    putsf("\rTemp1(^C)= "); puts(txt);  
}

//********************************************************
void UART_MonitorTemp2_f32(float value){ 
    char txt[16];     

    ftoa(value,1,txt);
    putsf("\rTemp2(^C)= "); puts(txt);  
}

//********************************************************
void UART_Config(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: Off
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
    UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
    UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
    UBRRH=0x00;
    UBRRL=0x33;
}


