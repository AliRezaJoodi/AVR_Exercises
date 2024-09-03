// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef _MCP3204_INCLUDED
#define _MCP3204_INCLUDED

#ifndef _MCP3204_PORTS
#define _MCP3204_PORTS
    #define MCP3204_CS_DDR      DDRB.4
    #define MCP3204_CS_PORT     PORTB.4
    #define MCP3204_CS_PIN      PINB.4 
    
    #define MCP3204_VREF        5000     //mv
#endif
#define MCP3204_CS              MCP3204_CS_PORT 

#define _MCP3204_RESOLUTION     4096     //12-Bit
#define _MCP3204_GAIN           MCP3204_VREF/_MCP3204_RESOLUTION
    
#define _SINGLE_CHANNEL         1 
#define _DIFF_CHANNEL           0  

//********************************************************
void MCP3204_Config(void){
    MCP3204_CS_DDR=1; 
    MCP3204_CS_PORT=1;   
}

#pragma used+

//********************************************************
unsigned int _MCP3204_Communication(char data1, char data2){
    unsigned int value=0;
    unsigned char msb=0;
    unsigned char lsb=0;
    
    MCP3204_CS=0;
    spi(data1);
    msb=spi(data2); 
    lsb=spi(0xFF);
    MCP3204_CS=1;
    
    msb=msb&0b00001111; 
    value=(msb<<8)|lsb;

    return value;
}

//********************************************************
float MCP3204_GetSingleEndedADC(char ch){
    char data1=0;
    char data2=0;
    unsigned int value_int=0;
    float mv=0; 
    char type=_SINGLE_CHANNEL;
    
    if(ch>3){return 0;}

    data1=0b00000100 | (type<<1);
    data2=ch<<6; 

    value_int=_MCP3204_Communication(data1, data2); 
    mv=value_int; mv=mv*_MCP3204_GAIN;

    return mv;
}

//********************************************************
float MCP3204_GetDifferentialADC(char ch){
    char data1=0;
    char data2=0;
    unsigned int value_int=0;
    float mv=0;
    char type=_DIFF_CHANNEL;
        
    switch (ch){
        case 01:
            ch=0b00000000; break;
        case 10:
            ch=0b00000001; break; 
        case 23:
            ch=0b00000010; break;
        case 32:
            ch=0b00000011; break;
        default:
            return 0;
    }
        
    data1=0b00000100 | (type<<1);
    data2=ch<<6;

    value_int=_MCP3204_Communication(data1, data2); 
    mv=value_int; mv=mv*_MCP3204_GAIN;

    return mv;
}

#pragma used-
#endif

