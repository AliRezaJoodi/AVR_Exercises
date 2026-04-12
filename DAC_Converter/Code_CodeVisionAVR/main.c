// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "dac_converter.h"

void UART_Config(void);
void UART_Display1(uint16_t in, uint16_t out);
void UART_Display2(uint32_t in, uint16_t out);

void main(void){
    uint16_t mv = 0;
    uint32_t uv = 0;
    uint16_t dac_count = 0;

    UART_Config();

    putsf("\rDAC_ConvertMilliVoltToCount_12Bit4V096\r");
    mv = 4096 / 2;
    dac_count = DAC_ConvertMilliVoltToCount_12Bit4V096(mv);
    UART_Display1(mv, dac_count);

    putsf("\rDAC_ConvertMicroVoltToCount_12Bit2V048\r");
    uv = 2048000 / 2;
    dac_count = DAC_ConvertMicroVoltToCount_12Bit2V048(uv);
    UART_Display2(uv, dac_count);

    putsf("\rDAC_ConvertMilliVoltToCount_10Bit5V\r");
    mv = 5000 / 2;
    dac_count = DAC_ConvertMilliVoltToCount_10Bit5V(mv);
    UART_Display1(mv, dac_count);

    putsf("\rDAC_ConvertMilliVoltToCount_10Bit4V096\r");
    mv = 4096 / 2;
    dac_count = DAC_ConvertMilliVoltToCount_10Bit4V096(mv);
    UART_Display1(mv, dac_count);

    putsf("\rDAC_ConvertMilliVoltToCount_10Bit3V3\r");
    mv = 3300 / 2;
    dac_count = DAC_ConvertMilliVoltToCount_10Bit3V3(mv);
    UART_Display1(mv, dac_count);

    putsf("\rDAC_ConvertMilliVoltToCount_10Bit2V048\r");
    mv = 2048 / 2;
    dac_count = DAC_ConvertMilliVoltToCount_10Bit2V048(mv);
    UART_Display1(mv, dac_count);

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
void UART_Display2(uint32_t in, uint16_t out){
    char txt[20];

    putsf("In:");
    ltoa(in, txt);
    puts(txt);

    putsf("  Out:");
    itoa(out, txt);
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




