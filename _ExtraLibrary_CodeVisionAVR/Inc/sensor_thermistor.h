// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _THERMISTOR_INCLUDED
#define _THERMISTOR_INCLUDED
    
#ifndef _THERMISTOR_HARDWARE
#define _THERMISTOR_HARDWARE 
    #define VCC     	    5
    #define R2      	    1500
    #define THERMISTOR_CH   0 
#endif  
    

//Pull-Up NTC
/*
VCC
R1=NTC
R2=1K5
GND
*/

#pragma used+

float Thermistor_ConvertVoltToOhm_PullUp(float);
float Test(float);

#pragma used-

#pragma library sensor_thermistor.lib
   
#endif
