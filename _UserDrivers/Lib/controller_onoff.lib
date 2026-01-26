// GitHub Account:  GitHub.com/AliRezaJoodi

#include <controller_onoff.h>

//******************************************
char Controller_OnOff_Heater(float sp,float pv, float hystersis){
    float error=0;
    static char heater=0;
    
    error=sp-pv;
    if(error>(hystersis/2)){heater=HEATER_ACTIVE;}   
        else if(error<-(hystersis/2)){heater=!HEATER_ACTIVE;};
     
    return heater;        
}

//******************************************
char Controller_OnOff2_Heater(float sp,float pv, float hystersis){
    float error=0;
    static char heater=0;
    
    error=sp-pv;
    if(error>(hystersis/2)){heater=HEATER_ACTIVE;}   
        else if(error<0){heater=!HEATER_ACTIVE;};
     
    return heater;        
}

//******************************************
char Controller_OnOff_Cooler(float sp,float pv, float hystersis){
    float error=0;
    static char cooler=0;
    
    error=sp-pv;
    if(error<-(hystersis/2)){cooler=COOLER_ACTIVE;}
        else if(error>(hystersis/2)){cooler=!COOLER_ACTIVE;};   
    
    return cooler;        
}

//******************************************
char Controller_OnOff2_Cooler(float sp,float pv, float hystersis){
    float error=0;
    static char cooler=0;
    
    error=sp-pv;
    if(error<-(hystersis/2)){cooler=COOLER_ACTIVE;}
        else if(error>0){cooler=!COOLER_ACTIVE;};   
    
    return cooler;        
}

