// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _NTC_INCLUDED
    #define _NTC_INCLUDED
    
    #ifndef NTC_PORTS
        #define NTC_PORTS 
        
        #define VCC     	5
        #define R2      	1500
        #define NTC_CH      0 
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
float NTC_ConvertVoltToOhm_PullUp(float vr2){
    float y=0;
    
    y=R2*(VCC-vr2)/vr2; 
    return y;
}

#pragma used-
   
#endif
