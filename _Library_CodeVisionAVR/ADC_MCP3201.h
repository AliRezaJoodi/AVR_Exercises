// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef _MCP3201_INCLUDED
#define _MCP3201_INCLUDED

#ifndef _MCP3201_PORTS
#define _MCP3201_PORTS
    #define MCP3201_CS_DDR      DDRB.4
    #define MCP3201_CS_PORT     PORTB.4
    #define MCP3201_CS_PIN      PINB.4  
    
    #define MCP3201_VREF        5000     //mv
#endif
#define MCP3201_CS              MCP3201_CS_PORT

#define _MCP3201_RESOLUTION     4096     //12-Bit
#define _MCP3201_GAIN           MCP3201_VREF/_MCP3201_RESOLUTION

//********************************************************
void MCP3201_Config(void){
    MCP3201_CS_DDR=1; 
    MCP3201_CS_PORT=1;   
}

#pragma used+

//********************************************************
unsigned int _MCP3201_Communication(void){
    unsigned int value=0;
    unsigned char msb=0;
    unsigned char lsb=0;
    
    MCP3201_CS=0;
    msb=spi(0xFF); 
    lsb=spi(0xFF);
    MCP3201_CS=1;
    
    msb=msb&0b00011111;
    lsb=lsb&0b11111110; 
    value=(msb<<8)|lsb;
    value=value>>1;
       
    return value;
}

//********************************************************
float MCP3201_GetDifferentialADC(void){
    unsigned int value_int=0;
    float mv=0;

    value_int=_MCP3201_Communication(); 
    mv=value_int; mv=mv*_MCP3201_GAIN; 
    
    return mv;
}

#pragma used-
#endif

