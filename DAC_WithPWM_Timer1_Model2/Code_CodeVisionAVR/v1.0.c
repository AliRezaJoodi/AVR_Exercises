#include <mega32a.h>

#include <timer1_dac_16mhz10bit2ch.h>

void main(void){
    Timer1_DAC_Config();
    
    Timer1_DAC_SetVoltage_ChA(2500);
    Timer1_DAC_SetVoltage_ChB(4300); 
    
    while(1){

    }
}
