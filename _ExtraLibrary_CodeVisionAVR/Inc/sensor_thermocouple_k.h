// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _TC_INCLUDED
#define _TC_INCLUDED

#ifndef TC_HARDWARE
#define TC_HARDWARE
    #define TC_CH           0
    #define TC_GAIN         1/90
#endif

#pragma used+

//******************************************
//Input:    ADC Channel Voltage(mV)
//Output:   Temp(^C)
int TC_ConvertMilliVoltToTemp(float);

//******************************************
//Input:    Temp(^C)
//Output:   TC Voltage(mV)
float TC_ConvertTempToMilliVolt(int);

#pragma used-

#pragma library sensor_thermocouple_k.lib

#endif

