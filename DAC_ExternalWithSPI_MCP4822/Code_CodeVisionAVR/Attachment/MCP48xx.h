// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _MCP48xx_INCLUDED_
    #define _MCP48xx_INCLUDED_

#include <spi.h>
#include <delay.h>

#ifndef _MCP48xx_PORTS_
    #define _MCP48xx_PORTS_
    
    #define CS_MCP48XX_DDR      DDRB.3
    #define CS_MCP48XX_PORT     PORTB.3
    #define CS_MCP48XX_PIN      PINB.3
    #define CS_MCP48XX          CS_MCP48XX_PORT
    
    #define LDAC_DDR            DDRB.2
    #define LDAC_PORT           PORTB.2
    #define LDAC_PIN            PINB.2
    #define LDAC_MCP48XX        LDAC_PORT
    
    #define VREF_MCP48XX        2.048   //V
    #define RESOLUTION_MCP4802  255   	//8-Bit  
    #define RESOLUTION_MCP4812  1023  	//10-Bit 
    #define RESOLUTION_MCP4822  4095  	//12-Bit
    #define GAIN_MCP4822        VREF_MCP48XX/RESOLUTION_MCP4822               
#endif

#pragma used+

//********************************************************
void _Config_SPI(void){
    DDRB.4=1; PORTB.4=0;    //SS
    DDRB.5=1; PORTB.5=0;    //MOSI
    DDRB.6=0; PORTB.6=0;    //MISO
    DDRB.7=1; PORTB.7=0;    //SCK

    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 2000.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);
}

//********************************************************
void Config_MCP48xx(void){
    _Config_SPI();
    CS_MCP48XX_DDR=1; CS_MCP48XX_PORT=1; 
    LDAC_DDR=1; LDAC_PORT=1;
}

//********************************************************
void _Set_MCP48xx(char data1, char data2){
    CS_MCP48XX=0;
    spi(data1); spi(data2); 
    CS_MCP48XX=1;
    LDAC_MCP48XX=0; delay_us(1); LDAC_MCP48XX=1;
}

//********************************************************
void Set_MCP4822(float volt, char ch){
    char data1=0;
    char data2=0;
    unsigned int value_int=0;
    
    if(volt>4.095){volt=4.095;};
    volt=volt*4096/2.048;
    if(volt<=4095){
        value_int=volt;
        data1=value_int>>8;
        data1=data1|0b00110000; 
        data2=value_int&0x00FF;
    }
    else{
        value_int=volt/2;
        data1=value_int>>8;
        data1=data1|0b00010000; 
        data2=value_int&0x00FF;
    }
    
    if(ch<=1){
        ch=ch<<7; data1=data1|ch;
        _Set_MCP48xx(data1, data2);
    }
}

//********************************************************
void ShutDown_MCP48xx(char ch){
    char data1=0;
    
    if(ch<=1){
        data1=ch<<7;
        _Set_MCP48xx(data1, 0);
    }
}

#pragma used-

#endif

