// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "adc_converter.h"

void UART_Config(void);
void UART_Display1(uint16_t adc_count, uint16_t mv);
void UART_Display2(uint16_t adc_count, uint32_t uv);

void main(void){
    uint16_t adc_count = 0;
    uint16_t mv = 0;
    uint32_t uv = 0;

    UART_Config();

    putsf("\rADC_ConvertCountToMilliVolt_12Bit5V\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_12Bit5V(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 4096;
    mv = ADC_ConvertCountToMilliVolt_12Bit5V(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMilliVolt_12Bit4V096\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_12Bit4V096(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 4096;
    mv = ADC_ConvertCountToMilliVolt_12Bit4V096(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMicroVolt_12Bit3V3\r");
    adc_count = 1;
    uv = ADC_ConvertCountToMicroVolt_12Bit3V3(adc_count);
    UART_Display2(adc_count, uv);
    adc_count = 4096;
    uv = ADC_ConvertCountToMicroVolt_12Bit3V3(adc_count);
    UART_Display2(adc_count, uv);

    putsf("\rADC_ConvertCountToMicroVolt_12Bit2V048\r");
    adc_count = 1;
    uv = ADC_ConvertCountToMicroVolt_12Bit2V048(adc_count);
    UART_Display2(adc_count, uv);
    adc_count = 4096;
    uv = ADC_ConvertCountToMicroVolt_12Bit2V048(adc_count);
    UART_Display2(adc_count, uv);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit5V\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_10Bit5V(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 1024;
    mv = ADC_ConvertCountToMilliVolt_10Bit5V(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit4V096\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_10Bit4V096(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 1024;
    mv = ADC_ConvertCountToMilliVolt_10Bit4V096(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit2V56\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_10Bit2V56(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 1024;
    mv = ADC_ConvertCountToMilliVolt_10Bit2V56(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit2V048\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_10Bit2V048(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 1024;
    mv = ADC_ConvertCountToMilliVolt_10Bit2V048(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMilliVolt_8Bit5V\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_8Bit5V(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 255;
    mv = ADC_ConvertCountToMilliVolt_8Bit5V(adc_count);
    UART_Display1(adc_count, mv);

    putsf("\rADC_ConvertCountToMilliVolt_8Bit2V56\r");
    adc_count = 1;
    mv = ADC_ConvertCountToMilliVolt_8Bit2V56(adc_count);
    UART_Display1(adc_count, mv);
    adc_count = 255;
    mv = ADC_ConvertCountToMilliVolt_8Bit2V56(adc_count);
    UART_Display1(adc_count, mv);

    while(1){
    };
}

//********************************************************
void UART_Display1(uint16_t adc_count, uint16_t mv){
    char txt[20];

    putsf("In:");
    itoa(adc_count, txt);
    puts(txt);

    putsf("  Out:");
    itoa(mv, txt);
    puts(txt);

    putsf("\r");
}

//********************************************************
void UART_Display2(uint16_t adc_count, uint32_t uv){
    char txt[20];

    putsf("In:");
    itoa(adc_count, txt);
    puts(txt);

    putsf("  Out:");
    ltoa(uv, txt);
    puts(txt);

    putsf("\r");
}

//********************************************************
void UART_Config(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
    UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
    UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
    UBRRH=0x00;
    UBRRL=0x47;
}




