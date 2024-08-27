// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef _MCP320X_INCLUDED
#define _MCP320X_INCLUDED
    
    //#define DISABLE_MCP320X
    #ifndef DISABLE_MCP320X
        #define _ENABLE_MCP320X
    #endif

    #define MCP320X_CS_DDR      DDRB.4
    #define MCP320X_CS_PORT     PORTB.4
    #define MCP320X_CS_PIN      PINB.4 
    #define MCP320X_CS          MCP320X_CS_PORT 
    
    #define MCP320X_VREF        5000    //MilliVolt
    #define _MCP320X_RESOLUTION  4096    //12-Bit
    #define _MCP320X_GAIN        MCP320X_VREF/_MCP320X_RESOLUTION
    
    #define SINGLE_CHANNEL      1 
    #define DIFF_CHANNEL        0  

//********************************************************
void MCP320x_Config(void){
    #ifdef _ENABLE_MCP320X
        MCP320X_CS_DDR=1; MCP320X_CS_PORT=1;
    #endif    
}

#pragma used+

//********************************************************
unsigned int _ConvertMsbLsbToInt(unsigned char msb, unsigned char lsb){
    return (msb<<8)|lsb;        
}

//********************************************************
float _ConvertIntToMillivolt(unsigned int x){
    float value=x;
    value=value*_MCP320X_GAIN;
    return value;
}

//********************************************************
unsigned int _CommunicationWithMCP3201(void){
    #ifdef _ENABLE_MCP320X
        unsigned int value=0;
        unsigned char msb=0;
        unsigned char lsb=0;
    
        MCP320X_CS=0;
        msb=spi(0xFF); 
        lsb=spi(0xFF);
        MCP320X_CS=1;
    
        msb=msb&0b00011111;
        lsb=lsb&0b11111110; 
        value=_ConvertMsbLsbToInt(msb, lsb);
        value=value>>1;   
        return value;
    #else
        return 0;
    #endif
}

//********************************************************
unsigned int _CommunicationWithMCP320x(char data1, char data2){
    #ifdef _ENABLE_MCP320X
        unsigned int value=0;
        unsigned char msb=0;
        unsigned char lsb=0;
    
        MCP320X_CS=0;
        spi(data1);
        msb=spi(data2); 
        lsb=spi(0xFF);
        MCP320X_CS=1;
    
        msb=msb&0b00001111; 
        value=_ConvertMsbLsbToInt(msb, lsb);   
        return value;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3201_GetDifferentialADC(void){
    #ifdef _ENABLE_MCP320X
        unsigned int value_int=0;
        float millivolt=0;

        value_int=_CommunicationWithMCP3201();
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3202_GetSingleADC(char ch){
    #ifdef _ENABLE_MCP320X
        char data1=0;
        char data2=0;
        unsigned int value_int=0;
        float millivolt=0; 
        char type=SINGLE_CHANNEL;
    
        if(ch>1){return 0;}
    
        data1=0b00000001; 
        data2=(type<<7) | (ch<<6);
        
        value_int=_CommunicationWithMCP320x(data1, data2);
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3202_GetDifferentialADC(char ch){
    #ifdef _ENABLE_MCP320X
        char data1=0;
        char data2=0;
        unsigned int value_int=0;
        float millivolt=0;
        char type=DIFF_CHANNEL;
        
        switch (ch){
            case 01:
                ch=0b00000000; break;
            case 10:
                ch=0b00000001; break;
            default:
                return 0;
        }
    
        data1=0b00000001; 
        data2=(type<<7) | (ch<<6);
    
        value_int=_CommunicationWithMCP320x(data1, data2);
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3204_GetSingleADC(char ch){
    #ifdef _ENABLE_MCP320X
        char data1=0;
        char data2=0;
        unsigned int value_int=0;
        float millivolt=0; 
        char type=SINGLE_CHANNEL;
    
        if(ch>3){return 0;}

        data1=0b00000100 | (type<<1);
        data2=ch<<6; 

        value_int=_CommunicationWithMCP320x(data1, data2);
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3204_GetDifferentialADC(char ch){
    #ifdef _ENABLE_MCP320X
        char data1=0;
        char data2=0;
        unsigned int value_int=0;
        float millivolt=0;
        char type=DIFF_CHANNEL;
        
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

        value_int=_CommunicationWithMCP320x(data1, data2);
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3208_GetSingleADC(char ch){
    #ifdef _ENABLE_MCP320X
        char data1=0;
        char data2=0;
        unsigned int value_int=0;
        float millivolt=0; 
        char type=SINGLE_CHANNEL;
    
        if(ch>7){return 0;}
    
        data1=0b00000100 | (type<<1) | (ch>>2); 
        data2=ch<<6; 

        value_int=_CommunicationWithMCP320x(data1, data2);
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

//********************************************************
float MCP3208_GetDifferentialADC(char ch){
    #ifdef _ENABLE_MCP320X
        char data1=0;
        char data2=0;
        unsigned int value_int=0;
        float millivolt=0;
        char type=DIFF_CHANNEL;
        
        switch (ch){
            case 01:
                ch=0b00000000; break;
            case 10:
                ch=0b00000001; break; 
            case 23:
                ch=0b00000010; break;
            case 32:
                ch=0b00000011; break;
            case 45:
                ch=0b00000100; break;
            case 54:
                ch=0b00000101; break;
            case 67:
                ch=0b00000110; break;
            case 76:
                ch=0b00000111; break;
            default:
                return 0;
        }
    
        data1=0b00000100 | (type<<1) | (ch>>2); 
        data2=ch<<6; 
        
        value_int=_CommunicationWithMCP320x(data1, data2);
        millivolt=_ConvertIntToMillivolt(value_int);
        return millivolt;
    #else
        return 0;
    #endif
}

#pragma used-
#endif

