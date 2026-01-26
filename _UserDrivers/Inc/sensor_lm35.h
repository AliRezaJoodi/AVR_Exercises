// GitHub Account:  GitHub.com/AliRezaJoodi
// Temp unit:       Celsius

#ifndef _LM35_INCLUDED
#define _LM35_INCLUDED


#define LM35_GAIN           0.1     // 10mV=1^C
#define LM35_RES            0.4     // Resolution = 0.488^C , (5000mV/1023)/10mV 

#define LM35_ConvertMilliVoltToTemp(VALUE)      (VALUE*LM35_GAIN)   // Celsius
#define LM35_ConvertVoltToTemp(VALUE)           LM35_ConvertMilliVoltToTemp(VALUE*1000) // Celsius


#endif
