// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _TC_INCLUDED
#define _TC_INCLUDED

#ifndef TC_HARDWARE
#define TC_HARDWARE
    #define TC_CH           0
    #define TC_GAIN         1/90
#endif

#pragma used+
int TC_ConvertMilliVoltToTemp(float mv);
float TC_ConvertTempToMilliVolt(int temp);
#pragma used-

#pragma library sensor_thermocouple_k.lib

#endif

