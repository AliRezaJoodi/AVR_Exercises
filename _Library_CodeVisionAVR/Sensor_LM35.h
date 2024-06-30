// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _LM35_INCLUDED
    #define _LM35_INCLUDED

    #ifndef _LM35_PORTS
        #define _LM35_PORTS
    
        #define LM35_CH             7 
        #define _LM35_GAIN          0.1
    #endif

    #define LM35_ConvertMilliVoltToTemp(VALUE)       (VALUE*_LM35_GAIN)
    #define LM35_ConvertVoltToTemp(VALUE)            (VALUE*1000*_LM35_GAIN)

#endif
