// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega16a.h>
#include <delay.h>

#include "hardware.h"
#include <tm1638.h>

void UART_Config(void);
  
void main(void){
    char txt[]; 
    uint8_t i=0;
    uint16_t led_u16 =0;
    uint8_t led_u8 =0; 
    uint8_t segments[16]; 
    uint8_t key_last = 0;        
    uint8_t key[4] = {0x00, 0x00, 0x00, 0x00,};

    TM1638_t tm1;
    tm1.stb.ddr     = &TM1638_STB1_DDR;
    tm1.stb.port    = &TM1638_STB1_PORT;
    tm1.stb.index   =  TM1638_STB1_BIT;
        
    UART_Config();             
    TM1638_Config(&tm1);

//*****************************************************
    for(i=0; i<16; ++i){
        WRITE_BIT(led_u16, i, 1);
        TM1638_Set16Leds(&tm1, led_u16);
        delay_ms(500);
    }
     
    for(i=0; i<16; ++i){
        WRITE_BIT(led_u16, i, 0);
        TM1638_Set16Leds(&tm1, led_u16);
        delay_ms(500);
    }
         
    TM1638_ClearDisplay(&tm1); delay_ms(1000);

//*****************************************************
    for(i=0; i<8; ++i){
        WRITE_BIT(led_u8, i, 1);
        TM1638_Set8Leds(&tm1, led_u8);
        delay_ms(500);
    } 
    
    for(i=0; i<8; ++i){
        WRITE_BIT(led_u8, i, 0);
        TM1638_Set8Leds(&tm1, led_u8);
        delay_ms(500);
    }
       
    TM1638_ClearDisplay(&tm1); delay_ms(1000);

//*****************************************************
    segments[0]=0x3FU;      // 0
    segments[1]=0b00000001;    
    segments[2]=0x06U;      // 1 
    segments[3]=0b00000001;  
    segments[4]=0x5BU;      // 2 
    segments[5]=0b00000000; 
    segments[6]=0x4FU;      // 3
    segments[7]=0b00000000;  
    segments[8]=0x66U;      // 4    
    segments[9]=0b00000000; 
    segments[10]=0x6DU;     // 5 
    segments[11]=0b00000000; 
    segments[12]=0x7DU;     // 6
    segments[13]=0b00000000;  
    segments[14]=0x07U;     // 7
    segments[15]=0b00000000; 
               
    TM1638_Set8SegmentsAndLeds(&tm1, segments, 16, 0); delay_ms(1000);

//*****************************************************            
    TM1638_SetDisplay(&tm1, 1, 0); delay_ms(1000);
    TM1638_SetDisplay(&tm1, 1, 1); delay_ms(1000);
    TM1638_SetDisplay(&tm1, 1, 2); delay_ms(1000);
    TM1638_SetDisplay(&tm1, 1, 3); delay_ms(1000);
    TM1638_SetDisplay(&tm1, 1, 4); delay_ms(1000);
    TM1638_SetDisplay(&tm1, 1, 5); delay_ms(1000);
    TM1638_SetDisplay(&tm1, 1, 6); delay_ms(1000); 
    TM1638_SetDisplay(&tm1, 1, 7); delay_ms(1000);
    TM1638_ClearDisplay(&tm1); delay_ms(1000);
    
//*****************************************************  
    TM1638_SetFixedAddress(&tm1, 0b00000001, 0x0F); delay_ms(1000);
    TM1638_SetFixedAddress(&tm1, 0b00000001, 0x01); delay_ms(1000);
    
//*****************************************************        
    segments[0]=0x3FU;      // 0 
    segments[1]=0x06U;      // 1 
    segments[2]=0x5BU;      // 2 
    segments[3]=0x4FU;      // 3 
    segments[4]=0x66U;      // 4    
    segments[5]=0x6DU;      // 5 
    segments[6]=0x7DU;      // 6 
    segments[7]=0x07U;      // 7     
    
    TM1638_Set8Segments(&tm1, segments, 8, 0); delay_ms(1000);
    TM1638_ClearDisplay(&tm1);  delay_ms(1000);
        
//*****************************************************    
    TM1638_SendCommand(&tm1, 0b10000111); delay_ms(1000); 
    TM1638_SetDisplay(&tm1, 1, 7); delay_ms(1000);    
    TM1638_ClearDisplay(&tm1); delay_ms(1000);

//*****************************************************
    TM1637_Set8Segments_4Digits_1st(&tm1, segments); delay_ms(1000);
    TM1638_ClearDisplay(&tm1);  delay_ms(1000); 
     
    TM1637_Set8Segments_4Digits_2nd(&tm1, segments); delay_ms(1000);
    TM1638_ClearDisplay(&tm1);  delay_ms(1000);
    
//*****************************************************     
//    TM1638_Get24Buttons(&tm1, &key[0]); 
        
    while(1){  
        TM1638_Get8Buttons(&tm1, &key[0]);      
//        key[0] = TM1638_Return8Buttons(&tm1);
        if(key_last != key[0]){
            key_last = key[0];
            if(key[0] != 0){
                //itoa(key[0], txt); puts(txt); puts("\r");
                sprintf(txt, "0x%02X\r", key[0]); puts(txt);
                delay_ms(50); 
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
