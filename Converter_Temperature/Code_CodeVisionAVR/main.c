// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>

#include <converter_temp.h>

void UART_Config(void);

void main(void){
    float temp_c = 50;
    float temp_k = 0;
    float temp_f = 0;
    
    char txt[16];
         
    UART_Config();         
    putsf("Loading ...\r");
    
    temp_k = Converter_Temp_CtoK(temp_c);
    ftoa(temp_k, 2, txt); putsf("\rTemp(^K): "); puts(txt); 
    
    temp_f = Converter_Temp_CtoF(temp_c);
    ftoa(temp_f, 2, txt); putsf("\rTemp(^F): "); puts(txt); 
    
    temp_c = Converter_Temp_KtoC(temp_k);
    ftoa(temp_c, 2, txt); putsf("\rTemp(^C): "); puts(txt); 

    temp_f = Converter_Temp_KtoF(temp_k);
    ftoa(temp_f, 2, txt); putsf("\rTemp(^F): "); puts(txt); 
        
    temp_c = Converter_Temp_FtoC(temp_f);
    ftoa(temp_c, 2, txt); putsf("\rTemp(^C): "); puts(txt);
    
    temp_k = Converter_Temp_FtoK(temp_f);
    ftoa(temp_k, 2, txt); putsf("\rTemp(^K): "); puts(txt);
           
    while(1){                                    
    };
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



