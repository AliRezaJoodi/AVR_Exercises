// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include <changed.h>

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input){
    ADMUX=adc_input | ADC_VREF_TYPE;
    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);
    // Start the AD conversion
    ADCSRA|=(1<<ADSC);
    // Wait for the AD conversion to complete
    while ((ADCSRA & (1<<ADIF))==0);
    ADCSRA|=(1<<ADIF);
    return ADCW;
}

void ADC_Config(void);
void UART_Config(void);
void UART_MonitorTemp1_f32(float value);
void UART_MonitorTemp2_f32(float value);

void main(void){
    float buf=0;
      
    uint16_t input1_u16=0; 
    uint16_t input1_last_u16=0;    
    
    uint16_t input2_u16=0; 
    uint16_t input2_last_u16=0;    
        
    ADC_Config();
    UART_Config();
         
    putsf("Loading ...\r");
    delay_ms(500);
           
    while(1){
        input1_u16 = read_adc(ADC_CH1);
        if(Changed_UpdateExact_u16(input1_u16, &input1_last_u16)){      //Difference = 4.88 mv
            buf = input1_u16 * 4.8875855;
            UART_MonitorTemp1_f32(buf);
        }
          
//        input2_u16 = read_adc(ADC_CH2);
//        if(Changed_UpdateExact_u16(input2_u16, &input2_last_u16)){      //Difference = 4.88 mv
//            buf = input2_u16 * 4.8875855;
//            UART_MonitorTemp2_f32(buf);
//        }
          
        input2_u16 = read_adc(ADC_CH2);
        if(Changed_UpdateThreshold_u16(input2_u16, &input2_last_u16, 20)){   //Difference = (4.88 mv)*x
            buf = input2_u16 * 4.8875855;
            UART_MonitorTemp2_f32(buf);
        }                                            
    };

}

//********************************************************
void UART_MonitorTemp1_f32(float value){ 
    char txt[16];     

    itoa(value,txt);
    putsf("\rVolt1(mv)= "); puts(txt);  
}

//********************************************************
void UART_MonitorTemp2_f32(float value){ 
    char txt[16];     

    itoa(value,txt);
    putsf("\rVolt2(mv)= "); puts(txt);  
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

//********************************************************
void ADC_Config(void){
    // ADC initialization
    // ADC Clock frequency: 500.000 kHz
    // ADC Voltage Reference: AVCC pin
    // ADC Auto Trigger Source: ADC Stopped
    ADMUX=ADC_VREF_TYPE;
    ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (1<<ADPS0);
    SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
}



