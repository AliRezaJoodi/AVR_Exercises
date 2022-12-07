// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>
#include <stdlib.h>

#include <Attachment\Converter_MsbLsb.h>

#ifndef RLY0_DDR
    #define RLY0_DDR DDRB.0
    #define RLY0_PORT PORTB.0
    #define RLY0_PIN PINB.0 
#endif
#define RLY0 RLY0_PORT
#define RLY0_INDEX 0

#ifndef ACTIVATE_RLY
    #define ACTIVATE_RLY 1
#endif
#define DEACTIVATE_RLY !ACTIVATE_RLY
#define DEFAULT_RLY DEACTIVATE_RLY

void Config_LCD(void);
void Display_Loading(void);
void Display_MainPage(void);
void Config_USART(void);
void Send_UART(void);
void Config_IO(void);

unsigned int number=300;
unsigned char number_msb;
unsigned char number_lsb;
char relay_status=0;
char cs=0;

void main(void){
    Config_LCD(); 
    Display_Loading();
    Config_USART();
    Config_IO();
    Display_MainPage(); 
    
    while(1){
        ++number;
        number_msb=Get_Msb(number);
        number_lsb=Get_Lsb(number);
        //number=Get_Int(number_msb,number_lsb);
        if(relay_status){relay_status=0; RLY0=DEACTIVATE_RLY;} else {relay_status=1; RLY0=ACTIVATE_RLY;};
        Display_MainPage();
        Send_UART();
        delay_ms(1000);   
    }     
}

//**************************************************
void Send_UART(void){
    UDR=0xEB; delay_ms(5); 
    UDR=number_msb; delay_ms(5);
    UDR=number_lsb; delay_ms(5);
    UDR=relay_status; delay_ms(5);
    cs=(0xEB+number_msb+number_lsb+relay_status); UDR=cs; delay_ms(5);
}

//**************************************************
void Display_MainPage(void){
    char txt[16];
    itoa(number,txt); lcd_gotoxy(0,0); lcd_putsf("Number:"); lcd_puts(txt); lcd_putsf("  ");  
    itoa(number_msb,txt); lcd_gotoxy(0,1); lcd_putsf("MSB:"); lcd_puts(txt); lcd_putsf("  "); 
    itoa(number_lsb,txt); lcd_gotoxy(7,1); lcd_putsf("LSB:"); lcd_puts(txt); lcd_putsf("  ");
    //lcd_gotoxy(0,1); lcd_putsf("Byte to VB6");
}

//********************************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Display_Loading(void){
    lcd_clear(); 
    lcd_gotoxy(0,0); lcd_putsf("Testing the LCD");
    lcd_gotoxy(0,1); lcd_putsf("Loading ...");
    delay_ms(500); lcd_clear();
}

//********************************************************
void Config_USART(void){
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

//********************************************************
void Config_IO(void){
    #define INPUT 0   
    #define OUTPUT !INPUT
    RLY0_DDR=OUTPUT; RLY0_PORT=DEFAULT_RLY; 
}
