// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _CONTROLLER_ONOFF_INCLUDED
#define _CONTROLLER_ONOFF_INCLUDED

#ifndef CONTROLLER_ONOFF_HARDWARE
#define CONTROLLER_ONOFF_HARDWARE
    #define HEATER_ACTIVE         1
    #define COOLER_ACTIVE         1
#endif

#pragma used+
char Controller_OnOff_Heater(float sp,float pv, float hystersis);
char Controller_OnOff2_Heater(float sp,float pv, float hystersis);
char Controller_OnOff_Cooler(float sp,float pv, float hystersis);
char Controller_OnOff2_Cooler(float sp,float pv, float hystersis);
#pragma used-

#pragma library controller_onoff.lib

#endif
