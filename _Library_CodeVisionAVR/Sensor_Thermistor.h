// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _THERMISTOR_INCLUDED
#define _THERMISTOR_INCLUDED
    
#ifndef _THERMISTOR_PORTS
#define _THERMISTOR_PORTS 
    #define VCC     	    5
    #define R2      	    1500
    #define THERMISTOR_CH   0 
#endif  
    
#pragma used+

//********************************************************
//Pull-Up NTC
/*
VCC
R1=NTC
R2=1K5
GND
*/
float Thermistor_ConvertVoltToOhm_PullUp(float vr2){
    float y=0;
    
    y=R2*(VCC-vr2)/vr2; 
    return y;
}

float Test(float vr2){
    float y=0;
    
    y=R2*(VCC-vr2)/vr2; 
    return y;
}
#pragma used-
   
#endif
