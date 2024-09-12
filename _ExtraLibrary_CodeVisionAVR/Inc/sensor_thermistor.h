// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _THERMISTOR_INCLUDED
#define _THERMISTOR_INCLUDED
    
#ifndef THERMISTOR_HARDWARE
#define THERMISTOR_HARDWARE 
    #define VCC     	        5
    #define RESISTOR      	    1500    //ohm
    #define THERMISTOR_CH       0 
#endif  
    

//Pull-Up NTC
/*
VCC
NTC
RESISTOR
GND
*/

#pragma used+
float Thermistor_ConvertVoltToOhm_PullUp(float volt);
#pragma used-

#pragma library sensor_thermistor.lib
   
#endif
