// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega16.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char buffer_uart;
char buffer_txt[16];

void Config_USART(void);
void test1(void);
void test2(void);
    
void main(void){    	
    Config_USART();
    test1();
    test2();
    	
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
    putsf("\r*** Function ***");
    putsf("\rPress any key:"); 
    buffer_uart=getchar();         
    putsf("\rASCII Decimal: "); itoa(buffer_uart,buffer_txt); puts(buffer_txt); 
    putsf("\rASCII Char:    "); putchar(buffer_uart);
    putsf("\r");
}

//********************************************************
void Config_USART(void){
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