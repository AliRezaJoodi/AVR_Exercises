// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <mega32a.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port = 0x1b ;PORTA
#endasm
#include <lcd.h>

#include "hardware.h"
#include "sht1x.h"

float temperature = 0;
float humidity = 0;

void Display_Values(void);
void UART_Config(void);
void UART_Display_i16(int16_t in);
void UART_Display_u16(uint16_t in);

void main(void){
    const SHT1x_t sht1 = {
        .sck = {
            .ddr   = &SHT1X_SCK_DDR,
            .port  = &SHT1X_SCK_PORT,
            .pin   = &SHT1X_SCK_PIN,
            .index = SHT1X_SCK_BIT
        },
        .data = {
            .ddr   = &SHT1X_DATA_DDR,
            .port  = &SHT1X_DATA_PORT,
            .pin   = &SHT1X_DATA_PIN,
            .index = SHT1X_DATA_BIT
        }
    };

    uint16_t temp = 0;
    uint8_t buf_u8 = 0;
    uint16_t buf_u16 = 0;

    lcd_init(16);
    lcd_clear();
    SHT1x_Init(&sht1);
    UART_Config();
    putsf("Test");
    //UART_Display_i16(12380);

    DDRB.0 = 1;

    while(1){
        PORTB.0 = ~PORTB.0;
//        humidity = Get_Humidity(&sht1);
//        temperature =  SHT1x_GetTemperature_(&sht1);
//        Display_Values();

        //SHT1x_ResetConnection(&sht1);
//        temp =  SHT1x_GetTemperature(&sht1);
//        putsf("\rTemperature(^C)= "); UART_Display_i16(temp);

        buf_u8 = SHT1x_StartMeasurement(&sht1, CMD_MEASURE_TEMPERATURE);
        if (buf_u8 != 0) {
            SHT1x_ResetConnection(&sht1);
        }
        //putsf("\rTest2");
        //while(SHT1x_DATA_GetPin(&sht1));
        delay_ms(400);
        buf_u16 = ReadSO(&sht1, CMD_MEASURE_TEMPERATURE);
        putsf("\rTemperature(^C)= "); UART_Display_u16(buf_u16);

        //SHT1x_SoftReset(&sht1);
        delay_ms(500);
    }
}

//***********************************
void UART_Display_u16(uint16_t in){
    char txt[];

    itoa(in, txt);
    puts(txt);
    putsf("\r");
}

//***********************************
void UART_Display_i16(int16_t in){
    char txt[];

    itoa(in, txt);
    puts(txt);
    putsf("\r");
}

//***********************
void Display_Values(void){
    char txt[16];
    lcd_clear();
    //sprintf(txt,"Humidity(%%)=%3.1f",humidity); lcd_gotoxy(0,0); lcd_puts(txt);
    sprintf(txt,"Temp(C)=%3.1f",temperature); lcd_gotoxy(0,1); lcd_puts(txt);
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
