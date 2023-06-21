#ifndef _INCLUDED_WATCHDOG
    #define _INCLUDED_WATCHDOG
    
    //#define DISABLE_WATCHDOG
    #ifndef DISABLE_WATCHDOG
        #define ENABLE_WATCHDOG
    #endif    
    
//*********************************************
void ConfigWatchdog(void){
    #ifdef ENABLE_WATCHDOG
        // Watchdog Timer initialization
        // Watchdog Timer Prescaler: OSC/2048k
        WDTCR=(0<<WDTOE) | (1<<WDE) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);
    #endif
}

//*********************************************
void ResetWatchdog(void){
    #asm("wdr")
}

#pragma used+
#pragma used-                
#endif  