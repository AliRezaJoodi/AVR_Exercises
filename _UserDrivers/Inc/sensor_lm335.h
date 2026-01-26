// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _LM335_INCLUDED
#define _LM335_INCLUDED

#ifndef LM335_HARDWARE
#define LM335_HARDWARE 
    #define LM335_CH        7 
#endif

#define LM335_GAIN          0.1      // 10mV=1^C

#define LM335_ConvertMilliVoltToTemp_Kelvin(VALUE)      (VALUE*LM335_GAIN)
#define LM335_ConvertVoltToTemp_Kelvin(VALUE)           (VALUE*1000*LM335_GAIN)

#endif
