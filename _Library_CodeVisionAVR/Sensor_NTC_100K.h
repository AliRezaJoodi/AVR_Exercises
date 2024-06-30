// GitHub Account: GitHub.com/AliRezaJoodi
/*
VCC
R1=NTC, 100K
R2=1K5
GND
*/

#ifndef _NTC100K_INCLUDED
    #define _NTC100K_INCLUDED
    
    #define VCC     5
    #define R2      1500
    
#pragma used+

//********************************************************
float NTC_ConvertVoltToOhm(float vr2){
    float y=0;
    
    y=R2*(VCC-vr2)/vr2; 
    return y;
}

#pragma used-
    
#endif
