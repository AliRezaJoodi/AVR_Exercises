// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <delay.h>
#include <Utility.h>

#ifndef _MCP4822_INCLUDED
    #define _MCP4822_INCLUDED

#ifndef _MCP4822_PORTS
#define _MCP4822_PORTS   
    #define MCP4822_CS_DDR      DDRB.3
    #define MCP4822_CS_PORT     PORTB.3
    #define MCP4822_CS_PIN      PINB.3
    
    #define MCP4822_LDAC_DDR    DDRB.2
    #define MCP4822_LDAC_PORT   PORTB.2
    #define MCP4822_LDAC_PIN    PINB.2            
#endif

#define MCP4822_CS          MCP4822_CS_PORT
#define MCP4822_LDAC        MCP4822_LDAC_PORT
        
/* DACA or DACB Select bit
1 = Write to DACB
0 = Write to DACA */
#define     _MCP4822_REGISTER_AB      15

/* Output Gain Select bit
1 = 1x (VOUT = VREF * D/4096)
0 = 2x (VOUT = 2 * VREF * D/4096) */
#define     _MCP4822_REGISTER_GA      13

/* Output Power-down Control bit
1 = Output Power-down Control bit
0 = Output buffer disabled, Output is high-impedance */
#define     _MCP4822_REGISTER_SHDN      12

#define MCP4822_GAIN    2000    // Gain = Resolution/VREF = 4096/2.048

//********************************************************
void MCP4822_Config(void){
    MCP4822_CS_DDR=1; 
    MCP4822_CS_PORT=1; 
    
    MCP4822_LDAC_DDR=1; 
    MCP4822_LDAC_PORT=1;
}

#pragma used+

//********************************************************
void _MCP4822_WriteCommand(unsigned int data){
    MCP4822_CS=0;
    spi((data&0xFF00)>>8);  //Send MSB 
    spi(data&0x00FF);   //Send LSB 
    MCP4822_CS=1; delay_us(1);  // Minimum Setup Time = 40ns 
    MCP4822_LDAC=0; delay_us(1); MCP4822_LDAC=1;    // Minimum Pulse Width = 100ns
}

//********************************************************
void MCP4822_SetOutput(char ch, float volt){
    unsigned int data=0;
    
    if(volt<=2.048){
        data=volt*MCP4822_GAIN;
        SetBit(data, _MCP4822_REGISTER_GA); // Gain=1x
    }
    else if(volt<=4.096){
        data=(volt/2)*MCP4822_GAIN;
        ClearBit(data, _MCP4822_REGISTER_GA);   // Gain=2x
    }
    
    if(ch<=1){
        WriteBit(data, _MCP4822_REGISTER_AB, ch);
        SetBit(data,_MCP4822_REGISTER_SHDN) 
        _MCP4822_WriteCommand(data);  
    }
}

//********************************************************
void MCP4822_ShutDown(char ch){
    unsigned int data=0;
    
    if(ch<=1){ 
        WriteBit(data, _MCP4822_REGISTER_AB, ch);
        ClearBit(data,_MCP4822_REGISTER_SHDN)
        _MCP4822_WriteCommand(data);
    }
}

#pragma used-
#endif

