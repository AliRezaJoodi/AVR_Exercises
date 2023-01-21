// GitHub Account:     GitHub.com/AliRezaJoodi

#include <spi.h>

#ifndef CS_DDR
    #define CS_DDR DDRB.3
    #define CS_PORT PORTB.3
    #define CS_PIN PINB.3 
#endif
#define CS_MCP320X CS_PORT

#ifndef SELECT
    #define SELECT 0
#endif
#define DESELECT !SELECT
#define DEFAULT DESELECT

#ifndef GAIN_ADC
    #define VREF        5000    //mV
    #define RESOLUTION  4095    //12-Bit
    #define GAIN_ADC    VREF/RESOLUTION
#endif

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
void Config_MCP320x(void){
    _Config_SPI();
    CS_DDR=1; CS_PORT=DEFAULT;
}

//********************************************************
unsigned int _Get_MCP320x(char data1, char data2){
    unsigned int value_int=0;
    unsigned char value_msb=0;
    unsigned char value_lsb=0;
    
    CS_MCP320X=SELECT;
    spi(data1);
    value_msb=spi(data2); value_msb=value_msb&0b00001111;
    value_lsb=spi(0xFF);
    CS_MCP320X=DESELECT;

    value_int=(value_msb<<8)|value_lsb;    
    return value_int;
}

//********************************************************
float _ConvertToVolt_MCP320x(unsigned int x){
    float value=x;
    value=value*GAIN_ADC/1000;
    return value;
}

//********************************************************
float GetSingle_MCP3202(char ch){
    char data1=0;
    char data2=0;
    unsigned int value_int=0;
    float value_float=0;
    
    if(ch>1){return -1;}
    
    data1=0b00000001; 
    data2=(ch|0b00000010)<<6;
    
    value_int=_Get_MCP320x(data1, data2);
    value_float=_ConvertToVolt_MCP320x(value_int);
    return value_float;
}

//********************************************************
float GetSingle_MCP3204(char ch){
    char data1=0;
    char data2=0;
    unsigned int value_int=0;
    float value_float=0;
    
    if(ch>3){return -1;}
    
    data1=(ch|0b00011000)>>2; 
    data2=ch<<6; 

    value_int=_Get_MCP320x(data1, data2);
    value_float=_ConvertToVolt_MCP320x(value_int);
    return value_float;
}

//********************************************************
float GetSingle_MCP3208(char ch){
    char data1=0;
    char data2=0;
    unsigned int value_int=0;
    float value_float=0;
    
    if(ch>7){return -1;}
    
    data1=(ch|0b00011000)>>2; 
    data2=ch<<6; 

    value_int=_Get_MCP320x(data1, data2);
    value_float=_ConvertToVolt_MCP320x(value_int);
    return value_float;
}

