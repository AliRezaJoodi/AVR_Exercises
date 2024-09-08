// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _OVEN_INCLUDED
#define _OVEN_INCLUDED

#ifndef OVEN_HARDWARE
#define OVEN_HARDWARE
    #define TEMP_CH             0
    #define TEMP_GAIN           1000 
#endif

#pragma used+

//******************************************
float Oven_ConvertVoltToTemp(float volt){
    float temp=0;
    temp = volt*TEMP_GAIN;
    return temp;
}

#pragma used-

#endif
