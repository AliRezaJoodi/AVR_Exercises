// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _CONTROLLER_PID_INCLUDED
#define _CONTROLLER_PID_INCLUDED

#ifndef CONTROLLER_PID_HARDWARE
#define CONTROLLER_PID_HARDWARE
    #define KP 0.5 
    #define KI 0.000001
    #define KD 0.1
#endif

#pragma used+
float Controller_PID(float sp,float pv,char status);
#pragma used-

#pragma library controller_pid.lib

#endif
