// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "adc_converter.h"

void UART_Config(void);
void UART_Display1(uint16_t in, uint16_t out);
void UART_Display2(uint16_t in, uint32_t out);

void main(void){
    uint16_t in_u16 = 0;
    uint16_t out_u16 = 0;
    uint32_t out_u32 = 0;

    UART_Config();

    putsf("\rADC_ConvertCountToMilliVolt_12Bit5V\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_12Bit5V(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 4096;
    out_u16 = ADC_ConvertCountToMilliVolt_12Bit5V(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMilliVolt_12Bit4V096\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_12Bit4V096(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 4096;
    out_u16 = ADC_ConvertCountToMilliVolt_12Bit4V096(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMicroVolt_12Bit3V3\r");
    in_u16 = 1;
    out_u32 = ADC_ConvertCountToMicroVolt_12Bit3V3(in_u16);
    UART_Display2(in_u16, out_u32);
    in_u16 = 4096;
    out_u32 = ADC_ConvertCountToMicroVolt_12Bit3V3(in_u16);
    UART_Display2(in_u16, out_u32);

    putsf("\rADC_ConvertCountToMicroVolt_12Bit2V048\r");
    in_u16 = 1;
    out_u32 = ADC_ConvertCountToMicroVolt_12Bit2V048(in_u16);
    UART_Display2(in_u16, out_u32);
    in_u16 = 4096;
    out_u32 = ADC_ConvertCountToMicroVolt_12Bit2V048(in_u16);
    UART_Display2(in_u16, out_u32);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit5V\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit5V(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 1024;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit5V(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit4V096\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit4V096(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 1024;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit4V096(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit2V56\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit2V56(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 1024;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit2V56(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMilliVolt_10Bit2V048\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit2V048(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 1024;
    out_u16 = ADC_ConvertCountToMilliVolt_10Bit2V048(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMilliVolt_8Bit5V\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_8Bit5V(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 255;
    out_u16 = ADC_ConvertCountToMilliVolt_8Bit5V(in_u16);
    UART_Display1(in_u16, out_u16);

    putsf("\rADC_ConvertCountToMilliVolt_8Bit2V56\r");
    in_u16 = 1;
    out_u16 = ADC_ConvertCountToMilliVolt_8Bit2V56(in_u16);
    UART_Display1(in_u16, out_u16);
    in_u16 = 255;
    out_u16 = ADC_ConvertCountToMilliVolt_8Bit2V56(in_u16);
    UART_Display1(in_u16, out_u16);

    while(1){
    };
}

//********************************************************
void UART_Display1(uint16_t in, uint16_t out){
    char txt[20];

    putsf("In:");
    itoa(in, txt);
    puts(txt);

    putsf("  Out:");
    itoa(out, txt);
    puts(txt);

    putsf("\r");
}

//********************************************************
void UART_Display2(uint16_t in, uint32_t out){
    char txt[20];

    putsf("In:");
    itoa(in, txt);
    puts(txt);

    putsf("  Out:");
    ltoa(out, txt);
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




