// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef CONTROLLER_PID_INCLUDED
#define CONTROLLER_PID_INCLUDED

#ifndef CONTROLLER_PID_HARDWARE
#define CONTROLLER_PID_HARDWARE
    #define KP 0.5 
    #define KI 0.000001
    #define KD 0.1
#endif

float Controller_PID(float sp, float pv, char status);

#pragma library controller_pid.lib

#endif
