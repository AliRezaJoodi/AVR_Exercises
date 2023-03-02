// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef INCLUDED_LM35
    #define INCLUDED_LM35

#ifndef PORTS_LM35
    #define PORTS_LM35
    
    #define CH_LM35         7 
    #define GAIN_LM35       0.1
#endif

#pragma used+

//******************************************
//Input:    Voltage(mV)
//Output:   Temp(^C)
float Convert_mVtoTemp_LM35(float mv){
    float temp=0;
    temp = mv*GAIN_LM35;
    return temp;
}

//******************************************
//Input:    Voltage(V)
//Output:   Temp(^C)
float Convert_VtoTemp_LM35(float volt){
    float temp=0;
    temp = Convert_mVtoTemp_LM35(volt*1000);
    return temp;
}

#pragma used-

#endif
