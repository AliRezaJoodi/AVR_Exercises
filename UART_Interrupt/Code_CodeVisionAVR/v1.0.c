// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <stdio.h>
#include <stdlib.h>

void test(char buffer_uart){ 
    char buffer_txt[16];       
    putsf("\rASCII Decimal: "); itoa(buffer_uart,buffer_txt); puts(buffer_txt); 
    putsf("\rASCII Char:    "); putchar(buffer_uart);
    putsf("\r");
}

#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)
#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)

// USART Receiver buffer
#define RX_BUFFER_SIZE 8
char rx_buffer[RX_BUFFER_SIZE];

#if RX_BUFFER_SIZE <= 256
unsigned char rx_wr_index=0,rx_rd_index=0;
#else
unsigned int rx_wr_index=0,rx_rd_index=0;
#endif

#if RX_BUFFER_SIZE < 256
unsigned char rx_counter=0;
#else
unsigned int rx_counter=0;
#endif

// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;

// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void){
    char status,data;
    status=UCSRA;
    data=UDR;
    if((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0){
        rx_buffer[rx_wr_index++]=data;
        #if RX_BUFFER_SIZE == 256
        // special case for receiver buffer size=256
        if (++rx_counter == 0) rx_buffer_overflow=1;
        #else
        if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
        if (++rx_counter == RX_BUFFER_SIZE){
            rx_counter=0;
            rx_buffer_overflow=1;
        }
        #endif 
        test(data);
    }
}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void){
    char data;
    while (rx_counter==0);
    data=rx_buffer[rx_rd_index++];
    #if RX_BUFFER_SIZE != 256
    if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
    #endif
    #asm("cli")
    --rx_counter;
    #asm("sei")
    return data;
}
#pragma used-
#endif

    
void main(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
    UCSRB=(1<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
    UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
    UBRRH=0x00;
    UBRRL=0x33;
    
    #asm("sei") // Global enable interrupts
    
    putsf("\rPress any key:");
    
    while(1){
    }
}

