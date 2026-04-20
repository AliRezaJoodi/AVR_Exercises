// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include "utils/array.h"

void UART_Init(void);
void UART_DisplayValues(unsigned int);

void main(void){
    uint16_t buf_u16 = 0;
    int16_t buf_i16 = 0;
    uint32_t buf_u32 = 0;
    float buf_f32=0;
    uint8_t i = 0;

    uint16_t array1[10] = {
        4821,
        157,
        9023,
        611,
        7420,
        3189,
        655,
        1204,
        8891,
        4302
    };

    char txt[16];

    UART_Init();
    putsf("Test\r");

    buf_u16 = Array_Min_u16(array1, ARRAY_SIZE(array1));
    itoa(buf_u16, txt); putsf("\rMin = "); puts(txt);

    buf_u16 = Array_Max_u16(array1, ARRAY_SIZE(array1));
    itoa(buf_u16, txt); putsf("\rMax = "); puts(txt);

    buf_u16 = Array_Average_u16(array1, ARRAY_SIZE(array1));
    itoa(buf_u16, txt); putsf("\rAverage = "); puts(txt);

    buf_i16 = Array_Find_u16(array1, ARRAY_SIZE(array1), 8891);
    itoa(buf_i16, txt); putsf("\rFind(Index) = "); puts(txt);

    Array_Reverse_u16(array1, ARRAY_SIZE(array1));
    putsf("\r"); putsf("\r"); putsf("Array(Reverse):\r");
    for (i=0; i<10; ++i){
        buf_u16 = array1[i];
        itoa(buf_u16, txt); puts(txt); putsf("\r");
    }

    Array_Clear_u16(array1, ARRAY_SIZE(array1));
    putsf("\r"); putsf("Array(Clear):\r");
    for (i=0; i<10; ++i){
        buf_u16 = array1[i];
        itoa(buf_u16, txt); puts(txt); putsf("\r");
    }

    //itoa(value_u8, txt); putsf("\rBuffer="); puts(txt);
    //ltoa(value_u32, txt); putsf("\rBuffer="); puts(txt);
    //ftoa(buf1_u32, 0, txt); putsf("\rBuffer="); puts(txt);

    while(1){
    }
}

//********************************************************
void UART_DisplayValues(unsigned int x){
    char txt[16];
    //putsf("\rCount=");
    itoa(x,txt); puts(txt);
    //putsf("\rt2="); itoa(t2,txt); puts(txt);
    //putsf("\r");
}

//********************************************************
void UART_Init(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRH=0x00;
    UBRRL=0x33;
}