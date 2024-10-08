// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _LM35_INCLUDED
#define _LM35_INCLUDED

#ifndef LM35_HARDWARE
#define LM35_HARDWARE 
    #define LM35_CH        7 
#endif

#define LM35_GAIN          0.1      // 10mV=1^C

#define LM35_ConvertMilliVoltToTemp_Celsius(VALUE)      (VALUE*LM35_GAIN)
#define LM35_ConvertVoltToTemp_Celsius(VALUE)           (VALUE*1000*LM35_GAIN)

#endif
