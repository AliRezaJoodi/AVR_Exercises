
#ifndef _INCLUDED_RTC
    #define _INCLUDED_RTC
    
        //#define DISABLE_RTC
    #ifndef DISABLE_RTC
        #define ENABLE_RTC
    #endif
    
#pragma used+

struct rtc{
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
};
struct rtc clock;

//***************************************
void SetClockWithDefaultValues(void){
    clock.hour=23; clock.minute=59; clock.second=55;
}

//***************************************
void ClockCounter(void){
    clock.second++;
    if(clock.second>59){
        clock.second=0;  
        clock.minute++;
        if(clock.minute>59){
            clock.minute=0; 
            clock.hour++; 
            if(clock.hour>23){clock.hour=0;}    
        }
    }   
}

//***************************************
void IncreaseMin(void){
    clock.minute++; if(clock.minute>59){clock.minute=0;}
    clock.second=0;
}

//***************************************
void IncreaseHour(void){
    clock.hour++; if(clock.hour>23){clock.hour=0;}  
    clock.second=0;
}

#pragma used-    
#endif
