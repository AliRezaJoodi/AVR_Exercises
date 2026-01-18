// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void UART_Config(void);
void test1(void);
void test2(void);
    
void main(void){    
    char txt[];
    uint8_t value = 25;
        	
    UART_Config();
    //test1();
    //test2();
    
    sprintf(txt, "value= %d", value);
    puts(txt);
    	
    while(1){ 
    }
}

//********************************************************
void test2(void){
    char txt[2];
    putsf("\r*** Function ***");
    putsf("\rEnter 2 char string:"); 
    gets(txt,2);
    puts(txt);
}

//********************************************************
void test1(void){
    char txt[]; 
    uint8_t buf = 0;
    putsf("\r*** Function ***");
    putsf("\rPress any key:"); 
    buf = getchar();         
    putsf("\rASCII Decimal: "); itoa(buf,txt); puts(txt); 
    putsf("\rASCII Char:    "); putchar(buf);
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