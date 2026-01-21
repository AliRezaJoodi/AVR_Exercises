// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega16a.h>
#include <delay.h>
#include <stdint.h>
#include <stdio.h>
//#include <stdlib.h>

#include <display7segment1digit_decoder.h>
#include <tm1638.h>

void UART_Config(void);

void main(void){
    char txt[];
    uint8_t key_last =0;
    
    uint8_t key[4]={
        0b00000000,   
        0b00000001,
        0b00000010,
        0b00000100,
    };
    
    uint8_t segments[16];
    
    UART_Config();             
    TM1638_Config();
        
    Display7Segment1Digit_DecodeDigit(0, &segments[0]);
    segments[1]=0b00000001;    
    Display7Segment1Digit_DecodeDigit(1, &segments[2]); 
    segments[3]=0b00000001;  
    Display7Segment1Digit_DecodeDigit(2, &segments[4]); 
    segments[5]=0b00000000; 
    Display7Segment1Digit_DecodeDigit(3, &segments[6]); 
    segments[7]=0b00000000;  
    Display7Segment1Digit_DecodeDigit(4, &segments[8]);    
    segments[9]=0b00000000; 
    Display7Segment1Digit_DecodeDigit(5, &segments[10]); 
    segments[11]=0b00000000; 
    Display7Segment1Digit_DecodeDigit(6, &segments[12]); 
    segments[13]=0b00000000;  
    Display7Segment1Digit_DecodeDigit(7, &segments[14]); 
    segments[15]=0b00000000; 
               
    TM1638_SetSegments_Seg1ToSeg10(segments, 16, 0); delay_ms(1000);
    TM1638_SetDisplay(1, 0); delay_ms(1000);
    TM1638_SetDisplay(1, 1); delay_ms(1000);
    TM1638_SetDisplay(1, 2); delay_ms(1000);
    TM1638_SetDisplay(1, 3); delay_ms(1000);
    TM1638_SetDisplay(1, 4); delay_ms(1000);
    TM1638_SetDisplay(1, 5); delay_ms(1000);
    TM1638_SetDisplay(1, 6); delay_ms(1000); 
    TM1638_SetDisplay(1, 7); delay_ms(1000);
    TM1638_ResetSegments_Seg1ToSeg10(); delay_ms(1000);

    TM1638_SetSegments_FixedAddress(0b00000001, 0x0F); delay_ms(1000);
    TM1638_SetSegments_FixedAddress(0b00000001, 0x01); delay_ms(1000);
    TM1638_ResetSegments_Seg1ToSeg10(); delay_ms(1000);

    TM1638_SetLeds_Seg9Seg10(0x0004); delay_ms(1000);  
    TM1638_SetLeds_Seg9Seg10(0x1000); delay_ms(1000);
    
    TM1638_SetLeds_Seg9(0x08); delay_ms(1000);  
    TM1638_SetLeds_Seg9(0x80); delay_ms(1000);
            
    Display7Segment1Digit_DecodeDigit(9, &segments[0]);    
    Display7Segment1Digit_DecodeDigit(0, &segments[1]); 
    Display7Segment1Digit_DecodeDigit(2, &segments[2]); 
    Display7Segment1Digit_DecodeDigit(7, &segments[3]); 
    Display7Segment1Digit_DecodeDigit(4, &segments[4]); 
    Display7Segment1Digit_DecodeDigit(6, &segments[5]); 
    Display7Segment1Digit_DecodeDigit(5, &segments[6]); 
    Display7Segment1Digit_DecodeDigit(3, &segments[7]);      
    
    TM1638_SetSegments_Seg1ToSeg8_KeepSeg9Seg10(segments, 8, 0); delay_ms(1000);
    TM1638_ResetSegments_Seg1ToSeg10(); delay_ms(1000);

    TM1638_SetSegments_Seg1ToSeg8_KeepSeg9Seg10(segments, 2, 6); delay_ms(1000);
    TM1638_ResetSegments_Seg1ToSeg10(); delay_ms(1000);
        
    TM1638_SetSegments_FixedAddress(segments[6], 0); delay_ms(1000);
    
    TM1638_SendCommand(0b10000111); delay_ms(1000); 
    TM1638_SetDisplay(1, 7); delay_ms(1000);
     
    delay_ms(3000); TM1638_ResetSegments_Seg1ToSeg10();
    
    while(1){
//        TM1638_GetButtons_K1K2K3( &key[0] ); 
//        sprintf(txt, "0x%02x 0x%02x 0x%02x 0x%02x \r", key[0], key[1], key[2], key[3]); puts(txt); 
//        delay_ms (500);   
        TM1638_GetButtons_K3( &key[0] );
//        key[0] = TM1638_ReturnButtons_K3();
        if(key_last != key[0]){
            key_last = key[0];
            if( key[0] != 0){
                sprintf(txt, "0x%02x \r", key[0]);
                puts(txt);
            }
        }                              
    };
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
